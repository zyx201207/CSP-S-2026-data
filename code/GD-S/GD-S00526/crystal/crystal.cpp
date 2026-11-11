#include <bits/stdc++.h>
using namespace std;
long long a[600005], cnt, n, m, i, j, k, p, jia;
int main (){
	freopen ("crystal.in", "r", stdin);
	freopen ("crystal.out", "w", stdout);
	scanf ("%lld%lld", &n, &m);
	for (i=1; i<=n; i++){
		scanf ("%lld", &a[i]);
	}
	sort (a+1, a+n+1);
	for (i=2; i<=n; i++){
		if (a[i] > a[i-1]){
			jia = a[i] - a[1];
			for (j=1; j<=i-1; j++){
				if (jia > m-cnt) {
					cnt == m;
					j--;
					break;
				}
				a[j] = a[i];
				cnt += jia;
				if (cnt == m) break;
			}
			if (cnt == m) break;
		}
		if (cnt == m) break;
	}
	for (k=i+1; k<=n; k++){
		if (a[k] == a[i]) p++;
		else break;
	}
	printf ("%lld", j+p+1);
	return 0;
}
