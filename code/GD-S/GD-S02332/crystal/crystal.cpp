#include<bits/stdc++.h>
using namespace std;
using ll=long long;
ll n,m,a[500010];
bool check(ll x){
	for(int i=1;i<=n;i++){
		ll cnt=1,sum=0;
		for(int j=i+1;j<=n;j++){
			sum+=a[i]-a[j];
			if(sum<=m)cnt++;
			else break;
			if(cnt==x)return true;
		}
	}return false;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}sort(a+1,a+n+1,greater<ll>());
	ll l=0,r=n,pos;
	while(l<=r){
		ll mid=(l+r)/2;
		if(check(mid)){
			l=mid+1;
			pos=mid;
		}else r=mid-1;
	}cout<<pos;
	return 0;
}
