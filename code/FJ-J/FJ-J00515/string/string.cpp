#include<bits/stdc++.h> 
using namespace std;

const int N = 2 * 1e5 + 1;
long long a[N];
int b[N];
int n;

int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		char c;
		scanf("%lld %c", &a[i], &c);
		b[i] = c - 'a' + 1;
	}
	long long ans = 0;
	int i = 1, j = n;
	while (i < j) {		
		if (a[i] == 0)
			i++;
		if (a[j] == 0)
			j--;
		if (a[i] > a[j]) {
			if (b[i] != b[j]) {
				ans += a[i] - a[j];
				a[i] -= a[j], a[j] = 0;
			}
		}
		else if (a[j] > a[i]){
			if (b[i] != b[j]) {
				ans += a[j] - a[i];
				a[j] -= a[i], a[i] = 0;
			}
		}
		else {
			if (b[i] != b[j]) {
				ans += a[i];
				a[i] = 0, a[j] = 0;
			}
		}
		if (b[i] == b[j]) {
			if (a[i] >= a[j])
				a[i] -= a[j], a[j] = 0;
			else
				a[j] -= a[i], a[i] = 0;
		}
    }
	printf("%lld\n", ans);
	return 0;
}





