#include <iostream>
#include <vector>
#define int long long
using namespace std;
const int maxn = 5e5 + 10; 
int w[maxn], k[maxn], pre[maxn];
signed main(){
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	vector<int> a[505];
	vector<int> t[505];
	int c, n, m, d, q;
	cin >> c >> n >> m >> d >> q;
	for(int i = 1; i <= m; i++){
		cin >> w[i];
		pre[i] = pre[i - 1] + w[i];
	} 
	for(int i = 1; i <= n; i++){
		cin >> k[i];
		for(int i = 1; i <= k[i]; i++){
			int aa, tt;
			cin >> aa >> tt;
			a[i].push_back(aa);
			t[i].push_back(tt);
		}
	}
	while(q--){
		int l, r;
		cin >> l >> r;
		cout << pre[r] - pre[l - 1] << '\n';
	}
	return 0;
}
