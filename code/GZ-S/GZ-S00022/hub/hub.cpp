//GZ-S00022 云岩区实验中学 向子睿
#include<bits/stdc++.h>
using namespace std;
#define int long long
const int maxn = 1000010, inf = 0x3f3f3f3f3f3f3f3fll;

int c, t, n, u, v, k;

void solve(){
    int ans = inf;
    cin >> n >> k;
    for(int i = 1; i < n; i++){
        cin >> u >> v;
    }int m = n >> 1, a = (m - k) >> 2, b = (m - k) & 3 + 1;
    int sum = (a * (a + 1) * 4) + ((a + 1) * b);
    cout << sum*2+1;
}

signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	cin >> c >> t;
	while(t--){
        solve();
	}
	return 0;
}
