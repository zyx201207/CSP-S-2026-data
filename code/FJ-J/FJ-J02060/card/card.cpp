#include <bits/stdc++.h>
#define sp " "
#define el "\n"
#define r0 return 0
#define fi first
#define se second
#define F(i, a, b, c) for (int i = a; i <= b; i += c)

using namespace std;
typedef long long ll;
typedef string str;

int n, m;
int a[500010];
std::vector<int> v;
int f[300010];
int cnt[300010];

signed main() {
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);
	std::cout.tie(0);
	freopen("card.in", "r", stdin);
    freopen("card.out", "w", stdout);
	cin >> n >> m;
	bool isA = 1;
	F(i, 1, n, 1) {
		cin >> a[i];
		if (a[i - 1] > a[i]) {
			isA = 0;
		}
	}
	if (isA) {
		F(i, 1, n, 1) {
			f[a[i]] = i;
		}
		F(i, 1, m, 1) {
			cout << f[i] << sp;
		}
		cout << el;
		r0;
	}
	if (m == 2) {
		F(i, 1, n, 1) {
			if (a[i] == a[n])  {
				f[a[n]]++;
			} else {
				f[1]++, f[2]++;
			}
		}
		F(i, 1, m, 1) {
			cout << f[i] << sp;
		}
		cout << el;
		r0;
	}
	F(i, 1, n, 1) {
		F(i, 1, m, 1) {
			cnt[i] = 0;
		}
		v.clear();
		F(j, i, n, 1) {
			if (cnt[a[j]]) {
				while (v.back() != a[j]) {
					cnt[v.back()]--;
					v.pop_back();
				}
			} else {
				cnt[a[j]]++;
				v.push_back(a[j]);
			}
		}
		F(j, 1, m, 1) {
			f[j] += cnt[j];
		}
	}
	F(i, 1, m, 1) {
		cout << f[i] << sp;
	}
	cout << el;
	r0;
}
/*
1 2 1 3 2 3 1 2 1 3

*/
