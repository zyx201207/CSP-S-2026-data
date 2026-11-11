#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("string.in", "r", stdin);
	freopen("string.out", "W", stdout);
	string s;
	int n;
	cin >> n;
	long long a;
	char c;
	for(int i = 0; i < n; i++)
	{
		cin >> a >> c;
		for(long long i = 0; i < a; i++)
		{
			s += c;
		}
	}
	long long cnt = 0;
	for(long long i = 0; i < s.size() / 2; i++)
	{
		long long x = s.size() - i - 1;
		if(s[i] != s[x])
		{
			cnt++;
		}
	}
	cout << cnt;
	return 0;
}
