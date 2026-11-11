#include <iostream>
#include <stdio.h>
#include <math.h>

inline int ctoi(char ch)
{
	return ch - 48;
}
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	
	std::string car_1,seat_1,car_2,seat_2;
	
	std::cin >> car_1 >> seat_1 >> car_2 >> seat_2;
	
	bool in_same_car = car_1 == car_2;
	int row_number_1 = 10 * ctoi(seat_1[0]) + ctoi(seat_1[1]) ,row_number_2 = 10 * ctoi(seat_2[0]) + ctoi(seat_2[1]);
	bool in_same_row = row_number_1 == row_number_2 && in_same_car;
	
	constexpr char left_side[] = {'A','B','C'}, right_side[] = {'D','F'};
	constexpr int left = 0,right = 1;
	int side_1 = right, side_2 = right;
	for(auto& ch : left_side)
	{
		if(ch == seat_1[2])
		{
			side_1 = left;
		}
		if(ch == seat_2[2])
		{
			side_2 = left;
		}
	}
	
	bool in_same_side = (side_1 == side_2) && in_same_row && in_same_car; 
	bool is_next_to = false;
	if(in_same_side && in_same_row)
	{
		char& ch1 = seat_1[2],ch2 = seat_2[2];
		if(side_1 == left)
			is_next_to = (abs(ch1 - ch2) == 1);
		else
			is_next_to = (abs(ch1 - ch2) == 2);
	}
	
	std::cout << in_same_car << in_same_row << in_same_side << is_next_to;
	return 0; 
}
