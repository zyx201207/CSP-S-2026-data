#include <bits/stdc++.h>
#define int long long
#define NDEBUG
#ifdef NDEBUG
	#define debug(x)
#else
	#define debug(x) cerr << #x << ' ' << x << endl
#endif
using namespace std;
/*
我们把每个数字每一位是否有一，贪心让最高位最大即可。 
*/
const int N = 2e5 + 5;
int n, m;
int a[N];
int vis[N];
int yao[N];
int ans; 
inline void solve(){
	cin >> n >> m;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
	}
	for(int k = 29, cnt; k >= 0; k--){ // 枚举第 k 位
		ans += (1 << k);
		cnt = 0;
		for(int i = 1; i <= n; i++){
			if(vis[i]) continue;
			yao[i] = (a[i] >> k & 1);
			cnt += yao[i];
		}
		if(cnt >= m){
			debug(1 << k);
			for(int i = 1; i <= n; i++) vis[i] = !yao[i];
		}
	}
	for(int i = 1; i <= n; i++){
		if(!vis[i]){
			ans &= a[i];
			debug(a[i]);
			debug(ans);
		}
	}
	cout << ans;
	return ;
}
signed main(){
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
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
