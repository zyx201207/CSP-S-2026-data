#include<bits/stdc++.h>
using ll = long long;
using namespace std;

constexpr int N = 2e6+7;

int n,_,c;

ll x[N],d;

int main(){freopen("migrate.in","r",stdin);freopen("migrate.out","w",stdout);
	cin>>c>>_;
	while(_--){
		cin>>n>>d;
		for(int i = 1;i<=n;i++){
			cin>>x[i];
		}
		ll ans = 0;
		int l = 1,r = 1;
		while(r <= n){
			if(x[r]-x[r-1] > d){
				if(r-l>=4&&x[r-1]-x[l] > d){
					ans += r-l-3;
				}
				l = r;
			}
			r++;
		}
		if(r-l>=4){
			for(int i = l;i+3<r;i++){
				if(x[i+3]-x[i] > d){
					ans ++;
				}
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}
