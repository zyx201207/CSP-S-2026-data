#include <bits/stdc++.h>
using namespace std;
string s;
long long n;
long long a;
char c;
long long cnt = 0;
int main()
{
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin >> n;
	for(long long i = 0; i < n; i++)
	{
		cin >> a;
		cin >> c;
		for(long long j = 0; j < a; j++)
		{
			s += c;
		}
	}
	long long si = s.size();
	long long si1 = si;
	for(long long i = 0; i < si/2+1; i++)
	{
		if(s[i] != s[si1-1])
		{
			s[si1] = s[i];
			cnt ++;
		}
		else
		{
			continue;
		}
		si1--;
	}
	
	cout << cnt;
	return 0;
}
