#include<bits/stdc++.h>
#define For(a,b,c) for(int a=b;a<=c;a++)
#define Fro(a,b,c) for(int a=b;a>=c;a--)
#define ms(a) memset(a,0,sizeof a)
#define int long long
#define pb push_back
#define Fopen(in) freopen(in".in","r",stdin),freopen(in".out","w",stdout);
using namespace std;
constexpr int N=5e5+5;

int n,d,x[N],dis[N],vis[N],cnt[N];
vector<int> g[N];
void bfs(int u){
	ms(vis);
	memset(dis,0x3f,sizeof dis);
	vis[u]=1;
	cnt[u]=1;
	dis[u]=0;
	queue<int> q;
	q.push(u);
	while(q.size()){
		int u=q.front();q.pop();
		for(auto v:g[u]){
			if(dis[u]+1==dis[v])
				cnt[v]+=cnt[u];
			if(dis[u]+1<dis[v])
				dis[v]=dis[u]+1,
				cnt[v]=cnt[u],
				q.push(v);
		}
	}
}
void solve(){
	cin>>n>>d;
	For(i,1,n)
		cin>>x[i],g[i].clear();
	For(i,1,n)
		For(j,i+1,n)
			if(x[j]-x[i]<=d)
				g[i].pb(j);
	int ans=0;
	For(i,1,n){
		bfs(i);
		For(j,i+1,n){
			if(cnt[j]==2)
				ans++;
		}
	}
	cout<<ans<<'\n';
}
signed main(){
	Fopen("migrate")
	ios::sync_with_stdio(false);
	cin.tie(0);
	int c,t=1;
	cin>>c>>t;
	while(t--)
		solve();
	return 0;  
}