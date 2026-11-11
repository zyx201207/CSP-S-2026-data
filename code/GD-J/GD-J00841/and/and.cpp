#include<bits/stdc++.h>
using namespace std;
using ll = long long;
ll ans=0;
vector<bool>vis;
vector<ll>a;
ll n,m;
void dfs(ll cnt, ll num){
//	cout<<cnt<<' '<<num<<endl;
	if(cnt<0){
		ans=num;
		return;
	}
	vector<ll>v;
	ll k=0;
	for(ll i = 1; i <= n; i ++){
		if(vis[i]){
			if((a[i]>>cnt)&1){
				k++;
			}
			else{
				v.push_back(i);
				vis[i]=0;
			}
		}
	}
	if(k>=m)dfs(cnt-1,num|(1<<cnt));
	else{
		for(auto l:v){
			vis[l]=1;
		}
		dfs(cnt-1,num);
	}
}
void solve(){
	cin>>n>>m;
	vis.resize(n+1,1);
	a.resize(n+1);
	for(ll i = 1; i <= n; i ++)cin>>a[i];
	dfs(32,0);
	cout<<ans;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ll t=1;
//	cin>>t;
	while(t--){
		solve();
	}
	return 0;
} 
