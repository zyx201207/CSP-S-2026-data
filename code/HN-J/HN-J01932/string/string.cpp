#include <iostream>
#include <stdint.h>
#include <limits.h>
#include <vector>
#include <math.h>
#include <stdio.h>
using i64 = int64_t;

#define DELETE_ME


struct Input
{
	i64 count;
	char ch;
	
	bool operator==(Input another)
	{
		return ch == another.ch && count == another.count;	
	}	
};

int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	
	
	int n;
	std::cin >> n;
	
	i64 string_length = 0;
	
	std::vector<Input> sequence;
	
	for(int i=0;i<n;i++)
	{
		Input input;
		
		std::cin >> input.count >> input.ch;
		
		string_length += input.count;
		if(!sequence.empty() && sequence[sequence.size() - 1].ch == input.ch)
			sequence[sequence.size() - 1].count += input.count;
		else
			sequence.push_back(input);
	}
	
	i64 half = string_length / 2;
	
	std::vector<Input> recorded;
	
	i64 answer = 0;
	i64 char_parsed = 0;
	i64 remain_last;
	bool pattern_found = false;
	
	size_t i = 0;
	for(i = 0;i < sequence.size();i++)
	{
#ifndef DELETE_ME
		size_t last = recorded.size() - 1;
		if(!recorded.empty())
		{
			if(recorded[last].ch == sequence[i].ch)
			{
				recorded[last].count += sequence[i].count;
				continue;
			}
		}
#endif

		i64 add = recorded.empty() ? 0 : sequence[i].count;
		for(auto& input : recorded)
		{
			if(input.ch == sequence[i].ch)
			{
				add = abs(add - input.count);
			}
		}
		
		answer += add;
		recorded.push_back(sequence[i]);

		char_parsed += sequence[i].count;
	}
	
	
	
	if(answer > half)
		answer = half;
	
	std::cout << answer;
	return 0;
}
