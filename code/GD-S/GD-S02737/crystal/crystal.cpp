#include <iostream>
#include <algorithm>
using namespace std;
using ll = long long;
const int MAXN = 500005;
int n, m, a[MAXN];
int main(){
	 freopen("crystal.in", "r", stdin);
	 freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
	}
	sort(a + 1, a + 1 + n);
	int l = 1, r = 1, ans = -1;
	ll usg = 0;
	while(r <= n){
		while(usg > m && l < r){
			usg -= a[r] - a[l];
			l++;
		}
		ans = max(ans, r - l + 1);
		usg += (a[r + 1] - a[r]) * (r - l + 1);
		r++;
	}
	cout << ans;
	return 0;
}
