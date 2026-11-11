#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,ans;
int w[10005],x,y;
int a[1005][1005],t[1005][1005],k[1005];
bool went[10005];
const int ma=9999999;
int dfs(int z)
{
	int cost=0;
	if(z==0)
	{
	for(int i=1;i<=n&&z==0;i++)
	{
		for(int j=1;j<=k[i]&&z==0;j++)
		{
			if(a[i][j]==x){
				z=i;
				if(cost==ma)cost=0;
				cost+=t[z][j];
			}
		}
	}
	}
	for(int j=1;j<=k[z];j++)
	{
		if(a[z][j]==y){
			if(cost==ma)cost=0;
			cost+=t[z][j];
			return cost;
		}
	}
	for(int l=1;l<=k[z];l++)
	{
	for(int i=1;i<=n&&went[i]==0;i++)
	{
		for(int j=1;j<=k[i];j++)
		{
			
			if(a[i][j]==a[z][l]){
				
				went[z]=1;
				cost=dfs(i)+t[z][l]+t[i][l];
				went[z]=0;
			}
		}
	}
	}
	return cost;
}
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
	for(int i=1;i<=m;i++)
	{
		scanf("%d",&w[i]);
	}
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&k[i]);
		for(int j=1;j<=k[i];j++)
		{
			scanf("%d%d",&a[i][j],&t[i][j]);
		}
	}
	for(int i=1;i<=q;i++)
	{
		scanf("%d%d",&x,&y);
		ans=w[x]+w[y];
		ans+=dfs(0);
		printf("%d\n",ans);
	}
}
