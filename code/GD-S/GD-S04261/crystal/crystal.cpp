#include<bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;
const int N = 500005;
ll a[N];
ll sum[N];
ll ans = -1;
//map<ll,ll> m;
ll anss = -1;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);	cin.tie(0);	cout.tie(0);
	ll n,m;
	cin>>n>>m;
	for(int i = 1; i <= n; i++){
		cin>>a[i];
//		m[a[i]]++;
//		anss = max(anss, m[a[i]]);
	}
	sort(a+1,a+1+n);
	if(m == 0){
		ll cnt = 1;
		for(int i = 2; i <= n; i++){
			if(a[i] == a[i-1]){
				cnt++;
				anss = max(anss,cnt);
			}
			else{
				anss = max(anss,cnt);
				cnt = 1;
			}
		}
		cout<<anss;
		return 0;
	}
	for(int i = 1; i <= n; i++){
		sum[i] = sum[i-1]+a[i];
	}
	ll l = 0;
	ll r = 1;
	while(l <= r && r <= n){
		l++;
		while(r <= n && (a[r]*(r-l+1) - (sum[r] - sum[l-1])) <= m){
			r++; 
		}
		r-=1;
//		cout<<(a[r]*(r-l+1) - (sum[r] - sum[l-1]))<<"  ";
//		cout<<l<<" "<<r<<endl;
		ans = max(ans,r-l+1);
	}
	cout<<ans;
	return 0;
}
/*
5 5
1 2 4 8 9

7 1
1 2 4 5 5 6 7
*/
//676767, i hucked myself tiwce at 5pm.
