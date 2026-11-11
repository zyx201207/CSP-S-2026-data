#include <iostream>
using namespace std;
int n, a[500005], m;
int Ans[500005];
namespace Baoli {
	int Cnt[5005];
	int Ls[3005];
	bool Hv[5005];
	void Run() {
		for (int st = 1; st <= n; st++) {
			for (int i = 1; i <= n; i++) Hv[i] = 0, Cnt[i] = 0;
			for (int i = 1; i <= m; i++) Ls[i] = 0;
			for (int i = st; i <= n; i++) {
				if (Ls[a[i]] == 0) {
					Hv[i] = 1;
					Ls[a[i]] = i;
				} else {
					for (int j = Ls[a[i]]; j < i; j++) {
						Hv[j] = 0;
						Ls[a[j]] = 0;
					}
					Ls[a[i]] = i;
					Hv[i] = 1;
				}
			}
			for (int i = 1; i <= n; i++) Cnt[a[i]] += Hv[i];
			for (int i = 1; i <= m; i++) if(Cnt[i]) ++Ans[i];
		}
		for (int i = 1; i <= m; i++) cout << Ans[i] << ' ';
		return ;
	}
}
namespace Special_A {
	void Run() {
		for (int i = 1; i <= n; i++) {
			Ans[a[i]] = i;
		}
		for (int i = 1; i <= m; i++) cout << Ans[i] << ' ';
	}
}
namespace M_le_2 {
	void Run() {
		for (int i = 1; i <= n; i++) {
			if (a[i] != a[n]) ++Ans[1], ++Ans[2];
			else ++Ans[a[n]];
		}
		if (m == 2) cout << Ans[1] << ' ' << Ans[2];
		else cout << n;
	}
}
bool Sa = 1;
int main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) cin >> a[i], Sa = Sa && (a[i - 1] <= a[i]);
	if (Sa) Special_A::Run();
	else if (m <= 2) M_le_2::Run();
	else Baoli::Run();
	return 0;
}
/*
Trick||Treat!
*/
// 1~14, 20 -> 15 * 4 = 60pts

