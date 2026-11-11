#include <bits/stdc++.h>
using namespace std;
int n, m;
int a[1000005];
int main(){
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	cin >> n >> m;
	int mx = -1e9;
	for(int i = 1;i <= n;i ++){
		cin >> a[i];
		mx = max(mx, a[i]);
	}
	cout << mx;
	return 0;
}
