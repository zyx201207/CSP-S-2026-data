#include<bits/stdc++.h>
using namespace std;
int n;
int a[1000005];
char c[1000005];
string s;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> n;
	for(int i = 1;i <= n;i++)
	{
		cin >> a[i] >> c[i];
	}
	for(int i = 1;i <= n;i++)
	{
		for(int j = 1;j <= a[i];j++)
		{
			s += c[i];
		}
	}
	int sz = s.size(),ans = 0;
	for(int i = 0;i < sz;i++)
	{
		if(s[i] != s[sz-1-i]) 
		{
			ans++;
		}
	}
	cout << ans/2;
	return 0;
}
