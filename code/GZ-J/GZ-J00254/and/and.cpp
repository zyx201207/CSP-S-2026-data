//GZ-J00254 遵义市新蒲新区白鹭湖小学 韩定远
#include <bits/stdc++.h>
using namespace std;
const int N = 2 * 1e5 + 5;
long long a[N];
long long n, m, maxn = LLONG_MIN, sum = 0;
priority_queue<long long> q;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	scanf("%lld%lld", &n, &m);
	for (long long i = 1; i <= n; i++){
		scanf("%lld", &a[i]);
		maxn = max(maxn, a[i]);
	}
	if (m == 1){
		printf("%lld", maxn);
		return 0;
	} 
	if (maxn == 4){
		printf("%d", 0);
	}
	else if (m == n){
		sum = a[1];
		for (long long i = 1; i <= n; i++){
			sum &= a[i];
		}
		printf("%lld", sum);
		return 0;
	}
	if (m == 2){
		maxn = LLONG_MIN;
		for (long long i = 1; i <= n; i++){
			for (long long j = i + 1; j <= m; j++){
				maxn = max(maxn, (a[i]&a[j]));
			}
		}
		printf("%lld", maxn);
		return 0;
	}
	for (long long i = 1; i <= n; i++){
		q.push(a[i]);
	}
	while (m){
		long long x = q.top();
		q.pop();
		long long y = q.top();
		q.pop();
		q.push((x & y));
		m--;
	}
	printf("%lld", q.top());
	return 0;
	fclose(stdin);
	fclose(stdout);
}
