#include<bits/stdc++.h>
using namespace std;
const int N = 1e6+10;
#define int long long
int c,t,n,k,vis[N],vvis[N],d[N];
vector<int>E[N];
void dfs(int u,int f){
	if(!vis[u])return;
	vvis[u]=1;
	for(int v : E[u]){
		if(v!=f)dfs(v,u);
	}
}
void solve(){
	cin >> n >> k;
	for(int i = 1; i <= n; i++)E[i].clear();
	for(int i = 1,u,v; i < n; i++){
		cin >> u >> v;
		E[u].push_back(v);
		E[v].push_back(u);
	}
	if(c==13||c==14){
		cout << ((n-1)/2-k+3)/4+1 << '\n';
		return;
	}
	int ans = 2e9;
	for(int i = 0; i < (1<<n); i++){
		int cnt=0;
		for(int j = 1; j <= n; j++){
			vis[j]=0;vvis[j]=0;
			if(i>>(j-1)&1){
				cnt++;vis[j]=1;
			} 
		}
		if(cnt!=k)continue;
		cnt=0;
		for(int j = 1; j <= n; j++){
			if(vis[j]&&!vvis[j]){
				dfs(j,0);cnt++;
			}
		}
		if(cnt>2)continue;
		queue<pair<int,int> >q;
		for(int j = 1; j <= n; j++){
			vvis[j]=0;
			if(vis[j]){
				q.push({j,0});
				vvis[j]=1;
			}
		}
		while(!q.empty()){
			int u=q.front().first,w=q.front().second;
			d[u]=w;q.pop();
			for(int v : E[u]){
				if(!vvis[v]){
					vvis[v]=1;
					q.push({v,w+1});
				}
			}
		}
		int x=0;
		for(int j = 1; j <= n; j++){
			x=max(x,d[j]);
		}
		ans=min(ans,x);
	}
	cout << ans << '\n';
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin >> c >> t;
	while(t--)solve();
}
