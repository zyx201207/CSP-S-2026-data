#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],b[500005],cnt[500005];
void dfs(int s,int g)
{
	if(s>n)
	{
		for(int i=1;i<=g;i++)
		{
			b[cnt[i]]++;
			cnt[i]=0;
		}
		return;
	}
	int d=0;
	for(int i=1;i<=g;i++)
	{
		if(a[s]==cnt[i])
		{
			for(int j=1;j<=g;j++)
			{
				cnt[j]=0;
			}
			d=1;
			g=1;
			cnt[g]=a[s];
			break;
		}
	}
	if(d==0)
	{
		g++;
		cnt[g]=a[s];
		dfs(s+1,g);
	}
	else
	{
		dfs(s+1,g);
	}
}
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=n;i++)
	{
		dfs(i,0);
	}
	for(int i=1;i<=m;i++)
	{
		cout<<b[i]<<" ";
	}
}
