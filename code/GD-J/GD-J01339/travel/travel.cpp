#include <iostream>
#include <string>
#include <cmath>
#include <fstream>

auto main() -> int
{	
	std::ifstream in("travel.in");
	std::ofstream out("travel.out", std::ios::trunc);
	
	auto c1 = std::string(), s1 = std::string(), c2 = std::string(), s2 = std::string();
	in >> c1 >> s1 >> c2 >> s2;
	
	if (c1 == c2)
	{
		out << 1;
		
		if (s1[0] == s2[0] && s1[1] == s2[1])
		{
			out << 1;
			
			if ((s1.back() >= 'A' && s1.back() <= 'C' && s2.back() >= 'A' && s2.back() <= 'C') || (s1.back() >= 'D' && s1.back() <= 'F' && s2.back() >= 'D' && s2.back() <= 'F'))
			{
				out << 1;
				
				if (std::abs(s1.back() - s2.back()) == 1)
				{
					out << 1;
				}
				else
				{
					out << "0";
				}
			}
			else
			{
				out << "00";
			}
		}
		else
		{
			out << "000";
		}
	}
	else
	{
		out << "0000";
	}
	
	return 0;
}
