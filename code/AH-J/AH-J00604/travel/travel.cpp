#include "bits/stdc++.h" 
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	std::string s,h,c,d;
	std::cin >> s >> h >> c >> d;
	if (s == c) std::cout << '1';
	else
	{
		std::cout << "0000";
		return 0;
	} 
	if (h[0] == d[0] && h[1] == d[1]) std::cout << '1';
	else 
	{
		std::cout << "000";
		return 0;
	}
	if (((h[2] >= 'A' && h[2] <= 'C') && (d[2] >= 'A' && d[2] <= 'C')) || ((h[2] >= 'D' && h[2] <= 'E') && (d[2] >= 'D' && d[2] <= 'F'))) std::cout << '1';
	else 
	{
		std::cout << "00";
		return 0;
	}
	if (std::abs(h[2] - d[2]) == 1) std::cout << '1';
	else std::cout << '0';
	return 0;
}
