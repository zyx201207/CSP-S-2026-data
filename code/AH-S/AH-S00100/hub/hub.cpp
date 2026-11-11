#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
int c, t, n, k;
struct Edge {
	int To, Next;
} E[200005];
int H[100005], Cnt;
void Add(int u, int v) {
	E[++Cnt] = {v, H[u]};
	H[u] = Cnt;
}
bool Used[15];
int Ans, Ans1;
namespace Baoli {
	int Dfs1(int Idx, int Fa) {
		int Res = Used[Idx];
		if (Used[Fa]) Res = 0;
		for (int i = H[Idx]; i; i = E[i].Next) {
			int j = E[i].To;
			if (j == Fa) continue ;
			Res += Dfs1(j, Idx);
		}
		return Res;
	}
	int Dfs2(int Idx, int Fa, int SD) {
		int FD = SD;
		if (Used[Idx]) FD = 0;
		int RD = FD;
		for (int i = H[Idx]; i; i = E[i].Next) {
			int j = E[i].To;
			if (j == Fa) continue ;
			RD = min(Dfs2(j, Idx, FD + 1), RD);
		}
		Ans1 = max(Ans1, RD);
		return RD + 1;
	}
	void Dfs(int Idx, int Cnt) {
		if (Idx > n) {
			if (Dfs1(1, 0) <= 2) {
				Ans1 = 0;
				Dfs2(1, 0, 100000);
				Ans = min(Ans, Ans1);
			}
			return ;
		}
		if (Cnt < k) Used[Idx] = 1, Dfs(Idx + 1, Cnt + 1);
		Used[Idx] = 0, Dfs(Idx + 1, Cnt);
	}
	void Run() {
		memset(H, 0, sizeof H);
		Cnt = 0;
		cin >> n >> k;
		for (int i = 1; i < n; i++) {
			int u, v;
			cin >> u >> v;
			Add(u, v);
			Add(v, u);
		}
		Ans = 100000;
		Dfs(1, 0);
		cout << Ans << '\n';
		return ;
	}
}
namespace Special_A{
	void Run() {
		cin >> n >> k;
		for (int i = 1; i < n; i++) {
			int u, v;
			cin >> u >> v;
		}
		if (k >= n) {
			cout << 0 << '\n';
			return ;
		}
		int Length = n / 2 + 1;
		if (k == 1) {
			cout << (Length + 1) / 2;
		} else {
			int Res = Length / 4 + 1;
			k = k - 2;
			if (Length % 4 < 2 && k > 0) --k, --Res;
			Res -= k / 4; 
			cout << max(Res, 1) << '\n';
		}
	}
}
int main() {
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin >> c >> t;
	while (t--) {
		if (c == 13 || c == 14) Special_A::Run();
		else Baoli::Run();
	}
	return 0;
}
//Oct31==Dec25?
// 15pts 17:22
// 10pts 17:59


