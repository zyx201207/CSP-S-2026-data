#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long a,b,ans=0,m=0,n=0;
	string s,x="";
	cin >> a;
	for (int i = 1;i <= a;i++)
	{
		cin >> b >> s;
		for (int j = 1;j <= b;j++)
		{
			x += s;
		}
		m += b;
	}
	n = 1+m-2;
	for (int i = 0;i <= m/2-1;i++)
	{
		if (x[i] != x[n-i])
		{
			ans++;
		}
	}
	cout << ans;
	
}
