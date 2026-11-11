#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,a[500010];
long long g[510][510];
vector<pair<int,int> > vc[500010];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
	for(int i=1;i<=m;i++)
		scanf("%d",&a[i]);
	for(int i=1;i<=n;i++)
	{
		int k;
		scanf("%d",&k);
		while(k--)
		{
			int x,v;
			scanf("%d%d",&x,&v);
			vc[x].push_back({i,v});
		}
	}
	memset(g,0x3f,sizeof(g));
	for(int i=1;i<=n;i++)
		g[i][i]=0;
	for(int ti=1;ti<=m;ti++)
	{
		int len=vc[ti].size();
		for(int i=0;i<=len-1;i++)
		{
			int x=vc[ti][i].first,vx=vc[ti][i].second;
			for(int j=i+1;j<=len-1;j++)
			{
				int y=vc[ti][j].first,vy=vc[ti][j].second;
				g[x][y]=g[y][x]=min(g[x][y],(long long)vx+vy);
			}
		}
	}
	for(int k=1;k<=n;k++)
	{
		for(int i=1;i<=n;i++)
		{
			if(i==k)continue;
			for(int j=1;j<=n;j++)
			{
				if(i==j||j==k)continue;
				g[i][j]=min(g[i][j],g[i][k]+g[k][j]);
			}
		}
	}
	while(q--)
	{
		int tx,ty;
		scanf("%d%d",&tx,&ty);
		long long s=0x3f3f3f3f3f3f3f3f;
		for(pair<int,int> px:vc[tx])
		{
			int x=px.first,vx=px.second;
			for(pair<int,int> py:vc[ty])
			{
				int y=py.first,vy=py.second;
				s=min(s,vx+vy+g[x][y]);
			}
		}
		s+=a[tx]+a[ty];
		printf("%lld\n",s);
	}
	return 0;
}
