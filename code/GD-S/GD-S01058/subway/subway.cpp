#include <bits/stdc++.h> 
using namespace std;
using ll = long long;
#define pii pair<int ,int>
ll read() {
	ll n = 0 ,f = 1; char c = getchar();
	while (c < '0' || c > '9') f = (c == '-') ? -f : f ,c = getchar();
	while (c >= '0' && c <= '9') n = n * 10 + c - '0' ,c = getchar();
	return n * f;
}
template<class T> inline void chkmx(T &x ,T y) { if (y > x) x = y; }
template<class T> inline void chkmn(T &x ,T y) { if (y < x) x = y; }

const ll inf = 1e18;
const int N = 510 ,M = 5e5 + 10;

int n ,m ,d ,q;
ll w[M] ,dis[N][N];
vector<pii> vec[M];

int main() {
//	freopen("subway7.in" ,"r" ,stdin);
	freopen("subway.in" ,"r" ,stdin);
	freopen("subway.out" ,"w" ,stdout);
	read() ,n = read() ,m = read() ,d = read() ,q = read();
	for (int i = 1;i <= m;i++) w[i] = read();
	for (int i = 1;i <= n;i++) {
		int k = read();
		for (int j = 1;j <= k;j++) {
			int a = read() ,t = read();
			vec[a].push_back({i ,t});
		}
	}
	for (int i = 1;i <= n;i++) for (int j = 1;j <= n;j++) dis[i][j] = inf;
	for (int i = 1;i <= n;i++) dis[i][i] = 0;
	for (int i = 1;i <= m;i++)
		for (auto [a ,da] : vec[i])
			for (auto [b ,db] : vec[i]) if (a != b)
				chkmn(dis[a][b] ,1LL * da + db);
	for (int k = 1;k <= n;k++) for (int i = 1;i <= n;i++) for (int j = 1;j <= n;j++) chkmn(dis[i][j] ,dis[i][k] + dis[k][j]);
	while (q--) {
		int x = read() ,y = read();
		if (x == y) { puts("0"); continue; }
		ll ans = inf;
		for (auto [a ,da] : vec[x]) for (auto [b ,db] : vec[y]) chkmn(ans ,dis[a][b] + da + db);
		printf("%lld\n",w[x] + w[y] + ans);
	}
	return 0;
}
/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2
*/
