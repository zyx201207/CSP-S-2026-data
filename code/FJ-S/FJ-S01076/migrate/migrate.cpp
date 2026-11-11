#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e6+10,M=5000+10;
int a[N];
int n,d;
int c,t;
struct edge{
	int to,w;
	bool operator<(const edge & rhs)const{
		return w>rhs.w;
	}
};
vector<edge> g[M];
int dis[M][M];
int tim[M][M];
bitset<M> vis;
void dij(int s){
	dis[s][s]=0;
	tim[s][s]=1;
	vis&=0;
	priority_queue<edge> pq;
	pq.push({s,0});
	while(!pq.empty()){
		int now=pq.top().to;
		pq.pop();
		if(vis[now])continue;
		vis[now]=1;
		for(edge i:g[now]){
			int nd=dis[s][now]+i.w;
			if(dis[s][i.to]==nd)tim[s][i.to]+=tim[s][now];
			if(dis[s][i.to]>nd){
				dis[s][i.to]=nd;
				tim[s][i.to]=tim[s][now];
				pq.push({i.to,dis[s][i.to]});
			}
		}
	}
}
void solve(){
	scanf("%lld%lld",&n,&d);
	int res=0;
	for(int i=1;i<=n;i++)scanf("%lld",a+i);
	if(11<=c&&c<=12){
		if(n>3&&d/(a[2]-a[1])>=2){
			int len=d/(a[2]-a[1]);
			res=n+1-len*2;
			res=max(res,0LL);
			printf("%lld\n",res);
		}
		else puts("0");
	}
	else if(13<=c&&c<=14){
		int p=0,f=0,fstp=0;
		for(int i=1;i<=n;i++){
			if(a[i]-a[1]<=d&&a[n]-a[i]<=d){
				if(p)f=1;
				else fstp=i;
				p=i;
			}
		}
		if(p-fstp+1>=3||p==n||fstp==1){
			puts("0");
			return;
		}
		if(p!=fstp){
			int it=0;
			for(it=p+1;a[it]-a[fstp-1]<=d;it++);
			int itt=0;
			for(itt=fstp-1;a[p+1]-a[itt]<=d;itt--);
			res=(n-it+1)*itt;
		}
		else{
			int it=0;
			for(it=p+1;a[it]-a[fstp-1]<=d;it++);
			int itt=0;
			for(itt=fstp-1;a[p+1]-a[itt]<=d;itt--);
			res=(n-p)*(fstp-1)-(n-it+1)*itt;
		}
	}
	else{
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)dis[i][j]=3e18,tim[i][j]=0,g[j].clear();
		for(int i=1;i<=n;i++){
			int it=lower_bound(a+1,a+i,a[i]-d)-a;
			for(int j=it;j<i;j++)g[j].push_back({i,1}),g[i].push_back({j,1});
		}
		for(int i=1;i<=n;i++)dij(i);
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(tim[i][j]==2)res++;
			}
		}
		res>>=1;
	}
	printf("%lld\n",res);
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%lld%lld",&c,&t);
	while(t--)solve();
} 
/*
0 1
6 6
1 2 3 7 9 11
((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((
*/
