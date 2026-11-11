#include <bits/stdc++.h>
using namespace std;
long long n, m, a[500001], ans;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false),cin.tie(0);
	cin >> n >> m;
	for(int i = 1; i <= n; i++) cin >> a[i];
	sort(a+1,a+1+n);
	long long l = 1, r = 1;
	while(r < n){
		if(m < (a[r+1]-a[r])*(r-l+1)){
			ans = max(ans,r-l+1);
			m += a[r] - a[l++];
		}else{
			m -= (a[r+1]-a[r])*(r-l+1);
			r++;
		}
	}
	cout << ans;
	return 0;
}
