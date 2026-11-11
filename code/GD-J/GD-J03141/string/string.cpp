#include <bits/stdc++.h>
using namespace std;

int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	
	int n;
	long long cnt = 0;
	string s = "";
	cin >> n;
	for (int i = 1;i <= n;i++)
	{
		long long x;
		char a;
		cin >> x >> a;
		for (long long j = 1;j <= x;j++)
		{
			s += a;
		}	
	}
	if (s.size() == 1)
		cout << 0;
	if (s.size() == 2)
	{
		if (s[0] == s[1])
			cout << 0;
		else
			cout << 1;
	}
	long long mid = s.size()/2;
	long long j = 0;
	for (long long i = s.size()-1;i >= mid;i--)
	{
		if (s[i] != s[j])
			cnt++;
		j++;
	}
	cout << cnt;
	return 0;
	
	
}
