#include <bits/stdc++.h>
using namespace std;

long long n, m, a[500005], qian[500005], ans;

bool cmp(long long aa, long long bb){
	return aa < bb;
}

int main(){
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	scanf("%lld %lld", &n, &m);
	for (long long i = 1; i <= n; i++){
		scanf("%lld", &a[i]);
	}
	sort(a+1, a+1+n, cmp);
	for (long long i = 1; i <= n; i++){
		qian[i] = qian[i-1]+a[i];
	}
	bool flag = 0;
	for (long long i = 2; i <= n; i++){
		if (flag){
			break;
		}
		for (long long j = i; j <= n; j++){
			if (a[j]*i-(qian[j]-qian[j-i]) <= m){
				ans = i;
				break;
			}
			else if(j == n){
				flag = 1;
			}
		}
	}
	printf("%lld", ans);
	return 0;
}
