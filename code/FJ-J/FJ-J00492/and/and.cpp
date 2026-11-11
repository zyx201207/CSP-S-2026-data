#include <bits/stdc++.h>
using namespace std;
int n,m,a[200005],dp[200005];
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >> n >> m;
	for(int i=1;i<=n;i++)
	{
		cin >> a[i];
	}
	sort(a+1,a+n+1);
	if(m==1)
	{
		cout << a[n];
	}
	else if(m==n)
	{
		int x=a[1];
		for(int i=2;i<=n;i++)
		{
			x&=a[i];
		}
		cout << x;
	}
	else if(m==2)
	{
		
		int maxx=0;
		for(int i=1;i<=n;i++)
		{
			for(int j=i+1;j<=n;j++)
			{
				int x;
				x = a[i]&a[j];
				maxx = max(maxx,x);
			}
		}
		cout << maxx;
	}
	else
	{
		int x = a[n];
		for(int i=n-1;i>=n-m+1;i--)
		{
			x&=a[i];
		}
		cout << x;
	}
 } 
