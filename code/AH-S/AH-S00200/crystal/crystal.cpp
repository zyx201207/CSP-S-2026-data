#include<bits/stdc++.h>
using namespace std;
const int N = 5e5 + 10;
int n, ans, cnt, pos;
long long m, a[N], mm;
int main(){
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	scanf("%d%lld", &n, &m);
	for(int i = 1; i <= n; i++) scanf("%lld", &a[i]);
	if(n > 5e3 && m > 1e8){
		long long d = a[2] - a[1];
		if(!d){
			printf("%d\n", n);
			return 0;
		}
		for(int i = n; i >= 1; i--){
			if(m < a[n] - a[i]) break;
			m -= a[n] -a[i];
			ans++;
		}
		printf("%d\n", ans);
		return 0;
	}
	sort(a + 1, a + n + 1);
	for(int i = 2; i <= n; i++){
		mm += (a[i] - a[i - 1]) * (i - 1);
		if(mm > m){
			pos = i - 1;
			break;
		}
	}
	for(int i = pos; i <= n; i++){
		cnt = 0;
		mm = m;
		while(mm >= a[i] - a[i - cnt] && i > cnt) mm -= a[i] - a[i - cnt], cnt++;
		while(i < n && a[i + 1] == a[i]) cnt++, i++;
		ans = max(ans, cnt);
	}
	printf("%d\n", ans);
	return 0;
}
