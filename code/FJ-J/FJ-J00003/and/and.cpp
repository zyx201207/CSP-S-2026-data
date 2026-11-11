#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define fi first
#define se second

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> PII;

const int N = 2e5+7, INF = 0x3f3f3f3f, M = 2e5+7;

int n, m;
int a[N];

int main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	int ans = 0;
	for (int j = 30; j >= 0; j--) {
		int mk = (1 << j);
		int att = ans | mk, cnt = 0;
		for (int i = 1; i <= n; i++) {
			if ((a[i] & att) == att) cnt++;
		}
		if (cnt >= m) ans |= mk;
//		if (cnt >= m) ans |= mk, cout << j << " accepted\n";
//		else cout << j << " ignored\n";
	}
	cout << ans << endl;
	return 0;
}

