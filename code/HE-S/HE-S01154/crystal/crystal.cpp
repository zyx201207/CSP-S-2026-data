#include<bits/stdc++.h>
using namespace std;
const int N = 5e5 + 10;
long long a[N], s[N];
long long n, m;
void init(){
	for(int i = 1; i <= n; i++) s[i] = s[i - 1] + a[i];
	return;
}
long long sum(int l, int r){
	return s[r] - s[l - 1];
}
bool check(int x){
	bool flag = false;
	for(int i = x; i <= n; i++){
		if(a[i] * (x - 1) - sum(i - x + 1, i - 1) <= m){
			flag = true;
			break;
		}
	}
	return flag;
}
int main(){
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	scanf("%lld%lld", &n, &m);
	for(int i = 1; i <= n; i++) scanf("%lld", &a[i]);
	sort(a + 1, a + n + 1);
	init();
	long long l = 1, r = n, mid;
	while(l < r){
		mid = (l + r) / 2 + 1;
		if(check(mid)) l = mid;
		else r = mid - 1;
	}
	printf("%lld", l);
	return 0;
}
