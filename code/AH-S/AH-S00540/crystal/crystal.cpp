#include <bits/stdc++.h>
using namespace std;
using ll=long long;
ll a[500005];
bool cmp(ll x,ll y){
	return x>y;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ll n,m;
	bool f=1;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(i>2 && a[i]-a[i-1]!=a[i-1]-a[i-2]) f=0;
	}
	if(f){
		sort(a+1,a+n+1);
		ll sum=a[2]-a[1];
		for(int i=1;i<=n;i++){
			m-=(i-1)*sum;
			if(m<0){
				cout<<i-1;
				break;
			}else if(m==0){
				cout<<i;
				break;
			}
		}
		return 0;
	}
	sort(a+1,a+n+1,cmp);
	ll mx=LONG_MIN;
	for(int i=1;i<=n;i++){
		ll ans=0,need=0;
		for(int j=i;j<=n;j++){
			need+=(a[i]-a[j]);
			if(need>m) break;
			ans++;
		}
		mx=max(mx,ans);
	}
	cout<<mx;
	return 0;
}
