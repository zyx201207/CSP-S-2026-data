#include<bits/stdc++.h>
#define fi first
#define se second
using namespace std;
using la2 = array<long long, 2>;
using pic = pair<la2, char>;
int n, _a[200001], l;
char c[200001], now[3];
long long sum, _sum, ans;
pic a[200010];
bool f;
int main(){
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	scanf("%d", &n);
	for(int i = 1; i <= n; i++){
		scanf("%d", &_a[i]);
		cin >> c[i];
		sum += _a[i];
	}
	for(int i = 1; i <= n; i++){
		_sum += _a[i];
		if(f){
			a[++l] = {{sum - _sum + 1, 2ll}, c[i]};
		}
		else if(_sum >= (sum + 1) / 2){
			f = true;
			if(_sum - _a[i] + 1 < sum / 2 + 1)a[++l] = {{_sum - _a[i] + 1, 1ll}, c[i]};
			if(_sum > (sum + 1) / 2)a[++l] = {{sum - _sum + 1, 2ll}, c[i]};
		}
		else{
			a[++l] = {{_sum - _a[i] + 1, 1ll}, c[i]};
		}
	}
	a[++l] = {{sum / 2 + 1, 1ll}, '.'};
	a[++l] = {{(sum + 1) / 2, 2ll}, '.'};
	sort(a + 1, a + l + 1);
//	for(int i = 1; i <= l; i++)printf("%lld %lld %c\n", a[i].fi[0], a[i].fi[1], a[i].se);
	now[1] = a[1].se, now[2] = a[2].se;
	for(int i = 3; i <= l; i++){
		ans += (now[1] != now[2]) * (a[i].fi[0] - a[i - 1].fi[0]);
		now[a[i].fi[1]] = a[i].se;
	}
	printf("%lld", ans);
	return 0;
}
