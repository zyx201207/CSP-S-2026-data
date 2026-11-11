// 45 pts
#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 5e5 + 5;
int n, m, a[N], ans;
signed main(){
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	scanf("%lld %lld", &n, &m);
	for(int i = 1;i <= n;i++) scanf("%lld", a + i);
	sort(a + 1, a + n + 1);
	for(int i = 1;i <= n;i++){
		int tmp = m, res = 0;
		for(int j = 1;j <= i;j++){
			if((a[i] - a[j]) <= tmp){
				tmp -= (a[i] - a[j]);
				res++;
			}
			else break;
		}
		ans = max(ans, res);
	}
	cout << ans;
	return 0;
}
