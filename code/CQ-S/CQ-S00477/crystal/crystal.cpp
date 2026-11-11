#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n, m, a[500005], sum[500005];
int main(){
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w" , stdout);
	cin >> n >> m;
	for(int i = 1; i <= n; ++i) cin >> a[i];
	sort(a + 1, a + n + 1);
	for(int i = 1; i <= n; ++i) sum[i] = sum[i - 1] + a[i];
	int ans = 1, wei = 1;
	for(int i = 2; i <= n;){
		ll js = 1;
		js = (i - wei) * a[i] - sum[i - 1] + sum[wei - 1];
		if(js <= m) {ans = i - wei + 1;i++;continue;}
		else{
			if(i - wei <= ans) i ++;
			else wei ++;
		}
	}
	cout << ans;
	return 0;
}

