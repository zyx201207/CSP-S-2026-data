#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pir;
const int MAXN=1e6+5,mod=998244353,inf=0x3f3f3f3f;
int testid,T,n,k;
struct EDGE{
	int to,next;
}e[MAXN<<1];
int ecnt=0,head[MAXN];
#define toi (e[i].to)
#define fore(now,i) for(int i=head[now];i;i=e[i].next)
inline void addedge(int u,int v){
	e[++ecnt]={v,head[u]};
	head[u]=ecnt;
}
bool g[MAXN];
int f[MAXN];
inline int findf(int x){
	return f[x]==x?x:f[x]=findf(f[x]);
}
inline void merge(int x,int y){
	x=findf(x),y=findf(y);
	if(x==y)
		return ;
	f[x]=y;
}
int p[MAXN][21],dp[MAXN],d[MAXN];
void dfs(int now,int fa){
	p[now][0]=fa;
	dp[now]=dp[fa]+1;
	for(int i=1;(1<<i)<dp[now];i++)
		p[now][i]=p[p[now][i-1]][i-1];
	fore(now,i){
		if(toi==fa)
			continue;
		if(g[now]&&g[toi])
			merge(now,toi);
		d[toi]=d[now]+1;
		dfs(toi,now);
	}
}
inline int LCA(int x,int y){
	if(dp[x]<dp[y])
		swap(x,y);
	for(int i=0,t=dp[x]-dp[y];t;t>>=1,i++)
		if(t&1)
			x=p[x][i];
	if(x==y)
		return x;
	for(int i=20;i>=0;i--)
		if(p[x][i]^p[y][i])
			x=p[x][i],y=p[y][i];
	return p[x][0];
}
inline int dis(int x,int y){
	return d[x]+d[y]-(d[LCA(x,y)]<<1);
}
void solve(){
	ecnt=0;
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		head[i]=0;
		for(int j=0;j<=20;j++)
			p[i][j]=0;
		d[i]=0;
	}
	for(int i=1,u,v;i<n;i++){
		cin>>u>>v;
		addedge(u,v);
		addedge(v,u);
	}
	int ans=inf;
	for(int c=3;c<(1<<n);c++){
		if(__builtin_popcount(c)!=k)
			continue;
		vector<int> v;
		for(int i=1;i<=n;i++)
			g[i]=0;
		for(int i=0;i<n;i++)
			if((c>>i)&1){
				g[i+1]=1;
				v.emplace_back(i+1);
			}
		for(int i=1;i<=n;i++)
			f[i]=i;
		dfs(1,1);
		int cnt=0;
		for(int i=1;i<=n;i++)
			cnt+=((g[i])&&(findf(i)==i));
		if(cnt>2)
			continue;
		int nowans=0;
		for(int i=1;i<=n;i++){
			if(g[i])
				continue;
			int di=inf;
			for(int j:v){
				di=min(di,dis(i,j));
			}
			nowans=max(nowans,di);
		}
		ans=min(ans,nowans);
	}
	cout<<ans<<"\n";
}
signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin.tie(nullptr)->sync_with_stdio(false);
	cin>>testid>>T;
	while(T--)
		solve();
	return 0;
}
/*
0 2
5 2
1 2
2 3
3 4
4 5
10 3
1 2
1 3
2 4
2 5
3 6
3 7
3 8
7 9
9 10
*/
