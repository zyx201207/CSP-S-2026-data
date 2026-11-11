#include <iostream>
#include <string>
using namespace std;

int main()
{
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	
	unsigned int n;
	string s;
	unsigned int a;
	char c;
	cin >> n;
	for (unsigned int i = 0; i < n; i++)
	{
		cin >> a >> c;
		for (unsigned int j = 0; j < a; j++)
		{
			s.push_back(c);
		}
	}
	unsigned int l = 0, r = s.size() - 1;
	unsigned int cnt = 0;
	while (l < r)
	{
		if (s[r] != s[l])
		{
			cnt++;
		}
		l++;
		r--;
	}
	cout << cnt << '\n';
	
	return 0;
}
