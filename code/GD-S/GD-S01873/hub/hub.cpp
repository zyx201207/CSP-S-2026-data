#include<bits/stdc++.h>
using namespace std;
bool f[1000005];
bool t[1000005];
int c,q;
int n,k;
int u,v;
int ans;
int d[4005][4005];
vector<int>D[1000005];
void solve(){
	int mx=0;
	for(int i=1;i<=n;i++){
		int mn=1e9+7;
		for(int j=1;j<=n;j++){
			if(f[j]) mn=min(mn,d[i][j]);
		}
		mx=max(mx,mn);
	}
	ans=min(ans,mx);
}
void dfs(int num,int cnt){
	if(cnt>k) return;
	if(num==n+1){
		if(cnt==k) solve();
		return;
	}
	dfs(num+1,cnt);
	f[num]=true;
	dfs(num+1,cnt+1);
	f[num]=false;
}
void df(int x,int y,int val){
	if(t[y]) return;
	t[y]=true;
	d[x][y]=val;
	for(int it:D[y]){
		df(x,it,val+1);
	}
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>q;
	while(q--){
		ans=1e9+7;
		cin>>n>>k;
		for(int i=1;i<=n;i++) D[i].clear();
		for(int i=1;i<n;i++){
			cin>>u>>v;
			D[u].push_back(v);
			D[v].push_back(u);
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++) t[j]=false;
			df(i,i,0);
		}
		dfs(1,0);
		cout<<ans<<'\n';
	}
	return 0;
}
