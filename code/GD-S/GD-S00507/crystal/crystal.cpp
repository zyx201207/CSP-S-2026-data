#include <bits/stdc++.h>
using namespace std;
long long n,m,a[500010],dis[500010],pre[500010];
long long ans = 0;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i ++) cin >> a[i];
	sort(a+1, a+n+1);
	for (int i = 1; i <= n; i ++){
		dis[n-i+1] = a[i] - a[i-1];
	}
	for (int i = 1; i <= n; i ++){
		pre[i] = pre[i-1] + dis[i];
	}
	for (int i = 1; i <= n; i ++){
		long long maxn = 0;
		for (int j = i; j <= n; j ++){
			maxn += (pre[j] - pre[i-1]);
			if (m < maxn) {
				if (ans < (j-i)){
					ans = j-i;
					break;
				}
				break;
			}
		}
	}
	cout << ans+1;
}
