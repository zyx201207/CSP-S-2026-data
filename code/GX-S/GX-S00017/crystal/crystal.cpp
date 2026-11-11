#include<bits/stdc++.h>
const int N = 5e5+5;
using namespace std;
#define ll long long
namespace Pinball{
	int n;
	ll a[N], m, b[N];
    void Purgatory(){
		cin >> n >> m;
		for (int i = 1;i <= n;i++){
			cin >> a[i];
		}
		sort(a + 1, a + 1 + n);
		for (int i = 1;i <= n;i++){
			b[i] = b[i - 1] + a[i];
		}
		int ans = 0;
		for (int i = 1, j = 1;i <= n;i++){
			while (j < i){
				ll v = (i - j + 1) * a[i] - (b[i] - b[j - 1]);
				if (v > m){
					++j;
				}
				else break;
			}
			ans = max(ans, i - j + 1);
		}
		cout << ans;
    }
}
signed main(){
    cin.tie(0)->sync_with_stdio(false);
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	int T = 1;
	while (T--) Pinball::Purgatory();
	return 0;
}