#include <bits/stdc++.h>
#define int long long 
#define r(x) for (int i = 1; i <= x; i++)
#define rep(i, a, b) for (int i = a; i <= b; i++)
#define reb(i, a, b) for (int i = a; i >= b; i--)
using namespace std;

const int N = 305, M = 2e6 + 50; 
int c, t, n, d, p[M], dis[N][N], f[N][N];

bool ch(int x, int y) {
	x = min(x, n), y = min(y, n);
	x = max(x, 1ll), y = max(y, 1ll);
	return abs(p[y] - p[x]) <= d;
}
void solvea() {
	int id = 0;
	r(n) if (p[i] - p[1] > d) {
		id = i; break;
	}
	id--; if (id <= 2) cout << "0\n"; 
	else cout << max(0ll, n - id * 2 + 3) << "\n";
}

signed main()
{
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	cin.tie(0)->sync_with_stdio(0);
	cin >> c >> t;
	while (t--) {
		cin >> n >> d;
		r(n) cin >> p[i];
		if (c == 11 || c == 12) { solvea(); continue; }
		int ans = 0; memset(dis, 0x3f, sizeof dis);
		r(n) rep(j, i + 1, n) if (ch(i, j)) dis[i][j] = 1, f[i][j] = 1;
		rep(k, 1, n) rep(i, 1, n) rep(j, 1, n) {
			if (dis[i][j] == dis[i][k] + dis[k][j]) {
				if (f[i][k] < 0 || f[k][j] < 0) f[i][j] = -1;
				else f[i][j] += f[i][k] * f[k][j];
				if (f[i][j] > 2) f[i][j] = -1;
			}
			else if (dis[i][j] > dis[i][k] + dis[k][j]) {
				dis[i][j] = dis[i][k] + dis[k][j];
				if (f[i][k] < 0 || f[k][j] < 0) f[i][j] = -1;
				else f[i][j] = f[i][k] * f[k][j];
				if (f[i][j] > 2) f[i][j] = -1;
			}
		}
		r(n) rep(j, i + 1, n) ans += (f[i][j] == 2);
		cout << ans << "\n"; 
	}
	return 0;
}
// 15:50 决定开始写一个做法，不知道正不正确，但是参考 T2 难度，可能会和 CSP2024 一样，并不难？
// 16:15 写完过不了样例，好像假了，哭了。 
// 16:20 决定上个厕所。回来继续写。
// 16:26 重新想了一个做法，开始写一下，应该更对一点，不过好像是 O(n^2) 的。 
// 状态并不是很好，打算写完这个做法之后如果错了就去打 T4 的指数级暴力。 
// 感觉挺假的，但是又不知道是哪个地方有问题，主要还是要让自己有事干 =v= 
// 多测有点恶啊感觉。假算并不能抠到什么分。假完了，现在知道问题了。
// 16:55 okok，但是现在也是只会 n^3 的 24pts 啊。看看能不能抠到 AB 性质。
// 17:05 写完了 n^3，现在在调，这个计算方案还是比较恶心。
// 17:07 okok，24pts get.现在已经 224pts了，比前两年都高了，现在润去 T4 写暴力。
// 不管结果怎么样，至少场上全力以赴了。 
// 17:56 写完 T4 暴力，检查完 T1,T2，现在想想这题的性质分和 n^2 能不能写出来。
// 18:02 想不到 n^2 做法，于是又去上了个厕所，现在打算看性质。现在 239pts。 
