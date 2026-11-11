#include<bits/stdc++.h>
using namespace std;
long long c,n,m,d,q,w[500005],k[505],aa[500005],tt[500005],x,y,kk,zx,f[1005][1005];
queue<long long> a[500005];
bool fa[500005];
void dfs(long long x,long long t)
{
	if(x==y)
	{
		zx=min(zx,t);
		return ;
	}
	for(int i=0;i<a[x].size();i++)
	{
		if(fa[a[x][i]]==0)
		{
			fa[a[x][i]]=1;
			dfs(a[x][i],t+f[x][i]);
			fa[a[x][i]]=0;
		}
	}
	return ;
}
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++)
	{
		cin>>k[i];
		for(int j=1;j<=k[i];j++)
		{
			cin>>aa[j]>>tt[j];
			for(int k=1;k<j;k++)
			{
				a[j].push(k);
				a[k].push(j);
				f[aa[k]][aa[j]]=tt[j];
				f[aa[j]][aa[k]]=tt[k];
			}
		}
	}
	while(q--)
	{
		cin>>x>>y;
		kk=w[x]+w[y],zx=INT_MAX;
		dfs(x,0);
		kk+=zx;
		cout<<kk<<"\n";
	}
	return 0;
}
