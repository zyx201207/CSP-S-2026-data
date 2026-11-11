#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 5e5 + 10;
int n,m;
int ans[N],a[N],b[N];
set<int> s;
signed main() {
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		b[i] = a[i];
	}
	sort(a+1,a+1+n);
	int mid,cnt = 0;
	if(n % 2 == 0) mid = n/2;
	else mid = (n+1)/2;
	int x = a[mid],sum = 0;
	for (int i = 1; i <= mid; i++) {
		m -= x-b[i];
		b[i] = x;
		cnt ++;
		while (m < 0) {
			cnt--;
			b[i] = a[i];
		}
	}
	for (int i = 1; i <= n; i++) {
		s.insert(b[i]);
	}
	cout << n - (s.size() - 1);
	return 0;
}
//Oct31==Dec25?
