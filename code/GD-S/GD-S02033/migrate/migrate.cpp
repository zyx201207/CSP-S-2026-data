#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 500010;
int a[N], n, d; 

signed main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	int c, T; cin >> c >> T;
	while(T --) {
		int ans = 0; cin >> n >> d;
		for(int i = 1;i <= n;i ++) cin >> a[i];
		if(a[n] - a[1] <= d) {
			cout << 0 << endl;
			continue;
		}
		int num = 0, cnt = 0;
		for(int i = 2;i <= n;i ++) {
			num += a[i] - a[i - 1];
			if(num > d) {
				break;
			} cnt ++;
		}
		for(int i = 1;i <= n;i ++) {
			for(int j = i;j <= n;j ++) {
				if(j - i <= cnt + 1) continue;
				int kk = j - i - 1;
				int as = kk / cnt;
				int ll = kk % cnt;
				ans += 1; 
				for(int i = 1;i < ll;i ++){
					ans += (as - 1);
				}
			}
		}
		
		cout << ans << endl;
	}
	return 0;
}
