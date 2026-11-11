#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n, a[500005], m, sum[500005];
int maxn;
bool check(int len){
	for(int i = len; i <= n; ++i){
		if(len*a[i]-sum[i]+sum[i-len] <= m){
			return 1;
		}
	}
	return 0;
}
int main(){
	cin.tie(nullptr)->sync_with_stdio(0);
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for(int i = 1; i <= n; ++i){
		cin >> a[i];
	} 
	sort(a+1, a+n+1);
	for(int i = 1; i <= n; ++i){
		sum[i] = sum[i-1] + a[i];
	}
	int l = 1, r = n, ans;
	while(l <= r){
		int mid = l+r>>1;
		if(check(mid)){
			l = mid+1;
			ans = mid;
		}else r = mid-1;
	}
	cout << ans;
}
