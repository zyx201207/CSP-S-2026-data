#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define mkp make_pair
#define pii pair<int, int>
#define pil pair<int, long long>
#define pli pair<long long, int>
#define pll pair<long long, long long>
#define debug(x) cerr << #x << ": " << (x) << "\n" 
#define ll long long
#define ull unsigned long long
#define uint unsigned int
using namespace std;
int n;
ll m, a[500007], s[500007];
signed main(){
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> n >> m;
	for(int i = 1; i <= n; i++) cin >> a[i];
	sort(a + 1, a + 1 + n);
	for(int i = 1; i <= n; i++) s[i] = s[i - 1] + a[i];
	int res = 1;
	for(int i = 2; i <= n; i++){
		int l = 1, r = i - 1, mid, ans = i;
		while(l <= r){
			mid = (l + r) / 2;
//			debug(l), debug(r), debug(mid);
//			debug(s[i - 1] - s[mid - 1] + m);
//			debug(a[i] * 1ll * (i - mid));
			if(s[i - 1] - s[mid - 1] + m >= a[i] * 1ll * (i - mid))
				r = mid - 1, ans = mid;
			else l = mid + 1;
		}
//		debug(i);
//		debug(ans);
		res = max(res, i - ans + 1);
	}
	cout << res;
}
/*
5 5
1 2 4 8 9
*/
