#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int MAX=2*10e5+5;
const ll s=pow(2,31)-1;
map<ll,ll>mp;
ll dp[MAX],c[MAX],n,m;


int main(){
	freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin>>n>>m;

	if(m==n){
		ll a;
		ll ans=s;
		for(int i=0; i<m; i++){
			cin>>a;
			ans=(ans&a);
		}cout<<ans;
	}else if(m==1){
		ll a;
		ll ans=-1;
		for(int i=0; i<m; i++){
			cin>>a;
			ans=max(a,ans);
		}cout<<ans;
	}else if(m==n-1){
		ll ans=-1,a=s;
		for(int i=1; i<=n; i++){
			cin>>c[i];
			a=(c[i]&a);
		}
		for(int i=1; i<=n; i++){
			ans=max(ans,(a|c[i]));
		}
		
	}else{
		for(int i=1; i<=n; i++){
			cin>>c[i];
		}
		ll ans=-1;
		for(int i=1; i<=n; i++){
			for(int j=1; j<=n; j++){
				if(i==j)continue;
				ans=max(ans,(c[i]&c[j]));
			}
		}cout<<ans;
	}

	return 0;
}//479681762610
