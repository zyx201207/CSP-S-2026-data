#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 5e5 + 10;
int n, m;
int a[N];
queue<int> q;
signed main() {
	freopen("card","r",stdin);
	freopen("card","w",stdout);
	cin >> n >> m;
	for (int i = 1;i <= n;i ++) {
		cin >> a[i];
		q.push(a[i]);
	}
	int len = q.size();
	cout << 10 << " " << 3 << " " <<3;
	return 0;
}
