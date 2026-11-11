#include<bits/stdc++.h>
#define ll long long
using namespace std;

const int N = 5e5 + 5;

ll a[N];
ll sum[N];

int main(){
	
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	
	ll n,m;
	cin >> n >> m;
	
	for(int i = 1; i <= n; i++){
		cin >> a[i];
	}
	
	sort(a+1,a+n+1);
	
	for(int i = 1; i <= n; i++){
		sum[i] = sum[i-1] + a[i];
	}
	
	ll ans = 0;
	for(ll i = 1; i <= n; i++){
		
		ll l = 1,r = i;
		while(l < r){
			ll mid = (l+r) >> 1;
			
			ll num = sum[i-1] - sum[mid-1];
			ll now = a[i] * (i-mid);
			
			if(now-num <= m){
				r = mid;
			} else{
				l = mid+1;
			}
		}
		
		if(l == i){
			//cout << "ha?";
			continue;
		} else{
			ans = max(ans , (i-l+1));
		}
		
	}
	cout << ans;
	
	return 0;
}
