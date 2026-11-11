#include <bits/stdc++.h>
using namespace std;

const int N=500+10,M=5e5+10,Q=1e5;
int c,n,m,d,q;
int k[N],w[M];
int a[M][21],t[M][21],b[M];

int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
	
	for(int i=1;i<=m;i++) scanf("%d",&w[i]);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&k[i]);
		for(int j=1;j<=(2*k[i]);j++) 
		{
			scanf("%d",&a[j][i]);
			scanf("%d",&t[a[j][i]][i]);
			b[a[j][i]]=i;
		}
	}
	int x,y;
	for(int r=1;r<=q;r++) 
	{
		
	scanf("%d%d",x,y);
	int ans=0,dx=b[x],dy=b[y];
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=(2*k[i]);j++)
		{
			
		}
	}
	
	for(int i=1;i<=n;i++)
	{
		printf("%d\n",w[x]+w[y]+t[x][dx]+t[y][dy]+ans);
	}}
	return 0;
}
