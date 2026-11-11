#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 5;
struct f{
	int ans;
	int ci;
}a[N];
int n, m, cnt;
bool cmp(f x, f y) {
	return x.ans > y.ans;
}
bool cmp1(f x, f y) {
	return x.ci < y.ci;
}
int main() {
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >> m;
	for(int i = 1; i <= n; i++)cin >> a[i].ans;
	sort(a+1,a+n+1,cmp);
	int x = a[(n+1)/2].ans;
	for(int i = 1; i <= n; i++) {
		a[i].ci = abs(x-a[i].ans);
	}
	sort(a+1,a+n+1,cmp1);
	for(int i = 1; i <= n; i++) {
		if(m <= 0)break;
		m -= a[i].ci;
		cnt++;
	}
	cout << cnt;
	return 0;
}
