#include<bits/stdc++.h>
using namespace std;
const int N=1e6+9;
int c,t;
int n,k;
vector<int> x[N];
int ans=1e9;
int bh[N],vis[N];
void run(int now,int fa){
	if(bh[now]==0)return;
	vis[now]=1;
	for(int i=0;i<x[now].size();i++){
		int to=x[now][i];
		if(to!=fa)run(to,now);
	}
}
int Mo=1e9;
void fun(int now,int fa,int len){
	if(bh[now]==1){
		Mo=min(Mo,len);
		return;
	}
	for(int i=0;i<x[now].size();i++){
		int to=x[now][i];
		if(to==fa)continue;
		fun(to,now,len+1);
	}
}
void dfs(int now,int K){
	if(n-now+1<K-k)return;
	if(now>n){
		for(int i=1;i<=n;i++)vis[i]=0;
		int S=0;
		for(int i=1;i<=n;i++){
			if(vis[i]==0&&bh[i]==1){
				S++;
				if(S>2)return;
				run(i,0);
			}
		}
		int s=0;
		for(int i=1;i<=n;i++){
			if(bh[i]==0){
				Mo=1e9;
				fun(i,0,0);
				s=max(Mo,s);
			}
		}
		ans=min(ans,s);
		return;
	}
	if(K<k)bh[now]=1;
	dfs(now+1,K+1);
	bh[now]=0;
	dfs(now+1,K);
}
void solve(){
	cin>>n>>k;
	for(int i=1;i<=n;i++)x[i].clear();
	for(int i=1;i<n;i++){
		int u,v;
		cin>>u>>v;
		x[u].push_back(v);
		x[v].push_back(u);
	}
	dfs(1,0);
	cout<<ans<<endl;
	ans=1e9;
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>c>>t;
	while(t--)solve();
	return 0;
} 
