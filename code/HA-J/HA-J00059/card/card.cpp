#include <bits/stdc++.h>
#define NDEBUG
#ifdef NDEBUG
	#define debug(x)
#else
	#define debug(x) cerr << #x << ' ' << x << endl
#endif
using namespace std;
/*
先打暴力吧 :) 
*/
const int N = 5e5 + 5;
const int M = 3e5 + 5;
int n, m, a[N];
int lst[M];
int ans[M];
int t[M];
inline void solve1(){
	for(int i = 1; i <= n; i++) ans[a[i]] = i;
	for(int i = 1; i <= m; i++) cout << ans[i] << ' ';
	return ;
}
inline void solve2(){
	for(int i = 1; i <= n; i++){
		debug("==================================");
		debug(i);
		for(int j = 1; j <= m; j++) lst[j] = 0;
		for(int j = i; j <= n; j++){
			if(!lst[a[j]]) lst[a[j]] = j;
			else {
				debug(j);
				int x = lst[a[j]];
				for(int k = j - 1; k > x; k--){
					lst[a[k]] = 0;
					debug(k);
					debug(a[k]);
				}
				lst[a[j]] = j;
			}
		}
		for(int j = 1; j <= m; j++){
			if(lst[j]){
				debug(j);
				ans[j]++;
			}
		}
	}
	for(int i = 1; i <= m; i++) cout << ans[i] << " ";
	return ;
}
bool flaga;
inline void solve(){
	cin >> n >> m;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
		if(a[i] < a[i - 1]) flaga = 1;
	}
	if(m == 1){
		cout << n;
		return ;
	}
	if(m == 2){ // 8
		for(int i = 1; i <= n; i++){
			if(a[i] != a[n]) ans[1]++, ans[2]++;
			else ans[a[n]]++;
		}
		for(int i = 1; i <= m; i++) cout << ans[i] << ' ';
		return ;
	}
	if(flaga){ // 4
		solve1();
		return ;
	}
	if(n <= 5000 && m <= 3000){ // 48
		solve2();
		return ;
	}
	return ;
}
signed main(){
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
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
