//GZ-S00053 张善之 贵阳市云岩区中天中学
#include <bits/stdc++.h>
const int N = 5e5+10 ; 
using namespace std ;
#define ll long long 
struct node {
	ll val , to ;
};
vector<node> ve[505] ;
ll a[N] , b[5][N] ,c[5][N],be2[505],nd2[505],k[505];
struct n {
	ll x , y ;
};
vector<n> v1 ;
vector<n> v2 ;
signed main () {
	ios::sync_with_stdio(false) ;
	cin.tie(0),cout.tie(0);
	freopen("subway.in","r",stdin) ;
	freopen("subway.out","w",stdout) ;
	ll C , n , m , d , q ;
	cin >> C >> n >> m >> d >> q ;
	if(n<=3){
		for(int i=1;i<=n;i++) cin >> a[i] ;
		for(int i=1;i<=n;i++) {
			cin >> k[i] ;
			for(int j=1;j<=k[i];j++) cin >> b[i][j] >> c[i][j] ;
		}
		for(int i=1;i<=q;i++){
			ll be , nd , ans= 0 ; cin >> be >> nd ;
			if(n==1) {
				 ans+=a[be]+a[nd] ;
				 ans+=b[1][be] + b[1][nd] ;
				 cout << ans <<"\n";
				 continue ;
			}
				if(be==nd) {
					cout << 0 <<"\n" ;
					continue;
				}
				ans=1e9;bool f = true ;
				ll mi = 1e9 ,be1=1e9,nd1=1e9;
				for(ll i=1;i<=n;i++) {
					for(ll j=1;j<=k[i];j++) {
						if(b[i-1][j]==b[i][j]) mi = min(mi,c[i-1][j]+c[i][j]) ;
						if(b[i][j]==be){
							v1.push_back({i,j}) ;
							be1 = min(be1,c[i][j]) ;
						} 
						if(b[i][j]==nd){
							v2.push_back({i,j}) ;
							nd1 = min(nd1,c[i][j]) ;
						} 
					}
				}
				for(auto i:v1) {
					for(auto j:v2) {
						if(i.x==j.x){
							ans=min(ans,c[i.x][i.y]+c[j.x][j.y]) ;
							f = false ;
						} 
					}
				}
				if(f) {
					ans+=mi+be1+nd1 ;
				}
				ans+=a[be]+a[nd] ;
				cout << ans ;
		}
		
	}
	return 0 ;
}

