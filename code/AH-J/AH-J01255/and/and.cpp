#include<bits/stdc++.h>
using namespace std;
const int N = 2e5+10;
int n, m;
int a[N];
int main() {
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
	}
	cout << a[n] << endl;
	return 0;
}
