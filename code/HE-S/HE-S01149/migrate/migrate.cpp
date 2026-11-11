#include <bits/stdc++.h>
using namespace std;

int c, t, n;
long long d, op1, op2, txt, ans;
long long a[2000001];

int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf ("%d%d", &c, &t);
	for (int i = 1; i <= t; i++){
		txt = 0;
		scanf ("%d%lld", &n, &d);
		for (int i = 1; i <= n; i++)
			scanf ("%lld", &a[i]);
		for (int i = 1; i <= n - 3; i++){
			for (int j = i + 3; j <= n; j++){
				txt = 0;
				if (a[j] - a[i] <= d)
					break;
				for (int k = i + 1; k < j; k++){
					op1 = a[k] - a[i];
					op2 = a[j] - a[k];
					if (op1 <= d && op2 <= d)
						txt++;
					printf ("%lld %lld\n", op1, op2);
				}
				if (txt == 2)
					ans++;
			}
		}
		printf ("%lld\n", ans);
	}
	return 0;
}






