#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int long long
const int N = 5e5 + 5;
int a[N];
signed main(){
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, m;
	cin >> n >> m;
	for (int i = 1;i <= n;i++){
        cin >> a[i];
	}
	sort(a + 1, a + n + 1);
	int l = 1, ans = 1, sum = 0;
	for (int r = 2;r <= n;r++){
        sum += (r - l) * (a[r] - a[r - 1]);
        if (sum <= m){
            ans = max(ans, r - l + 1);
            continue;
        }
        while (sum > m){
            sum -= (a[r] - a[l]);
            l++;
        }
        ans = max(ans, r - l + 1);
	}
	cout << ans;
	return 0;
}
