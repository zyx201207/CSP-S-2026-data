#include <bits/stdc++.h>
using namespace std;
#define int long long
int a[500005], b[500005], cost[500005], ans[500005], sum;
signed main(){
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n, m;
	cin >> n >> m;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
	}
	sort(a + 1, a + n + 1);
	cost[1] = 0;
	ans[1] = 1;
	sum = 1;
	for(int i = 2; i <= n; i++){
		if(cost[i - 1] + ans[i - 1] * (a[i] - a[i - 1]) <= m){
			cost[i] = cost[i - 1] + ans[i - 1] * (a[i] - a[i - 1]);
			ans[i] = ans[i - 1] + 1;
		}
		else{
			int costt, anss;
			costt = cost[i - 1];
			anss = ans[i - 1];
			while(anss > 1){
				costt -= a[i - 1] - a[i - anss];
				anss--;
				if(costt + anss * (a[i] - a[i - 1]) <= m){
					break;
				}
			}
			if(costt + anss * (a[i] - a[i - 1]) <= m){
				cost[i] = costt + anss * (a[i] - a[i - 1]);
				ans[i] = anss + 1;
			}
			else{
				cost[i] = 0;
				ans[i] = 1;
			}
		}
		sum = max(ans[i], sum);
	}
	cout << sum;
	return 0;
}
