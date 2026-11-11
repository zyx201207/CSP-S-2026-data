#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define M 100005
ll c, n, m, d, p, w[M], k[505], a[505][M], t[505][M], to[M], t2[505][M];
bool A = true, B = true;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	ll q, z, o;
	cin >> c >> n >> m >> d >> p;
	for(int i = 1;i <= m;i++) cin >> w[i];
	for(int i = 1;i <= n;i++){
		cin >> k[i];
		if(k[i] > 2) A = false;
		for(int j = 1;j <= k[i];j++){
			o = t[1][1];
			cin >> a[i][j] >> t[i][j];
			t2[i][a[i][j]] = t[i][j];
			if(to[a[i][j]] != 0) to[a[i][j]] = 0;
			to[a[i][j]] = i;
			if(o != t[i][j]) B = false;
		}
	}
	for(int i = 1;i <= q;i++){
		cin >> q >> z;
		if(n == 1){
			ll ans = t2[1][q] + t2[1][z] + w[q] + w[z];
			cout << ans << "\n";
		} else if(n == 2){
			ll ans;
			if(to[q] == 1 && (to[z] == 1 || to[z] == 0)){
				ans = t2[1][q] + t2[1][z] + w[q] + w[z];
				cout << ans << "\n";
			} else if(to[q] == 2 && (to[z] == 2 || to[2] == 0)){
				ans = t2[2][q] + t2[2][z] + w[q] + w[z];
				cout << ans << "\n";
			} else {
				if(to[q] == 1){
					ll minn = LLONG_MAX;
					for(int i = 1;i <= m;i++) minn = min(minn, t2[1][i] + t2[2][i]);
					ans = t2[1][q] + minn + t2[2][z] + w[q] + w[z];
					cout << ans < "\n"; 
				} else {
					ll minn = LLONG_MAX;
					for(int i = 1;i <= m;i++) minn = min(minn, t2[1][i] + t2[2][i]);
					ans = t2[2][q] + minn + t2[1][z] + w[q] + w[z];
					cout << ans << "\n";
				}
			}
		}
		
	}
	return 0;
} 
