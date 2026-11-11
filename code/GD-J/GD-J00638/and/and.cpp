#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 2e5 + 5;
ll n,m,r,maxn,ans;
ll a[N],qian[N];
bool check(int x){
	ll sum = 0,cnt = 0;
	for(ll i = 1;i <= n;i++){
		if(cnt == 0){
			sum = a[i];
			cnt++;
			continue;
		}if(cnt == m){
			maxn = max(maxn,sum);
			sum = 0;
			cnt = 0;
		}
		sum &= a[i];
		cnt++;
	}
	return maxn == x;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin >> n >> m;
	for(ll i = 1;i <= n;i++){
		cin >> a[i];
	}
	for(ll i = 1;i <= n;i++){
		for(ll j = i + 1;j <= n;j++){
			r = max(r,a[i] & a[j]); 
		}
	}
	ll l = 0;
	while(l <= r){
		ll mid = (l + r) >> 1;
		if(check(mid)){
			ans = mid;
			l = mid + 1;
		}else r = mid - 1;
	}
	cout << ans;
	return 0;
}
