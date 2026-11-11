#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll N = 5e5+10;
ll n,m,a[N],d[N],ans=1,minn=1e13,maxn = -1e13,sum;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >> m;
	for (ll i =1;i <= n;i++){
		cin >> a[i];
		minn = min(a[i],minn);
		maxn = max(a[i],maxn);
	}
	sort(a+1ll,a+n+1ll);
	ll l = 1,r = 2;
	while (l<=r&&r <= n){
		sum = 0;
		for (ll i =1;i <= r-1;i++){
			sum = (a[i+l] - a[i+l-1]) * i + sum;
		}
		if (sum <= m){
			ans = max(ans,r - l+1);
			r++;
		}else{
			l++;
		}
	}
	cout << ans;
	return 0;
}
