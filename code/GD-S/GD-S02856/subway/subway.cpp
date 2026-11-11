#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)
#define LL long long
using namespace std;
const int N=5e5+10,M=505;
const LL INF=1e18+10;
inline LL read()
{
	int x=0,f=1; char c=getchar();
	for(;!isdigit(c);c=getchar()) if(c=='-') f=-1;
	for(;isdigit(c);c=getchar()) x=(x<<3)+(x<<1)+c-48;
	return x*f;
}
int c,n,m,d,q;
int w[N];
vector<LL> way[N],tim[N];
LL dis[M][M];
map<int,int> mp[N];
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	c=read(),n=read(),m=read(),d=read(),q=read();
	rep(i,1,m) w[i]=read();
	rep(i,1,n)
	{
		int k=read();
		rep(j,0,k-1)
		{
			int x=read();
			way[x].push_back(i);//u站经过的第tot线路 
			mp[x][i]=tim[x].size();
			LL t=read();
			tim[x].push_back(t);
//			printf("tim[%d][%d]=%d\n",x,mp[x][i],tim[x][j]);
		}
	}
	memset(dis,0x3f,sizeof dis);
	rep(x,1,m)
	{
		rep(i,0,way[x].size()-1)
		{
			rep(j,i+1,way[x].size()-1)
			{
				int u=way[x][i],v=way[x][j];
				dis[u][v]=dis[v][u]=min(dis[u][v],tim[x][mp[x][u]]+tim[x][mp[x][v]]);//第u条线换乘第v条线的最小时间 
//				printf("dis(%d,%d)=%d\n",u,v,dis[u][v]);
			}
		}
	}
	rep(mid,1,n)
	{
		rep(u,1,n)
		{
			dis[u][u]=0;
			rep(v,u+1,n)
			{
				if(dis[u][mid]+dis[mid][v]<dis[u][v])
					dis[u][v]=dis[v][u]=dis[u][mid]+dis[mid][v];
			}
		}
	}
	while(q--)
	{
		int x=read(),y=read();
		LL ans=INF;
		rep(i,0,way[x].size()-1)
		{
			rep(j,0,way[y].size()-1)
			{
				int u=way[x][i],v=way[y][j];
				ans=min(ans,tim[x][mp[x][u]]+dis[u][v]+tim[y][mp[y][v]]);
			}
		}
		printf("%lld\n",ans+w[x]+w[y]);
	}
	return 0;
}

