#include <bits/stdc++.h>
#define int long long
#define NDEBUG
#ifdef NDEBUG
	#define debug(x)
#else
	#define debug(x) cerr << #x << ' ' << x << endl
#endif
using namespace std;
const int N = 2e5 + 5;
int n;
int a[N];
char c[N];
int cnt;
inline void solve(){
	cin >> n;
	for(int i = 1; i <= n; i++){
		cin >> a[i] >> c[i];
		cnt += a[i];
	}
	int l = 1, r = n, ans = 0;
	while(l < r){
		if(c[l] == c[r]){
			if(a[l] == a[r]) l++, r--;
			else if(a[l] < a[r]) a[r] -= a[l], l++;
			else a[l] -= a[r], r--;
		} else {
			if(a[l] == a[r]) ans += a[r], l++, r--;
			else if(a[l] < a[r]) ans += a[l], a[r] -= a[l], l++;
			else ans += a[r], a[l] -= a[r], r--;
		}
	}
	cout << ans;
	return ;
}
signed main(){
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	int t = 1;
	// cin >> t;
	while(t--) solve();
	return 0;
}

/*
众星因你，皆降为尘
华风夏韵，洛水天依
乐正司百曲，绫动万年红
言起一人歌，歌起万人和

QWQ luogu 1008686 wayneoi
*/
