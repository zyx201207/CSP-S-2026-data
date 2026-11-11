#include<algorithm>
#include<cstdio>
using namespace std;
using ll = long long;
constexpr int N = 5e5 + 5;
ll a[N], sum[N];
ll calc(int l, int i)noexcept{
	return a[i] * (i - l) - (sum[i - 1] - sum[l - 1]);
}
int main(){
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	int n; ll m;scanf("%d%lld", &n, &m);
	for(int i = 1;i <= n;i++){
		scanf("%lld", a + i);
	}
	sort(a + 1, a + n + 1);
	for(int i = 1;i <= n;i++)sum[i] = sum[i - 1] + a[i];
	int ans = 0;
	for(int i = 1;i <= n;i++){
		int _l = 0, _r = i - 1, _mid, res = 0;
		while(_l <= _r){
			_mid = (_l + _r) >> 1;
			if(calc(i - _mid, i) <= m)_l = _mid + 1, res = _mid;
			else _r = _mid - 1;
		}
		ans = max(ans, res + 1);
	}
	printf("%d", ans);
	return 0;
}
/*
5 5
1 2 4 8 9

5 8
-3 -1 2 2 7
*/
