//张文涵 绥阳中学 Gz-S00431 
#include<bits/stdc++.h>

using namespace std;
int c,n,m,d,q,best=0;
const int maxn=1e6+1;
const int maxn1=505;
int w[maxn];
int a[505][maxn1],t[505][maxn1],k[505];
int x[maxn1/5],y[maxn1/5];
bool bj[505][505];
void cill(int h)
{
	if(h<best)
	{
		best=h;
	}
	return;
}
void dfs(int now,int z_x,int ans_time)
{
	int ans=w[now];
	if(now==z_x)
	{
		cill(ans_time+w[z_x]);
		return;
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=k[i];j++)
		{
			if(a[i][j]==now&&bj[i][j]!=false)
			{
				ans+=t[i][now];
				for(int c=1;c<=k[i];c++)
				{
					if(a[i][c]!=now&&bj[i][c]!=false)
					{
					  ans+=t[i][a[i][c]];
					  bj[i][c]=false;
					  dfs(a[i][c],z_x,ans);
					  ans=ans-t[i][now]-t[i][a[i][c]];
					  bj[i][c]=true;
					}
					return;
				}
			}
		}
	 } 
}
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
	memset(bj,true,sizeof(bj));
    for(int i=1;i<=m;i++){
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
	 	scanf("%d%d",&x[i],&y[i]);
	 	dfs(x[i],y[i],0);
	 	printf("%d\n",best);
	 	best=0;
	 	memset(bj,true,sizeof(bj));
	 }
	return 0;
}
