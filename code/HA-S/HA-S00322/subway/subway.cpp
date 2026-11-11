#include<bits/stdc++.h>
#define int long long
#define pir pair<int,int>
using namespace std;
typedef long long ll;
const int N=5e5+5;

inline ll read()
{
	ll x=0,f=1;char c=getchar();
	while(c<'0'||c>'9'){if(c=='-'){f=-1;}c=getchar();}
	while(c>='0'&&c<='9'){x=x*10+c-'0';c=getchar();}
	return x*f;
}

int c,n,m,d,q,w[N];
vector<pir> e[N];// 存储每个节点拥有的线路和站台换乘的时间 
int dis[505][505];// dis 存储每个线路与线路之间换乘时间 

signed main() {
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	c=read(),n=read(),m=read(),d=read(),q=read();
	
	for(int i=1;i<=m;i++) w[i]=read();
	memset(dis,0x3f,sizeof(dis));
	for(int i=1;i<=n;i++) dis[i][i]=0;
	for(int i=1;i<=n;i++) {// 每一条线路 
		int k=read();
		for(int j=1;j<=k;j++) {
			int x=read(),val=read();
			for(auto l:e[x]) {
				int yy=l.first,ww=l.second;
				dis[i][yy]=dis[yy][i]=min(dis[i][yy],val+ww);
			}
			e[x].push_back({i,val});
		}
	}
	
	for(int k=1;k<=n;k++) {
		for(int i=1;i<=n;i++) {
			for(int j=1;j<=n;j++) {
				dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
			}
		}
	}
	
	for(int we=1;we<=q;we++) {
		int x=read(),y=read(),ans=LLONG_MAX;
		int sum=w[x]+w[y];
		for(auto j:e[x]) {
			int id1=j.first,ww1=j.second;
			for(auto l:e[y]) {
				int id2=l.first,ww2=l.second;
				ans=min(ans,sum+ww1+ww2+dis[id1][id2]);
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}
// Oct31==Dec25?
