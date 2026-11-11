#include <bits/stdc++.h>
#define int long long
#define x first
#define y second
#define NDEBUG
#ifdef NDEBUG
	#define debug(x)
#else
	#define debug(x) cerr << #x << ' ' << x << endl
#endif
using namespace std;
typedef pair<int, int> PII;
const int N = 2e6 + 5;
int n, d;
int a[N];
int f[301][301];
inline void solve(){
	memset(f, 0, sizeof f);
	cin >> n >> d;
	if(n >= 300){
		cout << "0\n";
		return ;
	}
	for(int i = 1; i <= n; i++){
		cin >> a[i];
	}
	for(int i = 1; i <= n; i++){
		for(int j = i + 1; j <= n && (a[j] - a[i]) <= d; j++){
			for(int k = j + 1; k <= n && (a[k] - a[j]) <= d; k++){
				f[i][k] += (bool)(((a[j] - a[i]) <= d) && ((a[k] - a[j]) <= d) && ((a[k] - a[i]) > d));
//				cout << i << ' ' << k << ' ' << f[i][k] << '\n';
			}
		}
	}
	int ans = 0;
	for(int i = 1; i <= n; i++){
		for(int j = i + 1; j <= n; j++){
//			cout << f[i][j] << ' ';
			ans += (f[i][j] == 2);
		}
//		cout << '\n';
	}
	cout << ans << '\n';
	return ;
}
signed main(){
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	int c, t = 1;
	cin >> c >> t;
	while(t--) solve(); 
	return 0;
}

/*
众星因你，皆降为尘
华风夏韵，洛水天依
乐正司百曲，绫动万年红
言起一人歌，歌起万人和

luogu 1008686 wayneoi 喵！
*/
