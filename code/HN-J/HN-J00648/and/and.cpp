#include <bits/stdc++.h>
using namespace std;
int n, m;
int a[200005];
int f[200005];
int maxn;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	if(m==1) cout<<a[n];
	if(m==n)
	{
		int b=a[1];
		for(int i=2;i<=n;i++)
		{
			b=b&a[i];
		}
		cout<<b;
		return 0;
	}
	if(m==n);
	{
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				maxn=max(maxn,a[i]&a[j]);
			}
		}
	}
	cout<<maxn;
	return 0; 
 }
