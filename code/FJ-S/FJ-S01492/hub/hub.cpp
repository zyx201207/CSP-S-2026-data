#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define fi first
#define se second
#define debug(...) fprintf(stderr,__VA_ARGS__)
using namespace std;
const int inf=0x3f3f3f3f,N=4005;
const ll INF=0x3f3f3f3f3f3f3f3f;
int C,n,k,sz[N],d[4][N],md[4],me[4][N],ff[N],f[N],X,Y,ty[N],ans;
vector<int> v[N],ve[2];
void dfs(int x,int fa,int o){
	ty[x]=o;
	d[o][x]=d[o][fa]+1,ff[x]=fa;
	if(d[o][x]>d[o][md[o]]) md[o]=x;
	me[o][x]=d[o][x];
	for(int y:v[x]){
		if(y==fa) continue;
		if(minmax(x,y)==minmax(X,Y)) continue;
		dfs(y,x,o);
		me[o][x]=max(me[o][x],me[o][y]);
	}
}
void dfs0(int x,int fa){
	// debug("%d\n",x);
	for(int y:v[x]){
		if(y==fa) continue;
		X=x,Y=y;
		md[0]=md[1]=md[2]=md[3]=0;
		dfs(y,x,0);
		int rt=md[0];
		dfs(rt,0,1);
		int G0=md[1];
		for(int i=1;i*2<=d[1][md[1]];i++) G0=ff[G0];
		dfs(G0,0,0);

		dfs(x,y,2);
		rt=md[2];
		dfs(rt,0,3);
		int G1=md[3];
		for(int i=1;i*2<=d[3][md[3]];i++) G1=ff[G1];
		dfs(G1,0,2);

		int l=-1,r=n,mid;
		auto check=[&](int lim){
			int cnt=0;
			for(int i=1;i<=n;i++)
				cnt+=(me[ty[i]][i]-d[ty[i]][i]>=lim);
			// debug("%d %d ")
			return cnt;
		};
		while(l+1<r){
			mid=l+r+1>>1;
			if(check(mid)<=k) r=mid;
			else l=mid;
		}
		ans=min(ans,r);
		// int nt[2]={sz[y],sz[x]};
		// pair<int,int> G[2];
		// G[0]=G[1]={inf,0};
		// mx[0]=inf;
		// for(int o:{0,1}){
		// 	for(int z:ve[o])
		// 		G[o]=min(G[o],make_pair(max(mx[z],nt[o]-sz[z]),z));
		// }
		// X=x,Y=y;
		// dfs1(G[0],0),dfs1(G[1],0);
		dfs0(y,x);
	}
}
void solve(int TID){
	for(int i=1;i<=n;i++) v[i].clear();
	cin>>n>>k;
	for(int i=1,x,y;i<n;i++)
		cin>>x>>y,v[x].pb(y),v[y].pb(x);
	// if(TID<5) return;
	ans=n;
	dfs0(1,0);
	printf("%d\n",ans);
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int T; cin>>C>>T;
	for(int i=1;i<=T;i++) solve(i);
	return 0;
}