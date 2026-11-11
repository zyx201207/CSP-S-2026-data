#include <bits/stdc++.h>
#define N 2000005
#define M 5005
#define inf 0x3f3f3f3f3f3f3f3f
using namespace std;

typedef long long ll;

ll c, T, n, d, x[N], dis[M][M];

typedef long long ll;

ll aabs(ll x) {
	return x < 0 ? -x : x;
}

int main() {
//	system("fc migrate.out migrate3.ans");
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	cin >> c >> T;
	while(T--) {
		cin >> n >> d;
		for(ll i = 1; i <= n; i++) cin >> x[i];
		if(c <= 6) {
			for(ll i = 1; i <= n; i++) for(ll j = 1; j <= n; j++) {
				if(i == j) dis[i][j] = 0;
				else if(aabs(x[i] - x[j]) <= d) dis[i][j] = 1;
				else dis[i][j] = inf;
			}
			for(ll k = 1; k <= n; k++) 
				for(ll i = 1; i <= n; i++) 
					for(ll j = 1; j <= n; j++) dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
//			for(ll i = 1; i <= n; i++)
//				for(ll j = 1; j <= n; j++, puts("")) cout << dis[i][j] << " ";
			ll ans = 0;
			for(ll i = 1; i <= n; i++) 
				for(ll j = 1; j <= n; j++) {
					ll cnt = 0;
					for(ll k = 1; k <= n; k++) if(dis[i][j] == dis[i][k] + dis[k][j]) cnt++;
//					cout << i << " " << j << " " << cnt << "\n";
					if(cnt == dis[i][j] + 2) ans++;
				}
			cout << ans / 2 << "\n";
		} else {
			
		}
	}
	return 0;
}
