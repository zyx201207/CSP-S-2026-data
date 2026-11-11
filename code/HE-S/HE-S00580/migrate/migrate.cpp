#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll c,t,n,d,ans;
ll x[2000005];
//const ex1 = {};

int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		ans = 0;
		cin>>n>>d;
		for (ll i = 1;i<=n;i++){
			cin>>x[i];
		}
		for (ll u = 1;u<=n-1;u++){
			for (ll v = u + 1;v<=n;v++){
				ll w = 0;
				for (ll i = u + 1;i < v;i++){
					if (x[v] - x[i] <= d &&
						x[i] - x[u] <= d){
						w++;
					}
					if (w >= 3) break;
				}
				if (w == 2) ans++;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}

