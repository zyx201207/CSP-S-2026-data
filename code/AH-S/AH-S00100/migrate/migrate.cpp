#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;
int c, t, n;
long long d, x[2000005], Ans;
int Hvl[2000005], Hvr[2000005];
namespace Std_Fail {
	void Run() {
		cin >> n >> d;
		for (int i = 1; i <= n; i++) cin >> x[i], Hvl[i] = Hvr[i] = 0;
		if (n < 4) {
			cout << "0\n";
			return ;
		}
		Ans = 0;
		int l = 1, m = 0, r = 0;
		while (m < n) {
			++m;
			while (x[r + 1] - x[m] <= d && r < n) ++r;
			while (x[m] - x[l] > d && l < m) ++l;
			if (r - m > 1) {
				++Hvr[r];
				//cout << m << " r: " << r << '\n';
			}
			if (m - l > 1) {
				++Hvl[l];
				//cout << m << " l: " << l << '\n';
			}
		}
		for (int i = 2; i < n; i++) {
			if (x[i + 1] - x[i] <= d && x[i + 1] - x[i - 1] > d) Hvr[i + 1] += Hvr[i];
		}
		for (int i = n - 1; i > 1; i--) {
			if (x[i] - x[i - 1] <= d && x[i + 1] - x[i - 1] > d) Hvl[i - 1] += Hvl[i];
		}
		for (int i = 1; i < n; i++) {
			Ans += (Hvl[i] * 1) * Hvr[i + 1];
			//cout << Hvl[i] << ' ' << Hvr[i] << '\n';
		}
		cout << Ans << '\n';
		return ;
	}
}
namespace BaoLi {
	int Dis[305][305];
	int GeShu[305];
	void Run() {
		memset(Dis, 0x3f, sizeof Dis);
		cin >> n >> d;
		for (int i = 1; i <= n; i++) {
			cin >> x[i];
			for (int j = i - 1; j ; j--) if (x[i] - x[j] <= d) Dis[j][i] = 1;
			Dis[i][i] = 0;
		}
		if (n < 4) {
			cout << "0\n";
			return ;
		}
		Ans = 0;
		for (int k = 1; k <= n; k++) for (int i = 1; i <= n; i++) for (int j = 1; j <= n; j++) Dis[i][j] = min(Dis[i][j], Dis[i][k] + Dis[k][j]);
		for (int i = 1; i < n; i++) {
			memset(GeShu, 0, sizeof GeShu);
			GeShu[i] = 1;
			for (int j = i + 1; j <= n; j++) {
				for (int k = j - 1; k >= i; k--) {
					//cout << j << ' ' << k << ' ' << GeShu[k] << '\n';
					if (x[j] - x[k] <= d) {
						if (Dis[i][j] == Dis[i][k] + 1) GeShu[j] += GeShu[k];// cout << "OK\n";
					} else break ;
 				}
 				if (GeShu[j] == 2) ++Ans;
 				//cout << GeShu[j] << ' ';
			}
			//cout << '\n';
		}
		cout << Ans << '\n';
		return ;
	}
}
namespace Special_A {
	void Run() {
		long long Cha = 0;
		cin >> n >> d;
		for (int i = 1; i <= n; i++) {
			cin >> x[i];
			if (i > 1) Cha = x[i] - x[i - 1];
		}
		if (Cha <= d / 2) cout << max(n + 1 - d / Cha * 2, 0LL)<< '\n';
		else cout << 0 << '\n';
	}
}
int main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> c >> t;
	while (t--) {
		if (c == 11 || c == 12){ // 8 pts
			Special_A::Run();
		} else {
			BaoLi::Run();//24 pts
		}
	}
	return 0;
}
//Oct31==Dec25?
// 24pts 16:37
// 8pts 16:56

