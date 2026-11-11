#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e6+10;

int n,d,ans;
int a[N];
vector<int>g[N];
int dis[N],vis[N];
queue<int>q;

void bfs(int s){
	for(int i=1;i<=n;i++) dis[i]=1e18,vis[i]=0;
	dis[s]=0;
	q.push(s);
	int cnt=0;
	while(q.size()){
		cnt++;
		int u=q.front();
		q.pop();
		vis[u]++;
		for(int j=0;j<g[u].size();j++){
			if(dis[g[u][j]]>=dis[u]+1){
				dis[g[u][j]]=dis[u]+1;
				q.push(g[u][j]);
			}
		}
	}
	for(int i=1;i<=n;i++) if(vis[i]==2) ans++;
//	cout<<cnt<<"~\n";
}

void solve(){
	cin>>n>>d;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		g[i].clear();
		for(int j=i+1;j<=n;j++)
			if(a[j]-a[i]<=d)
			g[i].push_back(j);
	}
	ans=0;
	for(int i=1;i<n;i++)bfs(i);
	cout<<ans<<"\n";
}

signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios_base::sync_with_stdio(0),cin.tie(0);
	int TTT=1,CCC;
	cin>>CCC>>TTT;
	while(TTT--){
		solve();
	}
}