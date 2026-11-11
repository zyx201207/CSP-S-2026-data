#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e5+5;
const int K = 30;
int n, m, a[N], f[N], ans[40];
signed main(){
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	for(int i = 1; i <= n; i++) cin >> a[i];
	for(int mask = K; mask >= 0; mask--){
		int cnt = 0;
		for(int i = 1; i <= n; i++){
			if((a[i]>>mask)&1){
				bool ok = 1;
				for(int o = K; o >= mask; o--){
					if(((a[i]>>o)&1) == 0 && ans[o] == 1) ok = 0;
				}
				if(ok) cnt++;
			}
		}
		if(cnt >= m) ans[mask] = 1;
	}
	int res = 0;
	for(int i = 0; i <= K; i++)
		if(ans[i]) res += (1<<i);
	cout << res;
	return 0;
} 
