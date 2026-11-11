#include <bits/stdc++.h>
#define start_code signed main(){
#define stop_code return 0;}
#define elif else if
#define Tests int T;for(cin>>T;T --;)
#define infile(x) freopen(#x".in","r",stdin)
#define outfile(x) freopen(#x".out","w",stdout)
#define ansfile(x) freopen(#x".ans","w",stdout)
#define openfile(x) (infile(x),outfile(x))
#define fastio() (ios::sync_with_stdio(0),cin.tie(0),cout.tie(0))
#define mem(a,v) memset(a,v,sizeof(a))
#define int long long
using namespace std;
template <typename T> T& mineq(T &x,T y) {return x = min(x,y);}
const int N = 500,M = 5e5+5,INF = 0x3f3f3f3f3f3f3f3f;
struct edge {int to,ne,w;} e[M<<1]/*,e2[N*N]*/;
int CID,n,m,d,q,w[M],head[N+M],len/*,head2[N],len2*/,g[N][N];
inline void insert(int u,int v,int w) {e[++len] = {v,head[u],w},head[u] = len;}
inline void add(int u,int v,int w) {insert(u,v,w),insert(v,u,w);}
//inline void insert2(int u,int v,int w) {e2[++len2] = {v,head2[u],w},head2[u] = len2;}
//inline void add2(int u,int v,int w) {insert2(u,v,w),insert2(v,u,w);}
start_code
openfile(subway);
fastio();
cin>>CID>>n>>m>>d>>q,mem(g,0x3f);
for (int i = 1;i <= m;i ++) cin>>w[i];
for (int i = 1,k,a,t;i <= n;i ++)
{
	cin>>k;
	for (int j = 1;j <= k;j ++) cin>>a>>t,add(i+m,a,t);
}
for (int i = 1;i <= n;i ++) g[i][i] = 0;
for (int i = 1;i <= m;i ++)
	for (int j = head[i],u;j;j = e[j].ne)
		for (int k = head[i],v;k;k = e[k].ne)
			if ((u = e[j].to) != (v = e[k].to))
				mineq(g[u-m][v-m],e[j].w+e[k].w);
//for (int i = 1;i < n;i ++)
//	for (int j = i+1;j <= n;j ++)
//		if (g[i][j] != INF)
//			add2(i,j,g[i][j]);
for (int k = 1;k <= n;k ++)
	for (int i = 1;i <= n;i ++)
		for (int j = 1;j <= n;j ++)
			if (g[i][k]+g[k][j] < g[i][j])
				g[i][j] = g[i][k]+g[k][j];
for (int x,y,ans;q --;)
{
	cin>>x>>y,ans = INF;
	for (int i = head[x];i;i = e[i].ne)
		for (int j = head[y];j;j = e[j].ne)
			mineq(ans,e[i].w+e[j].w+g[e[i].to-m][e[j].to-m]);
	cout<<ans+w[x]+w[y]<<'\n'; 
}
stop_code
