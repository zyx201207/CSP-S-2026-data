#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;
const int N = 5e5+5;
int n, l, r, len, ans;
ll m, a[N], lst, cur;
int main(){
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; ++i) cin >> a[i];
	sort(a+1, a+n+1);
	ans = 1, l = 1, r = 1, lst = a[l], cur = m, len = 1;
	while (r <= n){
		++r;
		while ((a[r]-lst)*len > cur){
			cur += lst-a[l++];
			--len;
		}
		cur -= (a[r]-lst)*len;
		++len;
		lst = a[r];
		ans = max(ans, len);
	}
	cout << ans << '\n';
	
	return 0;
} 
