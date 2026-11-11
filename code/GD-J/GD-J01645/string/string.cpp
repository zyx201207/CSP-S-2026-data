#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	
	long long n;
	cin >> n;
	long long a;
	string c, s;
	while (n--)
	{
		cin >> a >> c;
		for (int i = 1;i <= a;i++)
			s += c;
	}
	
	long long cnt = 0;
	long long l = 0, r = s.size()-1;
	while (l < r)
	{
		if (s[l] != s[r])
			cnt++;
		l++;
		r--;
	}
	cout << cnt; 
	return 0;
}
