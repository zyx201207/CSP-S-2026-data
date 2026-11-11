#include <bits/stdc++.h>

using namespace std;

const int N = 2000010;

int c, T, n, v[N];
long long d, a[N], f[N];

int main(){
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	scanf("%d%d", &c, &T);
	if (c <= 10){
		while (T--){
			int ans = 0;
			scanf("%d%lld", &n, &d);
			for (int i = 1; i <= n; i++)
				scanf("%lld", &a[i]);
			for (int i = 1; i <= n; i++){
				for (int j = i; j <= n; j++)
					f[j] = 0, v[j] = 1 << 30;
				f[i] = 1, v[i] = 0;
				for (int j = i; j <= n; j++)
					for (int k = j + 1; k <= n && a[k] - a[j] <= d; k++)
						if (v[k] > v[j] + 1)
							f[k] = f[j], v[k] = v[j] + 1;
						else
							if (v[k] == v[j] + 1)
								f[k] += f[j];
				for (int j = i; j <= n; j++)
					if (f[j] == 2)
						++ans;
			}
			printf("%d\n", ans);
		}
	}
	else
		if (c <= 12){
			while (T--){
				scanf("%d%lld", &n, &d);
				for (int i = 1; i <= n; i++)
					scanf("%lld", &a[i]);
				if (n < 4)
					printf("0\n");
				else{
					long long k = a[n] - a[n - 1];
					k = d / k;
					k = k * 2 - 1;
					if (k > 1)
						printf("%d\n", max(0LL, n - k));
					else
						printf("0\n");
				}
			}
		}
	return 0;
}