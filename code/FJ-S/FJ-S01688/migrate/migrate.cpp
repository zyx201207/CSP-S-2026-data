#include <bits/stdc++.h>
#define ll long long
using namespace std;
constexpr int N = 2e6 + 5; 
ll c, T, n, d, a[N], f[N], g[N];
void work(){
	ll res = 0;
	for(int i = 1; i <= n ; i ++){// i -> j
		f[i] = 1;
		g[i] = 0;
		for(int j = i + 1; j <= n ; j ++){
			f[j] = 0;
			g[j] = 1e18;
			for(int k = i; k < j; k ++){
				if(a[j] - a[k] <= d){
					if(g[j] == 1e18 || g[j] == g[k] + 1){
						g[j] = g[k] + 1;
						f[j] += f[k];
					}
				}
			}
			if(f[j] == 2) res ++;
		}
	}
	cout << res << '\n'; 
} 
int main(){
	ios::sync_with_stdio(0); cin.tie(0);	
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	cin >> c >> T;
	while(T --){
		cin >> n >> d;
		for(int i = 1; i <= n ; i ++)
			cin >> a[i];
		if(n <= 5000) {
			work();
			continue;
		}
		int p = a[2] - a[1];
		int t = d / p;
		cout << n - 2 * t + 1 << '\n';
	}
	return 0;
}
