#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN = 5e5 + 5;
ll a[MAXN], sum[MAXN]; 
int main(){
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	int n;
	ll m;
	cin >> n >> m;
	for(int i = 1; i <= n; i++) cin >> a[i];
	sort(a + 1, a + n + 1);
	for(int i = 1; i <= n; i++) sum[i] = sum[i - 1] + a[i];
	int ans = 0;
	for(int i = 1; i <= n; i++){
		int l = 1, r = i, mid;
		while(l <= r){
			mid = (l + r >> 1);
			ll need = a[i] * (i - mid + 1) - (sum[i] - sum[mid - 1]);
			if(need <= m) r = mid - 1;
			else l = mid + 1;
		}
		ans = max(ans, i - l + 1);
	}
	cout << ans;
	return 0;
}
