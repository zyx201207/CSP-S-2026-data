#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 50;
int n , m;
long long a[N];
bool cmp(long long x , long long y) {
	return x >= y;
}
int main() {
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >> n >> m;
	for(int i = 1 ; i <= n ; i++) {
		cin >> a[i];
	}
	sort(a+1,a+n+1,cmp);
	for(int i = 1 ; i <= n ; i++) cout << a[i] << '\n';
	long long ans = a[1];
	for(int i = 2 ; i <= m ; i++) {
		cout << ans << ' ';
		ans &= a[i];
	}
	cout << ans;
	return 0;
}
