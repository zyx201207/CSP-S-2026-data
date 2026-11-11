#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
int n, m, ans, maxn;
int a[N];
bool cmp(int a, int b) {
	return a > b;
}
int main() {
	freopen("and","r",stdin);
	freopen("ans","w",stdout);
	cin >> n >> m;
	for (int i = 1;i <= n;i ++) {
		cin >> a[i];
	}
	sort(a + 1, a+ n +1, cmp);
	ans = a[1]; 
	for (int i = 2;i <=n;i ++) {
		maxn = max(maxn, ans & a[i]);
	}
	cout << maxn;
	return 0;
}
