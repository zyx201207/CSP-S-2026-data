#include<bits/stdc++.h>
#define int long long
#define No ios::sync_with_stdio(0);
#define TLE cin.tie(0);
#define endl '\n'
#define INF 0x3f3f3f3f3f3f3f3f
using namespace std;
const int N=2e5+10;
void _freopen(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
}
int C;
int s[N];
bool vis[N];
vector<int>g[N];
void solve(){
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++) g[i].clear();
	for(int i=1;i<n;i++){
		int u,v;
		cin>>u>>v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	int ans=INF;
	memset(s,0,sizeof s);
	memset(vis,0,sizeof vis);
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			queue<int>q;
			q.push(i);
			q.push(j);
			int sum=0;
			while(!q.empty()){
				int u=q.front();
				for(int v:g[u]){
					if(vis[v]) continue;
					vis[v]=1;
					s[v]=s[u]+1;
					sum=max(sum,s[v]);
					q.push(v);
				} 
			} 
			ans=min(ans,sum);
		}
	}
	cout<<ans<<endl;
}
signed main(){
	No TLE
	_freopen();
	int T=1;
	cin>>C>>T;
	while(T--){
		solve();
	}
}

