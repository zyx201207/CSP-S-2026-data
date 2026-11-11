#include <bits/stdc++.h>
using namespace std;
#define int long long
const int maxn = 5e3+5;
int c,t,n,d;
int x[maxn],zdl[maxn][maxn],tha[maxn][maxn];
int iwa[maxn][maxn];
void solve(){
	cin >> n >> d;
	cin >> x[1] >> x[2];
	for (int i = 3;i <= n;i++){
		if (c <= 6) cin >> x[i];
		else cin >> x[3];
	}
	
	if (c == 11 || c == 12){
		int gc = x[2]-x[1];
		if (d < 2*gc) cout << 0 << '\n';
		else cout << max(0ll,n-2*(d/gc)+1ll) << '\n';
	}
	
	if (c <= 6){
		memset(zdl,0x3f,sizeof(zdl));
		for (int i = 1;i <= n;i++){
			int cf = i;
			zdl[i][i] = 0;
			for (int j = i+1;j <= n;j++){
				while (x[j]-x[cf] > d){
					cf++;
				}
				tha[i][j] = cf;
				zdl[i][j] = zdl[i][cf]+1;
				//cout << zdl[i][j] << ' ';
			}
			//cout << '\n';
		}
		
		int ans = 0;
		for (int l = 1;l <= n;l++){
			for (int i = 1;i <= n-l+1;i++){
				int j = i+l-1;
				iwa[i][j] = 1;
				for (int k = i+1;k < j;k++){
					if (k == tha[i][j]) continue;
					if (zdl[i][k]+zdl[k][j] == zdl[i][j]){
						iwa[i][j] += iwa[i][k]*iwa[k][j];
					}
				}
				//cout << i << ' ' << j << ':' << iwa[i][j] << '\n';
				if (iwa[i][j] == 2){
					ans++;
				}
			}
		}
		cout << ans << '\n';
	}
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	cin >> c >> t;
	while (t--){
		solve();
	} 
}
/*
0 2
5 3
-2 -1 0 1 2
6 2
-4 -3 -2 -1 3 6
*/
