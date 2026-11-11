#include<bits/stdc++.h>
using namespace std;
using ll = long long;
void solve(){
	ll n,m;
	cin>>n>>m;
	vector<ll>v(n+1);
	vector<ll>ans(m+1);
	for(ll i = 1; i <= n; i ++)cin>>v[i];
	for(ll i = 1; i <= n; i ++){
		vector<ll>a;
		vector<bool>vis(m+1);
		for(ll j = i; j <= n; j ++){
			if(vis[v[j]]){
				while(a.back()!=v[j]){
					vis[a.back()]=0;
					a.pop_back();
				}
			}
			else{
				vis[v[j]]=1;
				a.push_back(v[j]);
			}
		}
		for(ll j = 1; j <= m; j ++){
			if(vis[j])ans[j]++;
		}
	}
	for(ll i = 1; i <= m; i ++)cout<<ans[i]<<' ';
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ll t=1;
//	cin>>t;
	while(t--){
		solve();
	}
	return 0;
} 
