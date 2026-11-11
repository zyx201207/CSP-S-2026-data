#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=105;
int n,k,cnt,tmp,ans;
bool flg[maxn];
int col[maxn],dis[maxn];
vector<int> g[maxn];
queue<int> q;
void func(int x){
	for(auto i:g[x]){
		if(col[i]||!flg[i]){
			continue;
		}
		col[i]=tmp;
		func(i);
	}
}
bool check(){
	if(cnt!=k){
		return 0;
	}
	for(int i=1;i<=n;i++){
		col[i]=0;
	}
	tmp=0;
	for(int i=1;i<=n;i++){
		if(!flg[i]){
			continue;
		}
		if(col[i]){
			continue;
		}
		tmp++;
		func(i);
	}
	if(tmp>2){
		return 0;
	}
	return 1;
}
int calc(){
	int res=0;
	for(int i=1;i<=n;i++){
		dis[i]=1e9;
		if(flg[i]){
			q.push(i);
			dis[i]=0;
		}
	}
	while(!q.empty()){
		int x=q.front();
		q.pop();
		res=max(res,dis[x]);
		for(auto i:g[x]){
			if(dis[i]>dis[x]+1){
				dis[i]=dis[x]+1;
				q.push(i);
			}
		}
	}
	return res;
}
void dfs(int x){
	if(x>n){
		if(check()){
			ans=min(ans,calc());
		}
		return;
	}
	flg[x]=0;
	dfs(x+1);
	if(cnt<k){
		flg[x]=1,cnt++;
		dfs(x+1);
		cnt--;
	}
}
void solve(){
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		g[i].clear();
	}
	for(int i=1;i<n;i++){
		int u,v;
		cin>>u>>v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	cnt=0,ans=1e9;
	dfs(1);
	cout<<ans<<"\n";
}
signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int c,t;
	cin>>c>>t;
	while(t--){
		solve();
	}
	return 0;
}
