#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<ll> mp[10005];
vector<ll> tree[10005];
void cl(){
	for(int i = 1;i<=1005;i++){
		mp[i].clear();
		tree[i].clear();
	}
}
int main(){
	//freopen("migrate.in","r",stdin);
	//freopen("migrate.out","w",stdout);
	ll c,t;
	cin>>c>>t;
	while(t--){
		ll n,d;
		cin>>n>>d;
		ll a[1005];
		for(int i = 1;i<=n;i++){
			cin>>a[i];
		}
		for(int i = 1;i<=n;i++){
			ll k = upper_bound(a+1,a+n+1,a[i]+d)-a;
			k-=1; 
			for(int j = i+1;j<=k;j++){
				mp[a[i]].push_back(a[j]);
			}
			cout<<endl;
		}
		dfs(1);
	}
	return 0;
} 
