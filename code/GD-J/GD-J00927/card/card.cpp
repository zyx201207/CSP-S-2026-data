#include<bits/stdc++.h>
using namespace std;
int cnt[300010];
int a[500010];
int c[500010];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		c[i] = 0;
	}
	for(int i=n;i>=1;i--)
	{
		if(c[a[i]] == 0)
		{
			c[a[i]] = i;
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=i;j<=n;j++)
		{
			cnt[a[j]]++;
			j = c[a[j]];
		}
	}
	for(int i=1;i<=m;i++)
	{
		cout<<cnt[i]<<' ';
	}
	return 0;
}
