#include <bits/stdc++.h>
using namespace std;
int f[5010][5010],flag[5010];
int w[500010];
void add(int x,int y,int num)
{
	f[x][y]=num;
	f[y][x]=num;
}
int ret=INT_MAX;
int c,n,m,d,q;
void dfs(int x,int y,int dep)
{
	flag[x]=1;
	if(x==y)
	{
		ret=min(dep,ret);
		return;
	}
	for(int i=1;i<=m;i++)
	{
		if(f[x][i]!=0&&!flag[i])
		{
			dfs(i,y,dep+f[x][i]);
		}
	}
}
int x[500010],y[500010];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)
	{
		cin>>w[i];
	}
	int tot=m,k,x2,y2;
	for(int i=0;i<n;i++)
	{
		cin>>k;
		for(int i=1;i<=k;i++)cin>>x[i]>>y[i];
		for(int i=1;i<=k;i++)
		{
			for(int j=i+1;j<=k;j++)
			{
				add(x[i],x[j],y[i]+y[j]);
			}
		}
	}
	int a,b;
	while(q--)
	{
		memset(flag,0,sizeof(flag));
		ret=INT_MAX;
		cin>>a>>b;
		dfs(a,b,0);
		if(ret==INT_MAX)ret=0;
		cout<<ret+w[a]+w[b]<<'\n';
	}
	return 0;
}
