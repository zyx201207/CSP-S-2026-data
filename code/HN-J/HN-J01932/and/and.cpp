#include <iostream>
#include <stdio.h>
#include <stdint.h>
#include <algorithm>
#include <map>
#include <vector>
#define READ_FILE

inline int log2(int64_t num)
{
	int64_t tmp = 1;
	for(int i=0;i<=63;i++)
	{
		if(tmp >= num)
		{
			return i;
		}
		tmp = tmp << 1;
	}
	return 64;
}

int64_t closest2expn(int64_t num)
{
	if(num - (int64_t)pow(2,log2(num)) == 0)
	{
		return INT64_MAX;
	}
	return std::min(abs(num - (int64_t)pow(2,log2(num))), abs((int64_t)pow(2,log2(num) - 1) - num));
}

int main()
{
	#undef READ_FILE
#ifdef READ_FILE
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
#endif
	
	int number_count,pick_count;
	std::cin >> number_count >> pick_count;
	
	int64_t numbers[number_count];
	for(auto& v : numbers)
	{
		std::cin >> v;
	}
	
	std::sort(numbers,numbers + number_count,[&](int64_t a,int64_t b){
		return a > b && closest2expn(a) <= closest2expn(b);
	});
	

	int64_t dp[2 * (int)1e5 + 1] = {};
	dp[1] = numbers[0];
	
	for(int i=0;i<number_count;i++)
	{
		for(int j=pick_count;j > 0;j--)
		{
			//std::cout << j << ' ' << dp[j-1] << ' ' << dp[j] << ' ' << numbers[i] << std::endl;
			dp[j] = std::max(dp[j - 1],dp[j] & numbers[i]);
		}
	}
	
	std::cout << dp[pick_count];


/*
	for(auto v : numbers)
	{
		std::cout << v << ' ';
	}
	std:: cout << std::endl;
	
	int r = numbers[0];
	for(int i=0;i<pick_count;i++)
	{
		r &= numbers[i];
	}
	std::cout << r;
*/
	return 0;
}
