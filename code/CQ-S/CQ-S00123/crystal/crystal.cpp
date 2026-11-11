#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+10;
int n, m, a[N], ans;
signed main(){
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	
	cin >>n >>m;
	for(int i=1; i<=n; i++)
		cin >>a[i];
	sort(a+1, a+n+1);
	for(int i=1, j=1, cost=0; i<=n; i++){
		cost += (i-j) * (a[i] - a[i-1]);
		while(cost > m)
			j ++, cost -= a[i] - a[j];
		ans = max(ans, i - j + 1);
	}
	cout <<ans <<endl;
	return 0;
}

