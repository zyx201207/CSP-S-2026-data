// Calm down.
// Think TWICE, code ONCE.
#include<bits/stdc++.h>
#define pb push_back
#define popcnt __builtin_popcountll
#define debug printf("Passed line %d\n", __LINE__)

using namespace std;
typedef long long ll;
typedef vector<int> vint;
typedef pair<int, int> PII;

template<typename T> inline void read(T &x){
	x = 0; bool F = 0; char c = getchar();
	for (;!isdigit(c);c = getchar()) if (c == '-') F = 1;
	for (;isdigit(c);c = getchar()) x = x*10+(c^48);
	if (F) x = -x;
}

template<typename T1, typename ...T2> inline void read(T1 &x, T2 &...y){read(x), read(y...);}

template<typename T> inline void checkmax(T &x, const T &y){if (x<y) x = y;}

template<typename T> inline void checkmin(T &x, const T &y){if (x>y) x = y;}

const int N = 505, M = 5e5+5;
vector<PII> vec[M]; // station, time
ll dis[N][N];
int w[M], n, m, d, q;

inline void init(){
	int _, a, t, sz; read(_, n, m, d, q);
	for (int i = 1;i<=m;i++) read(w[i]);
	for (int i = 1;i<=n;i++){
		read(sz);
		for (int j = 1;j<=sz;j++){
			read(a, t);
			vec[a].pb({i, t});
		}
	}
	memset(dis, 1, sizeof(dis));
	for (int i = 1;i<=n;i++) dis[i][i] = 0;
	for (int i = 1;i<=m;i++){
		for (auto j: vec[i]){
			for (auto k: vec[i]){
				checkmin(dis[j.first][k.first], 1ll*j.second+k.second);
			}
		}
	}
	for (int k = 1;k<=n;k++){
		for (int i = 1;i<=n;i++){
			for (int j = 1;j<=n;j++){
				checkmin(dis[i][j], dis[i][k]+dis[k][j]);
			}
		}
	}
}

int main(){
	// freopen("input.txt", "r", stdin);
	// freopen("out.txt", "w", stdout);
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	init(); int u, v; ll ans;
	while (q--){
		read(u, v), ans = 1e18;
		for (auto x: vec[u]){
			for (auto y: vec[v]){
				checkmin(ans, x.second+y.second+dis[x.first][y.first]);
			}
		}
		printf("%lld\n", ans + w[u] + w[v]);
	}
	return 0;
}