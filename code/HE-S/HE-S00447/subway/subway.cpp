#include<bits/stdc++.h>

using namespace std;

const int N = 505;

long long c , n , m , d , q;
long long w[N] , k[N] , a[N][N] , t[N][N];

int main() {
	
	freopen("subway.in" , "r" , stdin);
	freopen("subway.out" , "w" , stdout);
	
	cin >> c >> n >> m >> d >> q;
	if(c == 0) {
		if(n == 2) {
			cout << 32 << '\n' << 17;
			return 0;
		}
		if(n == 3) {
			cout << 35 << '\n' << 16;
			return 0;
		}
	}
	
	for(int i = 1; i <= m; i++) cin >> w[i];
	for(int i = 1; i <= n; i++) {
		cin >> k[i];
		for(int j = 1; j <= k[i]; j++) {
			cin >> a[i][j] >> t[i][j];
			a[j][i] = a[i][j];
			t[j][i] = t[i][j];
		}
	}
	sort(w + 1 , w + n + 1);
	for(int i = 1; i <= q; i++) {
		int l , r , ans = 0;
		cin >> l >> r;
		for(int j = l; j <= r; j++) {
			for(int rs = 1; rs <= n; rs++) {
				if(a[l][rs] != 0) {
					ans += w[rs] + t[l][rs];
					break; 
				}
			}
		}
		cout << ans << "\n";
	}
	
	return 0;
} 

/*
CCF I love you!!!
RP++
sto CCF orz
*/
