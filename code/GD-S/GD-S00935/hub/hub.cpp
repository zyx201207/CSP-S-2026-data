#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,k,ans=1e18;
vector<int>vt[1000005];
vector<int>x;
int b[1000005];
bool cnt(){
	vector<bool>vis(n+1);
	for(int i=1;i<=n;i++)b[i]=0;
	for(int x1:x)b[x1]=1;
	int cnt1=0;
	for(int i=1;i<=n;i++){
		if(vis[i]==0&&b[i]==1){
			cnt1++;
			queue<int>q;q.push(i);vis[i]=1;
			while(q.size()){
				int u=q.front();q.pop();
				for(int v:vt[u]){
					if(vis[v]==0&&b[i]==1){
						vis[v]=1;
						q.push(v);
					}
				}
			}
		}
	}
	return cnt1<=2;
}
int bfs(){
	vector<int>dis(n+1);
	queue<int>q;
	for(int x1:x){
		dis[x1]=1,q.push(x1);
	}
	while(q.size()){
		int u=q.front();q.pop();
		for(int v:vt[u]){
			if(dis[v]==0){
				dis[v]=dis[u]+1;
				q.push(v);
			}
		}
	}
	int re=0;
	for(int i=1;i<=n;i++){
		cout<<dis[i]-1<<" ";
		re=max(re,dis[i]-1);
	}
	cout<<" ";
	return re;
}
void dfs(int t){
	if(t>n){
		if(x.size()==k&&cnt()){
			for(int x1:x)cout<<x1<<" ";
			int s=bfs();
			cout<<s<<"\n";
			ans=min(ans,s);
		}
		return;
	}
	x.push_back(t);
	dfs(t+1);
	x.pop_back();
	dfs(t+1);
}
void solve(){
	cin>>n>>k;int u,v;
	memset(vt,0,sizeof(vt));
	for(int i=1;i<n;i++){
		cin>>u>>v;
		vt[u].push_back(v);
		vt[v].push_back(u);
	}
	ans=1e18;
	dfs(1);
	cout<<ans<<'\n';
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int c,t;cin>>c>>t;
	while(t--){
		solve();
	}
	return 0;
}
