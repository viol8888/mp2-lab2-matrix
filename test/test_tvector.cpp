#include "utmatrix.h"

#include <gtest.h>

TEST(TVector, can_create_vector_with_positive_length)
{
  ASSERT_NO_THROW(TVector<int> v(5));
}

TEST(TVector, cant_create_too_large_vector)
{
  ASSERT_ANY_THROW(TVector<int> v(MAX_VECTOR_SIZE + 1));
}

TEST(TVector, throws_when_create_vector_with_negative_length)
{
  ASSERT_ANY_THROW(TVector<int> v(-5));
}

TEST(TVector, throws_when_create_vector_with_negative_startindex)
{
  ASSERT_ANY_THROW(TVector<int> v(5, -2));
}

TEST(TVector, can_create_copied_vector)
{
  TVector<int> v(10);

  ASSERT_NO_THROW(TVector<int> v1(v));
}

TEST(TVector, copied_vector_is_equal_to_source_one)
{
	TVector<int> v(2);
	v[0] = 2;
	TVector<int> w(v);
	EXPECT_EQ(v, w);
}

TEST(TVector, copied_vector_has_its_own_memory)
{
	TVector<int> v(2);
	v[0] = 5;
	TVector<int> w(v);
	w[0] = 1;
	EXPECT_NE(v, w);
}

TEST(TVector, can_get_size)
{
  TVector<int> v(4);

  EXPECT_EQ(4, v.GetSize());
}

TEST(TVector, can_get_start_index)
{
  TVector<int> v(4, 2);

  EXPECT_EQ(2, v.GetStartIndex());
}

TEST(TVector, can_set_and_get_element)
{
  TVector<int> v(4);
  v[0] = 4;

  EXPECT_EQ(4, v[0]);
}

TEST(TVector, throws_when_set_element_with_negative_index)
{
	TVector<int> v(5);
	EXPECT_ANY_THROW(v[-1]);
}

TEST(TVector, throws_when_set_element_with_too_large_index)
{
	TVector<int> v(5);
	EXPECT_ANY_THROW(v[6]);
}

TEST(TVector, can_assign_vector_to_itself)
{
	TVector<int> v(5);
	EXPECT_NO_THROW(v = v);
}

TEST(TVector, can_assign_vectors_of_equal_size)
{
	TVector<int> v(5);
	TVector<int> w(5);
	EXPECT_EQ(w, v);
}

TEST(TVector, assign_operator_change_vector_size)
{
	TVector<int> v(5);
	TVector<int> w(10);
	v = 10;
	EXPECT_EQ(v.GetSize(), w.GetSize());
}

TEST(TVector, can_assign_vectors_of_different_size)
{
	TVector<int> v(5);
	TVector<int> w(10);
	ASSERT_NO_THROW(v = w);
}

TEST(TVector, compare_equal_vectors_return_true)
{
	TVector<int> v(5);
	TVector<int> w(5);
	EXPECT_TRUE(v == w);
}

TEST(TVector, compare_vector_with_itself_return_true)
{
	TVector<int> v(5);
	EXPECT_TRUE(v == v);
}

TEST(TVector, vectors_with_different_size_are_not_equal)
{
	TVector<int> v(5);
	TVector<int> w(10);
	EXPECT_FALSE(w == v);
}

TEST(TVector, can_add_scalar_to_vector)
{
	TVector<int> v(2);
	TVector<int> w(2);
	v[0] = 1; w[0] = 2; w[1] = 1;
	v = v + 1;
	EXPECT_EQ(w, v);
}

TEST(TVector, can_subtract_scalar_from_vector)
{
	TVector<int> v(2);
	TVector<int> w(2);
	v[0] = 3; v[1] = 1; w[0] = 2; w[1] = 0;
	v = v - 1;
	EXPECT_EQ(w, v);
}

TEST(TVector, can_multiply_scalar_by_vector)
{
	TVector<int> v(3);
	TVector<int> w(3);
	v[0] = 1; w[0] = 2;
	v = v * 2;
	EXPECT_EQ(w, v);
}

TEST(TVector, can_add_vectors_with_equal_size)
{
	TVector<int> v(3);
	TVector<int> w(3);
	TVector<int> k(3);
	v[0] = 1; w[0] = 1; k[0] = 2;
	v = v + w;
	EXPECT_EQ(v, k);
}

TEST(TVector, cant_add_vectors_with_not_equal_size)
{
	TVector<int> v(2);
	TVector<int> w(3);
	ASSERT_ANY_THROW(v + w);
}

TEST(TVector, can_subtract_vectors_with_equal_size)
{
	TVector<int> v(3);
	TVector<int> w(3);
	TVector<int> k(3);
	v[0] = 3; w[0] = 1; k[0] = 2;
	v = v - w;
	EXPECT_EQ(v, k);
}

TEST(TVector, cant_subtract_vectors_with_not_equal_size)
{
	TVector<int> v(2);
	TVector<int> w(3);
	ASSERT_ANY_THROW(w - v);
}

TEST(TVector, can_multiply_vectors_with_equal_size)
{
	TVector<int> v(2);
	TVector<int> w(2);
	v[0] = 2;	v[1] = 2;	w[0] = 1;	w[1] = 3;
	int a = v * w;
	EXPECT_EQ(a, 8);
}

TEST(TVector, cant_multiply_vectors_with_not_equal_size)
{
	TVector<int> v(3);
	TVector<int> w(2);
	v[0] = 2;	v[1] = 2; v[2] = 3;	w[0] = 1;	w[1] = 3;
	ASSERT_ANY_THROW(v * w);
}

