#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a[110000];
ll k[110][110];
void dfs(ll c,ll bs,ll n,ll jl){
	k[c][bs]++;
	if(c==n) return ;
	for(ll i=c+1;i<=n;i++){
		if(a[i]-a[c]<=jl) dfs(i,bs+1,n,jl);
	}
	return ;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ll C,t;
	cin>>C>>t;
	while(t--){
		memset(k,0,sizeof k);
		ll n,jl;
		cin>>n>>jl;
		for(ll i=1;i<=n;i++){
			cin>>a[i];
		}
		dfs(a[1],0,n,jl);
		ll cnt=0;
		for(ll i=1;i<=100;i++){
			for(ll j=1;j<=100;j++){
				if(k[i][j]==2){
					cnt++;
					break;
				}
			}
		}
		cout<<cnt<<endl;
	}
	return 0;
}

