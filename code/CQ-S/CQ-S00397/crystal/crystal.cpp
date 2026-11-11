#include <bits/stdc++.h>
#define int long long

using namespace std;

namespace Code {
	constexpr int N = 5e5 + 5;

	int n, m;
	int a[N];

	class SegTree {
	private:
		struct Range {
			int sum, lazy;
		} Tree[N << 2];

	public:
		void PushUp(int pos) { Tree[pos].sum = Tree[pos << 1].sum + Tree[pos << 1 | 1].sum; }

		void PushDown(int pos, int s, int t) {
			if (!Tree[pos].lazy) return ;

			int mid = s + ((t - s) >> 1);
			Tree[pos << 1].lazy += Tree[pos].lazy;
			Tree[pos << 1 | 1].lazy += Tree[pos].lazy;
			Tree[pos << 1].sum += Tree[pos].lazy * (mid - s + 1);
			Tree[pos << 1 | 1].sum += Tree[pos].lazy * (t - mid);
			Tree[pos].lazy = 0;
		}

		void Change(int pos, int s, int t, int L, int R, int val) {
			if (L <= s && t <= R) {
				Tree[pos].sum += val * (t - s + 1);
				Tree[pos].lazy += val;
				return ;
			}
			PushDown(pos, s, t);

			int mid = s + ((t - s) >> 1);
			if (L <= mid) Change(pos << 1, s, mid, L, R, val);
			if (R > mid) Change(pos << 1 | 1, mid + 1, t, L, R, val);

			PushUp(pos);
		}

		int Query(int pos, int s, int t, int L, int R) {
			if (L <= s && t <= R) return Tree[pos].sum;
			PushDown(pos, s, t);

			int mid = s + ((t - s) >> 1), res = 0;
			if (L <= mid) res += Query(pos << 1, s, mid, L, R);
			if (R > mid) res += Query(pos << 1 | 1, mid + 1, t, L, R);

			return res;
		}
	} T;

	void main() {
		cin >> n >> m;
		for (int i = 1; i <= n; ++ i) cin >> a[i];
		sort(a + 1, a + n + 1);

		int ans = 1;
		for (int i = 2; i <= n; ++ i) {
			T.Change(1, 1, n, 1, i - 1, a[i] - a[i - 1]);

			int l = 1, r = i - 1, pos = i;
			while (l <= r) {
				int mid = l + ((r - l) >> 1);
				if (T.Query(1, 1, n, mid, i - 1) <= m) r = mid - 1, pos = mid;
				else l = mid + 1;
			}

			ans = max(ans, i - pos + 1);
		}

		cout << ans << '\n';
	}
}

signed main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);

	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	Code::main();

	return 0;
}

/*
++ rp
*/