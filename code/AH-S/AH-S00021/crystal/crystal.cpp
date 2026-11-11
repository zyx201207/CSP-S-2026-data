#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 5e5 + 10;
int a[N], n, m, ans = 1;
signed main(){
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for(int i = 1; i <= n; i++) cin >> a[i];
    sort(a + 1, a + n + 1);
    int L = 1, tot = 0;
    for(int i = 2; i <= n; i++){
        int sum = tot + (a[i] - a[i - 1]) * (i - L);
        while(sum > m){
            sum -= a[i] - a[L];
            L ++;
        }
        tot = sum;
        ans = max(ans, i - L + 1);
    }
    cout << ans << '\n';
	return 0;
}
