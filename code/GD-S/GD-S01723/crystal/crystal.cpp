#include<bits/stdc++.h>
#define ll long long
#define pll pair<ll, ll> 
using namespace std;

ll n,m, a[500100], ans = 1;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	
	cin>>n>>m;
	for(int i=1;i<=n;++i){
		cin>>a[i];
	}
	
	sort(a+1, a+1+n);
	
	ll L = 1, sum = 0;
	for(ll i=2;i<=n;++i){
//		cout<<i<<' '<<sum<<'\n';
		sum += (i-L)*(a[i]-a[i-1]);
//		cout<<sum<<'\n';
		while(sum > m){
			sum -= a[i]-a[L];
//			cout<<"#"<<a[i]-a[L]<<' '<<sum<<'\n';
			++L;
		}
		ans = max(ans, i-L+1);
	}
	cout<<ans;
	
	
	
	return 0;
} 
