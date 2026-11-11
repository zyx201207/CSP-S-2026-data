#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	ll n,m;
	cin >> n >> m;
	vector < ll > u(n + 1),pre(n + 1);
	for(int i = 1;i <= n;i++){
		cin >> u[i];
	}
	
	sort(u.begin() + 1,u.end());
	
	for(int i = 1;i <= n;i++)pre[i] = pre[i - 1] + u[i];
	
	int l = 1,r = 1;
	int ans = 0;
	while(r <= n){
		ll val = (r - l + 1) * u[r] - (pre[r]- pre[l - 1]);
		if(val <= m){
			ans = max(ans,r - l + 1);
			r++;	
		}
		else l++;
		
	}
	cout << ans;
	return 0;
}
