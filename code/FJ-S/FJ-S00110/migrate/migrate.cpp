#include <cstdio>
#include <vector>
#include <queue>
#include <climits>
#include <algorithm>

using namespace std;
typedef long long ll;
ll n, d;

ll x[2000005];
ll f[5005][5005][3];

void upd(ll i, ll k, ll j) {
	for (ll jj = 2 ; jj >= 0 ; jj --) {
		for (ll kk = 2 ; kk >= 0 ; kk --) {
			for (ll ii = 2 ; ii >= 0 ; ii --) {
				if (f[i][j][ii] > f[i][k][jj] + f[k][j][kk]) {
					if (ii != 2) f[i][j][ii+1] = f[i][j][ii];
					f[i][j][ii] = f[i][k][jj] + f[k][j][kk];
					if (f[i][j][ii] == 0) {
						//putchar('!');
					}
					if (i==5||i==6||j==5||j==6) {
						//putchar('!');
					}
				}
			}
		}
	}
}

struct State {
	ll p, w;
};

void work1() {
	for (int i = 1 ; i <= n ; i ++) {
		for (int j = 1 ; j <= n ; j++) {
			f[i][j][0] = f[i][j][1] =f[i][j][2]= LLONG_MAX / 4;
		}
		//f[i][i][0] = f[i][i][1] = 0;
	}
	for (int i = 1 ; i <= n ; i ++) {
		scanf("%lld", &x[i]);
		for (int j = i-1 ; j > 0 ; j --) {
			if (x[i] - x[j] <= d) {
				//g[i].push_back(j);
				//g[j].push_back(i);
				f[i][j][0]=f[j][i][0] = 1;
			} else {
				break;
			}
		}
	}
	for (int i = 1 ; i <= n ; i ++) {
		for (int j = 1 ; j <= n ; j ++) {
			//printf("%lld,%lld ", f[i][j][0], f[i][j][1]);
		}
		//putchar('\n');
	}
	for (int k = 1 ; k <= n ; k ++) {
		for (int i = 1 ; i <= n ; i ++) {
			for (int j = 1 ; j <= n ; j ++) {
				upd(i, k, j);
			}
		}
	}
	ll cnt = 0;
	for (int i = 1 ; i <= n ; i ++) {
		for (int j = 1 ; j <= n ; j ++) {
			//printf("%lld,%lld,%lld ", f[i][j][0], f[i][j][1], f[i][j][2]);
			if (f[i][j][0] == f[i][j][1] && f[i][j][1] != f[i][j][2] && f[i][j][0] < LLONG_MAX/8 && i != j) cnt++;
			//if (f[i][j][0] == f[i][j][1] && f[i][j][1] != f[i][j][2] && i != j) printf("%lld, %lld: %lld\n", i, j, f[i][j][0]);
		}
		//putchar('\n');
	}
	printf("%lld\n", cnt/2);
}

ll structs[2000005], ptr = 0;

void work2() {
	ptr = 0;
	structs[ptr++] = -2;
	for (int i = 1 ; i <= n ; i ++) {
		scanf("%lld", &x[i]);
		if (i >= 4 && x[i] - x[i-2] <= d && x[i-1] - x[i-3] <= d) {
			structs[ptr++]=i-3;
			//printf("[D] STRUCT %lld\n", i-3);
		}
	}
	structs[ptr] = n;
	ll sum = 0;
	//printf("[D] ptr=%lld", ptr);
	for (int i = 1 ; i < ptr ; i ++) {
		//printf("[D] %lld\n", i);
		sum += max(structs[i] - structs[i-1] - 2, 1ll) * max(1ll, structs[i+1] - structs[i] - 2);
	}
	printf("%lld\n", sum);
}

void work() {
	scanf("%lld%lld", &n, &d);
	if (n <= 5000) work1();
	else work2();
}

int main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	ll c, t;
	scanf("%lld%lld", &c, &t);
	while(t--) work();
	return 0;
}
