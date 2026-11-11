#include <iostream>
#include <string>

int main()
{
	std::freopen("travel.in", "r", stdin);
	std::freopen("travel.out", "w", stdout);
	
	std::string c1, s1, c2, s2;
	std::cin >> c1 >> s1 >> c2 >> s2;
	int res = 0;
	if (c1 == c2) 
	{
		res = 1000;
		if (s1.substr(0, 2) == s2.substr(0, 2)) 
		{
			res = 1100;
			if (('A' <= s1.back() && s1.back() <= 'C' &&
				'A' <= s2.back() && s2.back() <= 'C') ||
				('D' <= s1.back() && s1.back() <= 'F' &&
				'D' <= s2.back() && s2.back() <= 'F'))
			{
				res = 1110;
				if (std::abs(s1.back() - s2.back()) == 1)
					res = 1111;
			}
		}
	}
	std::cout << res;
}
