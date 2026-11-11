#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 500005;
int n, ans;
ll m, a[N], sum[N];
int main(){
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	scanf("%d%lld" ,&n ,&m);
	for(int i = 1;i <= n;i++)
		scanf("%lld" ,&a[i]);
	sort(a + 1, a + 1 + n);
	for(int i = 1;i <= n;i++){
		sum[i] = sum[i - 1] + (i - 1) * (a[i] - a[i - 1]);
		if(sum[i] <= m){
			ans = max(ans, i);
			continue;
		}
		int l = 1, r = i;
		while(l <= r){
			int mid = (l + r) >> 1;
			if(sum[i] - sum[mid] - mid * (a[i] - a[mid]) <= m) r = mid - 1;
			else l = mid + 1;
		}
		ans = max(ans, i - r - 1);
	}
	printf("%d" ,ans);
	return 0;
}
