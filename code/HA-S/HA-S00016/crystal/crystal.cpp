#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
long long n, a[500005];
long long m;
int main(){
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	scanf("%lld%lld", &n, &m);
	for(int i = 1;i <= n;i++){
		scanf("%lld", &a[i]);
	}
	unsigned long long ans = 0;
	sort(a + 1, a + n + 1);
	for(unsigned long long i = 1;i <= n;i++){
		unsigned long long x = m, cnt = 0, now = 0;
		for(unsigned long long j = i - 1;j < n;j++){
			if(x >= (abs(a[j + 1] - now * 1ull) * (j - i + 1))){
//				cout << x << ' ';
				cnt++;
				x -= (a[j + 1] - now * 1ull) * (j - i + 1);
				now = a[j + 1];
//				cout << x << ' ';
//				cout << i << ' ' << j << '\n';
			}
		}
		ans = max(ans, cnt);
	}
	printf("%llu", ans);
	return 0;
}
