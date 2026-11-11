#include <bits/stdc++.h>

long long n;
long long  slen;
long long mcount = 0;
using namespace std;
string s;
int main()
{
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin.tie(0);
	cin >> n;
	for (long long int i = 0;i < n;i++)
	{
		unsigned long long tlen;
		string tdata;
		cin >> tlen >> tdata;
		for (unsigned long long j = 0;j < tlen;j++)
		{
			s += tdata;
		}
	}
	for (size_t i = 0;i < s.size()/2;i++)
	{
		if (s[i] != s[s.size()-i-1])
		{
			mcount ++;
		}	
	}
	cout << mcount;
}
