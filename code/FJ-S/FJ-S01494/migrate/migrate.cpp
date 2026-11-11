#include<bits/stdc++.h>
#define F(i,a,b) for ( int i=a; i<=b; i++)
#define FF(i,a,b) for ( int i=a; i>=b; i--)
#define lb(x) ( x & -x)
#define lp ( p <<1)
#define rp ( p <<1 |1)
#define emb emplace_back
using ll =long long;
using ull =unsigned long long;
using db =double;
using ldb =long double;
const int MAXN =2e6+6;

using namespace std;
int n;
ll d,a[MAXN];
int dp[305][305][305];
	
bool check( int l,int r) {
	cout <<l <<' ' <<r <<": ";
	int cnt =0; ll x =a[l],p =l;
	while ( x <a[r] && l <r) {
		x +=d,++cnt;
		if ( x <a[p]) return 0;
		while ( x >=a[p +1]) ++p;
	}	
	int dp[305][305][305];
	F ( i,l +1,r) {
		if ( a[l] +d <a[i]) break;
		dp[l][i][1] =1;
	}
}

void solve() {
	cin >>n >>d;
	ll ans =0;
	F ( i,1,n) F ( j,1,n) F ( k,1,n) dp[i][j][k] =0;
	F ( i,1,n) cin >>a[i];
	F ( i,1,n) {
		F ( j,i +1,n) {
			if ( a[i] +d <a[j]) break;
			dp[i][j][1] =1;
		}
	}
	F ( l,1,n) {
		F ( r,l,n) {
			F ( k,l +1,r -1) {
				F ( i,2,r -l +1) {
					if ( a[k] +d <a[r]) continue;
					dp[l][r][i] +=dp[l][k][i -1];
				}
			}
		}
	}
	F ( i,1,n) {
		F ( j,i +2,n) {
			int f =1;
			F ( k,1,n) {
				int tmp =dp[i][j][k];
				if ( tmp) {
					ans +=( tmp ==2); break;
				} 
			}
		}
	}
	cout <<ans <<'\n';
}

signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);

	int T,c; cin >>c >>T;
	while ( T --) solve();


	return 0;
}
/****
0 2
4 2
1 2 3 4
5 2
1 2 3 4 5

0 2
5 3
-2 -1 0 1 2
6 2
-4 -3 -2 -1 3 6

****/
