#include <bits/stdc++.h>
using namespace std;
const int N = 200011;

int n, a [N], l, r;
string c [N];
long long sum = 0;

int main(){
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) cin >> a [i] >> c [i];
	l = 1, r = n;
	while (l < r) {
		if (c [l] == c [r]) {
			if (a [l] == a [r])
				l++, r--;
			else if (a [l] < a [r])
				a [r] -= a [l], l++;
			else
				a [l] -= a [r], r--;
		}
		else {
			if (a [l] < a [r])
				sum += a [l], a [r] -= a [l], l++;
			else
				sum += a [r], a [l] -= a [r], r--;
		}
	}
	printf("%lld", sum);
	return 0;
}
