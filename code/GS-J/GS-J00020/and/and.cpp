#include <bits/stdc++.h>
using namespace std;

int n, m;
int a[200010] = {0};

bool cmp(int x, int y) { return x > y; }

int main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	cin >> n >> m;
	for (int i = 0; i < n; i++) cin >> a[i];
	sort(a, a + n, cmp);
	cout << a[m - 1] << endl;
	
	return 0;
}
