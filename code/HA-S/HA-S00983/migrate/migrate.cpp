#include<bits/stdc++.h>
#define ll long long
#define N 2000100

using namespace std;

ll n,a[N],c,T,m,b[N],d,minn=2e18+1;
vector<ll> mp[1005][1005]; 	

inline void f(ll x,ll he,ll j,ll jj) {
	if(x==j){
		mp[jj][j].push_back(he);
		return ;
	}	
	for(int i = 1; i <= n; ++i) {
		if(x==i||i==jj) {
			continue;
		}
		if(!b[i]) {
			if(abs(a[x]-a[i])<=d) {
				b[i]=1;
//				cout << i << ' ' << x << "\n";
				f(i,he+1,j,jj);
				b[i]=0;
			}			
		}
	}
}

signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin >> c >> T;
	while(T--) {
		memset(b,0,sizeof b);
		ll ans=0;
		cin >> n >> d;
		for(int i = 1; i <= n; ++i) {
			cin >> a[i];
		}
		for(int i = 1; i <= n; ++i) {
			for(int j = i+1; j <= n; ++j) {
				b[i]=1;
				f(i,0,j,i);
				b[i]=0;
			}			
		}
		for(int i = 1; i <= n; ++i) {
			for(int j = i+1; j <= n; ++j) {
				ll minn=2e18+1;
				for(auto v : mp[i][j]) {
					minn=min(minn,v);
//					cout << v << "\n";
				}		
				ll u=0;
				for(auto v : mp[i][j]) {
					if(v==minn) {
						u++;
					}	
//					cout << minn << " " << v << " " << i << " " << j << "\n"; 			
				}	
				if(u>=2) {
					ans++;
				}							
			}
		}
		cout << ans << "\n";
	}
	return 0;
} 
