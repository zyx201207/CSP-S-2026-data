#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 5e5 + 10, M = 510;
bool vis[M][N]; 
int c, n, m, d, q;
ll t[M][N], w[N];
int main(){
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	cin >> c >> n >> m >> d >> q;
    for(int i = 1; i <= m; i++)
    	cin >> w[i];
    for(int i = 1; i <= n; i++){
    	int k;
    	cin >> k;
    	for(int j = 1; j <= k; j++){
    		int x;
    		cin >> x >> t[i][j];
    		vis[i][x] = 1;
		}
	}
	while(q--){
		int l, r;
		cin >> l >> r;
		ll ans = LLONG_MAX;
		for(int i = 1; i <= n; i++){
			if(vis[i][l] && vis[i][r]){
				ans = t[1][1] * 2 + w[l] + w[r];
				cout << ans << "\n";
				break;
			}
		}
	}
    return 0;
}


