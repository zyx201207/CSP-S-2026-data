#include <bits/stdc++.h>
using namespace std;

string s, b;
int n;
long long cnt;
int main()
{
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin >> n;
	for(int i=0; i<n; i++)
	{
		long long a;
		char c;
		cin >> a;
		cin >> c;
		for(long long j=0; j<a; j++)
		{
			s+=c;
		}
	}
	long long len = s.size();
	long long h = len/2-1;
	for(long long i=0; i<len/2; i++)
	{
		b += s[len/2-1-i];
	}
	for(long long i=0; i<len/2; i++)
	{
		if(s[i+len/2+1] != b[i])
		{
			cnt++;
		}
	}
	cout << cnt;
	return 0;
 } 
