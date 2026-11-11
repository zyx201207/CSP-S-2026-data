#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<ll> v[1000005];
ll n,k;
bool dfs(ll u,ll d){
	//判断能否在塞k个基地的前提下满足通勤距离小于d 
}
bool check(ll x){
	for(int i=1;i<=n;i++){
		if(bfs(i,x)){
			return 1;
		}
	}
	return 0;
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	ll c,t;
	cin>>c>>t;
	while(t--){
		cin>>n>>k;
		for(int i=1;i<n;i++){
			ll u,w;
			cin>>u>>w;
			v[u].push_back(w);
			v[w].push_back(u);
		}
		ll l=0,r=n;
		while(l<=r){
			ll mid=(l+r)/2;
			if(check(mid)){
				r=mid-1;
				ans=mid;
			}
			else{
				l=mid+1;
			}
		}
	}
	return 0;
}
