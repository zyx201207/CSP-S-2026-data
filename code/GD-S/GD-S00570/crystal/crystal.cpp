#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e5+1;
ll n,m,cnt; 
ll a[N],sum[N];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(ll i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(ll i=2;i<=n;i++){
		ll t=a[i]-a[i-1];
		sum[i]=t*(i-1)+sum[i-1];
	}
	for(ll len=n;len>=1;len--){
		for(ll i=1;i+len-1<=n;i++){	
			ll j=i+len-1;
			if(sum[j]-sum[i]>m)continue;
			cnt=max(len,cnt);
			cout<<cnt;return 0;
		}
	}
	cout<<cnt;
	return 0;
}

