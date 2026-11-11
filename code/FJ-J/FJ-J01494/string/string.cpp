#include<bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 2e5 + 5;
ll n, a[N], len = 0, mid, cnt = 0, x;
char c[N];
string s;

int main(){
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i] >> c[i];
		len += a[i];
	}
	if (n % 2 == 0) mid = n / 2;
	else mid = n / 2 + 1;
	x = n;
	for (int i = 1; i <= mid; i++) {
		if (c[i] != c[x]) {
			if (a[i] == a[x]) {
				cnt += a[i];
				a[i] = 0;
				a[x] = 0;
				x--;
			}
			int num = min(a[i], a[x]);
			if (num == a[x]) {
				ll sum = 0;
				for (int j = x; j >= 1; j--) {
					if (a[i] - a[j] >= 0) a[i] -= a[j], sum += a[j];
					else {
						x = j;
						break;
					}
				}
				a[x] -= a[i];
				cnt += sum + a[i];
				a[i] = 0;
				continue;
			}
			cnt += num;
			a[x] -= num;
		}
	}
	cout << cnt;
	return 0;
}

