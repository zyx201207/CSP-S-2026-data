#include <bits/stdc++.h>
using namespace std;
string s;
long long sum;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin >> n;
	while(n--)
	{
		long long m;
		char r;
		cin >> m >> r;
		for (long long i = 1;i <= m;i++)
		{
			s += r;
		}
	}
	for (long long i = 0;i < s.size()/2;i++)//22135
	{
		if (s[i] != s[s.size()-i-1])
		{
			sum++;
		}
	}
	cout << sum;
	return 0;
}
