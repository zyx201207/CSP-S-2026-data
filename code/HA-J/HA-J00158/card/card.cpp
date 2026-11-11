#include<bits/stdc++.h>
using namespace std;
int a[500010];
int x[300010];
int t[300010];
int main () {
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin >> n >> m;
	for (int i = 1;i <= n;i++) {
		cin >> a[i];
	}
	for (int i = 1;i <= n;i++) {
		for (int j = 1;j <= m;j++) t[j] = 0;
		for (int j = i;j <= n;j++) {
			t[a[j]]++;
		}
		for (int j = 1;j <= m;j++) {
			if (t[j] % 2 != 0 && t[j] != 0) x[j]++;
		}
	}
	for (int i = 1;i <= m;i++) {
		if (i != 1) cout << " ";
		cout << x[i];
	}
	return 0;
}
