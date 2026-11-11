#include<bits/stdc++.h>

using namespace std;
using ll = long long;

const int N = 5e5 + 5;

ll m;
int n, ans;
ll a[N], pre[N];

int main(){
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> n >> m;
	for(int i = 1; i <= n; i++) cin >> a[i];
	sort(a + 1, a + 1 + n);
	for(int i = 1; i <= n; i++) pre[i] = pre[i - 1] + a[i]; 
	for(int i = 1; i <= n; i++){
		int l = 1, r = i + 1;
		while(l < r){
			int mid = l + r >> 1;
			a[i] * (i - mid + 1) - pre[i] + pre[mid - 1] <= m ? r = mid : l = mid + 1;
		}
		ans = max(ans, i - l + 1);
	}
	cout << ans;
	return 0;
}
/*

*/
