#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e5+5;
ll n,m;
ll x[N],mn=INT_MAX,tmp=INT_MAX,cnt,ans;
void dfs(ll cur,ll ed){
	if(cur>=x[ed]){
		if(tmp<mn){
			cnt=1;
			mn=tmp;
		}
		cnt++;
		return;
	}
	for(ll i=1;i<=m;i++){
		tmp++;
		dfs(cur+i,ed);
	}
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ll c,q;
	cin>>c>>q;
	while(q--){
		cin>>n>>m;
		for(ll i=1;i<=n;i++) cin>>x[N];
		for(ll i=1;i<=n;i++){
			for(ll j=1;j<=n;j++){
				dfs(x[1],x[n]);
				if(cnt==2) ans++;
				cnt=0,mn=INT_MAX,tmp=INT_MAX;
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}
