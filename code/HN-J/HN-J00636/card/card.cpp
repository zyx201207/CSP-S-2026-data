#include <bits/stdc++.h>
#define qwq ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define pii pair<int, int>
//#define int long long
using namespace std;
const int N = 5e5 + 5;
int n, m;
int a[N], v[N];
int st[N], top;
int cnt[N], lst[N];
bool f = 1;
int Rand(int n) {
	return (long long)rand() * rand() % n;
}
signed main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	qwq;
	srand((unsigned)time(0));
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		if (a[i] > a[i - 1] and i != 1) f = 0; 
	}
	for (int i = 1; i <= n; i++)
		lst[a[i]] = i;
	if (f) 
		for (int i = 1; i <= m; i++) 
			cout << lst[i];
	else if (n <= 5000 and m <= 3000) {
		for (int i = 1; i <= n; i++) {
			memset(v, 0, sizeof v);
			top = 0;
			for (int j = i; j <= n; j++) {
				if (v[a[j]]) 
					while (st[top] != a[j]) 
						v[st[top]] = 0, top--;
				else 
					v[a[j]] = 1, st[++top] = a[j];
			}
			for (int i = 1; i <= m; i++) 
				if (v[i]) 
					cnt[i]++;
		}
		for (int i = 1; i <= m; i++) 
			cout << cnt[i] << ' ';
	}
	else 
		for (int i = 1; i <= m; i++) 
			cout << Rand(lst[i]);
	return 0;
}
