#include <bits/stdc++.h>
using namespace std;
const int MAX = 1e6;
long long m, a[MAX], b[MAX];
int n, ans;

int main(){
	freopen ("crystal.in", "r", stdin);
	freopen ("crystal.out", "w", stdout);
	scanf ("%d%lld", &n, &m);
	for (int i = 1; i <= n; i++){
		scanf ("%lld", &a[i]);
	}
	sort (a + 1, a + 1 + n);
	for (int i = 2; i <= n; i++){
		b[i] = (i - 1) * (a[i] - a[i - 1]) + b[i - 1];
	}
	int j = 1;
	for (int i = 1; i <= n; i++){
		long long temp = b[i] - b[j] - ((a[i] - a[j]) * (j - 1));
		while (temp > m){
			temp = b[i] - b[j] - ((a[i] - a[j]) * (j - 1));
			j++;
		}
		ans = max (ans, i - j + 1);
	}
	printf ("%d\n", ans);
	return 0;
}

