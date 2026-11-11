#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 5e5 + 5;
int n,ans;
ll m,sum,a[N];
bool check(int x){
	ll cnt = 0,ls = 0;
	int ip = upper_bound(a,a + n,sum) - a;
	if(a[ip] != sum) ip--;
	for(int i = ip; i >= 1; i--){
		if(cnt >= m) break;
		if(cnt - a[i] + sum <= m){
			cnt = cnt - a[i] + sum;
			ls++;
		}else break;
	}
	return ls >= x;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(int i = 1; i <= n; i++)
		cin>>a[i];
	sort(a + 1,a + 1 + n);
	sum = (a[1] + a[n]) / 2;
	ll l = 1,r = n;
	while(l <= r){
		ll mid = l + ((r - l) >> 1);
		if(check(mid)){
			l = mid + 1;
			ans = mid;
		}else r = mid - 1;
	}
	cout<<ans<<'\n';
	return 0;
}
