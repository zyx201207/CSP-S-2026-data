#include<bits/stdc++.h>
using namespace std;
int n,m,a[300000],b[300000],c[300000],maxn=INT_MIN;
void dfs(int x)
{
	if(x>m)
	{
		int lm=c[1]&c[2];
		for(int i=3;i<=m;i++)
			lm=lm&c[i];
		if(lm>maxn)
			maxn=lm;
	}
	for(int i=1;i<=n;i++)
	{
		if(b[i]==0)
		{
			b[i]=1;
			c[x]=a[i];
			dfs(x+1);
			b[i]=0;
		}
	}
	
}
int main()
{	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	dfs(0);
	cout<<maxn;
	return 0;
}
