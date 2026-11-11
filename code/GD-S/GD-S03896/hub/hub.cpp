#include<bits/stdc++.h>
using namespace std;
const int INF=1e9;
struct sta{
	int cnt,comp,sel,dy,de;
	bool operator<(const sta& o)const{
		if(comp!=o.comp)return comp<o.comp;
		if(sel!=o.sel)return sel<o.sel;
		if(dy!=o.dy)return dy<o.dy;
		if(de!=o.de)return de<o.de;
		return cnt<o.cnt;
	}
	bool operator==(const sta& o)const{
		return comp==o.comp&&sel==o.sel&&dy==o.dy&&de==o.de;
	}
	
};
int n,k;
vector<int>adj[100005];
vector<sta>dp[100005];
int R;
void dfs(int u,int p){
	dp[u].clear();
	dp[u].push_back({1,1,1,0,R+1});
	dp[u].push_back({0,0,0,R+1,0});
	for(int v:adj[u]){
		if(v==p)continue;
		dfs(v,u);
		vector<sta>ndp;
		for(const auto&su:dp[u]){
			for(const auto&sv:dp[v]){
				int c=su.comp+sv.comp-(su.sel&sv.sel);
				if(c>2)continue;
				int cnt=su.cnt+sv.cnt;
				if(cnt>k)continue;
				int ndy=min(su.dy,(sv.dy==R+1)?R+1:sv.dy+1);
				int nde=max(su.de,(sv.de==R+1)?R+1:sv.de+1);
				if(nde>R&&nde!=R+1)continue;
				if(ndy!=R+1&&nde!=R+1&&ndy+nde<=R){
					nde=R+1;
				}
				ndp.push_back({cnt,c,su.sel,ndy,nde});
			}
		}
		sort(ndp.begin(),ndp.end());
		dp[u].clear();
		for(const auto&s:ndp){
			if(dp[u].empty()||!(dp[u].back()==s)){
				dp[u].push_back(s);
			}
		}
	}
}
bool check(int mid){
	R=mid;
	dfs(1,0);
	for(const auto&s:dp[1]){
		if(s.comp<=2&&s.de==R+1&&s.cnt<=k){
			return true;
		}
	}
	return false;
}
void solve(){
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		adj[i].clear();
	}
	for(int i=1;i<n;i++){
		int u,v;
		cin>>u>>v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	k=min(k,n);
	int low=0,hi=n,ans=n;
	while(low<=hi){
		int mid=(low+hi)/2;
		if(check(mid)){
			ans=mid;
			hi=mid-1;
		}else{
			low=mid+1;
		}
	}
	cout<<ans<<endl;
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int c,t;
	if(cin>>c>>t){
		while(t--){
			solve();
		}
	}
	
	return 0;
} 
