#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
int n, m;
int a[N];
int main() {
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	cout << a[3] << " " << a[6] << a[7] << a[n];
	return 0;
}
