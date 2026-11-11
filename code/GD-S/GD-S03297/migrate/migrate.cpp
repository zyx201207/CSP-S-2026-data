#include<bits/stdc++.h>
#define int long long
using namespace std;
int c,t;
int n,d;
vector<int> xx;
int ans=LLONG_MAX,bans,bbans;
map<int,bool> vis;
void dfs(int x,int tm,int y){
	if(x==y){
		if(ans==tm)
			bans++;
		if(tm<ans){
			ans=tm;
			bans=1;
		}
	}
	if(tm>ans)
		return;
	for(int i=1;i<=n;i++){
		if(vis[i]||abs(xx[x]-xx[i])>d)
			continue;
		vis[i]=1;
		dfs(i,tm+1,y);
		vis[i]=0;
	}
}
void solve(){
	cin>>n>>d;
	xx.resize(n+1);
	for(int i=1;i<=n;i++)
		cin>>xx[i];
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			vis[i]=1;
			ans=LLONG_MAX;
			bans=0;
			dfs(i,0,j);
			vis[i]=0;
			bbans+=(bans==2);
		}
	}
	cout<<bbans<<'\n';
	bbans=0;
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>c>>t;
	while(t--)
		solve();
	return 0;
}
