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
const int MAXN =5e5+5;
const ll INF =1e18;
using namespace std;
ll a[MAXN],m;
int n;

bool check( int mid) {
	ll res =0,sum =0; int l =1,r =mid;
	F ( i,1,mid) sum +=a[mid] -a[i];
	res =sum;
	F ( i,mid +1,n) {
		sum -=a[i -1] -a[l];
//		cout <<"-: " <<a[i -1] -a[l] <<", ";
		sum +=1ll *( mid -1) *( a[i] -a[ i -1]);
//		cout <<"add:" <<( 1ll *( mid -1) *( a[i] -a[i -1])) <<'\n';
		res =min( res,sum),++l;
	}
	if ( res <=m) return 1;
	else return 0;
}

void solve() {
	cin >>n >>m;
	ll mn =INF,mx =-INF;
	F ( i,1,n) cin >>a[i];
//	F ( i,1,n) mn =min( a[i],mn),mx =max( mx,a[i]);
	sort( a +1,a +n +1);
	int l =0,r =n,ans =0;
	while ( l <=r) {
		int mid =l+r >>1;
		if ( check( mid)) l =mid +1,ans =mid;
		else r =mid -1;
	}
	cout <<ans <<'\n';
}

signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
	solve();


	return 0;
}
/****
5 5
1 2 4 8 9

5 8
-3 -1 2 2 7

crystal
****/

