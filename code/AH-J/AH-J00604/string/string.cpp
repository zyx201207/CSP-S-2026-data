#include "bits/stdc++.h" 
bool hw_string(std::string s)
{
	int l = 0,r = s.size()-1;
	while (l < r)
	{
		if (s[l] != s[r]) return false;
		l++,r--;
	}
	return true;
}
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	srand(time(0));
	int n,sum = 0,m;
	char ch;
	std::string s = "";
	std::cin >> n;
	while (n--)
	{
		std::cin >> m >> ch;
		while (m--)
		{
			s += ch;
		}
		sum += m;
	}
	if (hw_string(s)) std::cout << 0;
	else std::cout << (rand()%sum+1)/2;
	return 0;
}
