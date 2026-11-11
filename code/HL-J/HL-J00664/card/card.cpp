#include<bits/stdc++.h>

using namespace std;
const int N = 3e5 + 5;
long long a[N], b[N];
pair<long long, long long> c[N];

int main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	long long n, m;
	cin >> n >> m;
	for(int i = 1; i <= n; i ++) {
		cin >> a[i];
	}
	for(int i = 1; i <= m; i ++) {
		long long cnt = 0;

		for(int k = 1; k <= n; k ++) {
			long long y = 0;

			for(int j = k, r = 1; j <= n; j ++, r ++) {

				if(!c[a[j]].second) c[a[j]].second = 1, c[a[j]].first = r, b[++ y] = a[j];
				else {

					int u = y;
					for(int g = c[a[j]].first; g <= u; g ++) {

						c[b[g]].second = 0;
						c[b[g]].first = 0;
						b[g] = 0;
						y --;

					}
					b[++ y] = a[j];
					c[a[j]].first = r;
					c[a[j]].second = 1;
				}

			}

			for(int s = 1; s <= y; s ++) {
				if(b[s] == i) {
					cnt ++;
					break;
				}
			}

			memset(b, 0, sizeof(b));
			memset(c, 0, sizeof(c));

		}

		cout << cnt << " ";
	}
	return 0;
}
