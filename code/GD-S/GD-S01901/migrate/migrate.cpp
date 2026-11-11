#include <bits/stdc++.h>
#define int long long
#define rep(i,l,r) for (int i=(l);i<=(r);i++)
#define per(i,l,r) for (int i=(r);i>=(l);i--)

using namespace std;

const int N=310,inf=0x3f3f3f3f3f3f3f3f;

int n,d,x[N];
int dis[N][N],cnt[N][N];
vector<int> e[N];

void bfs(int s,int dis[],int cnt[]){
	fill(dis+1,dis+n+1,inf);
	fill(cnt+1,cnt+n+1,0);
	queue<int> q;
	q.emplace(s),dis[s]=0,cnt[s]=1;
	while(q.size()){
		int u=q.front();
		q.pop();
		for(auto v:e[u]){
			if(dis[v]==dis[u]+1) cnt[v]+=cnt[u];
			else if (dis[v]>dis[u]+1)
				dis[v]=dis[u]+1,cnt[v]=1,q.emplace(v);
		}
	}
}

void solve() {
	cin>>n>>d;
	rep(i,1,n) cin>>x[i];
	rep(i,1,n){
		rep(j,i+1,n){
			if(x[j]-x[i]<=d) e[i].emplace_back(j);//e[j].emplace_back(i);
		}
	}
	rep(i,1,n){
		bfs(i,dis[i],cnt[i]);
	}
	int ans=0;
	rep(i,1,n){
		rep(j,i+1,n){
			if(cnt[i][j]==2) ans++;
		}
	}
	cout<<ans<<"\n";
	rep(i,1,n) e[i].clear();
}

signed main() {
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	
	int c,t;
	cin>>c>>t;
	while(t--) solve();
	
	return 0;
}
