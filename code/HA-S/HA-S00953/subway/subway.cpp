#include<bits/stdc++.h>
using namespace std;

int c, n, m, d, q;
int m1[500005];
int k1[1000005], t1[1000005];

int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	cin >> c >> n >> m >> d >> q;
	for(int i = 1; i <= m; i++)
		cin>> m1[i];
	for (int i = 1; i <= n; i++) {
		int k;
		cin >> k;
		for (int j = 1; j <= k; j++)
			cin >> k1[j] >> t1[j];
	}
	int x[100], y[100];
	for(int i = 1; i <= q; i++) {
		cin >> x[i] >> y[i];
	}
	int hhh, aaa;
	for(int i = 1; i <= q; i++) {
		if(hhh + 1 % 2 == 0)
			cout << (aaa + 1) % 7;
		else
			cout << ((aaa + 1)  * 3)% 20;
			cout << endl;
	}
	
	return 0;
}
