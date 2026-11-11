#include<bits/stdc++.h>
#define N 5007
#define ll long long
using namespace std;
int c, T;
int n;
ll d;
ll a[N];
int l[N], r[N];
ll f[N][N], g[N][N];
int main(){
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> c >> T;
	
	while(T--){
		cin >> n >> d;
		for(int i = 1;i <= n;i++){
			cin >> a[i];
		}
		int p = 1;
		for(int i = 1;i <= n;i++){
			while(a[i] - a[p] > d){
				p++;
			}
			l[i] = p;
		}
		p = n;
		for(int i = n;i >= 1;i--){
			while(a[p] - a[i] > d){
				p--;
			}
			r[i] = p;
		}
		ll ans = 0;
		for(int i = 1;i <= n;i++){
			f[i][i] = 0;
			g[i][i] = 1;
			for(int j = i + 1;j <= n;j++){
				f[i][j] = f[i][max(i, l[j])] + 1;
				g[i][j] = g[i][max(i, l[j])];
				for(int k = max(i, l[j]) + 1;k < j;k++){
					if(f[i][k] + 1 == f[i][j]){
						g[i][j] += g[i][k];
						if(g[i][j] > 2)break;
					}
					else break;
				}
				if(g[i][j] == 2)ans++;
			}
		}
		cout << ans << '\n';
	}
	
	return 0;
}
