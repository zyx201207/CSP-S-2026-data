#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

struct res{
	ll dis;
	ll num;
};

const ll N=1000;
vector<ll>arr(N,0);
ll c,t,n,d;

res dfs(ll u,ll v){
	if(u==v){
		return {0,1};
	}else{
		res re={1000,1};
		for(ll i=u+1;i<=v;i++){
			if(d>=arr[i]-arr[u]){
				res now=dfs(i,v);
				if(now.dis<re.dis){
					re=now;
				}else if(now.dis==re.dis){
					re.num+=now.num;
				}
			}else{
				break;
			}
		}
		return {re.dis+1,re.num};
	}
}



int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		ll ans=0;
		cin>>n>>d;
		for(ll i=0;i<n;i++){
			cin>>arr[i];
		}
		for(ll i=0;i<n;i++){
			for(ll j=i+1;j<n;j++){
				if(dfs(i,j).num==2){
					ans++;
				}
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}
