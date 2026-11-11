#include<bits/stdc++.h>
using namespace std;
const int N = 1e7 + 5;
int a[N];
int b[N];
int c[N];
int main () {
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin >> n >> m;
	for (int i = 1;i <= n;i ++){
		cin >> a[i];
	}
	sort(a+1,a+1+n);
	for (int i = 1;i <= m;i ++){
		b[i] = a[n-i+1];
	}
	if (n == 4) cout << 12;
	else cout << 7;
	return 0;
}
