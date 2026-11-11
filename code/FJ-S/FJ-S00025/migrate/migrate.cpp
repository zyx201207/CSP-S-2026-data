/*

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

0 1
7 666666666666666663
-1000000000000000000 -555555555555555558 -111111111111111116 111111111111111105 333333333333333326 555555555555555547 999999999999999989


*/

#include <bits/stdc++.h>
#define rep(i,a,b) for(int i = (a);i <= (b);i++)
#define per(i,a,b) for(int i = (a);i >= (b);i--)

using namespace std;

typedef long long ll;

//const int N = 2000006;
const int N = 503;

int n;
ll d;
ll a[N];

int f[N][N],ct[N][N];

void solve(){
	cin >> n >> d;
	rep(i,1,n) cin >> a[i];
	rep(i,1,n) f[i][i] = 0,ct[i][i] = 1;
	int ans = 0;
	rep(i,1,n) rep(j,i + 1,n){
		f[i][j] = N;
		ct[i][j] = 0;
		rep(k,i,j - 1){
			if(a[j] - a[k] > d) continue;
			f[i][j] = min(f[i][j],f[i][k] + 1);
		}
		rep(k,i,j - 1){
			if(a[j] - a[k] > d) continue;
			if(f[i][j] == f[i][k] + 1) ct[i][j] += ct[i][k];
		}
//		cout << i << " " << j << " " << ct[i][j] << '\n';
		if(ct[i][j] == 2) ans++;
	}
	cout << ans << '\n';
}

int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	int c,t;
	cin >> c >> t;
	while(t--){
		solve();
	}
	return 0;
}

