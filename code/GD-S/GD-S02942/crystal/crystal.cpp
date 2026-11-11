#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const ll N=5e5+10;
ll n,m;
ll a[N],b[N];
ll check(ll x){//目标值为x,小于等于m次操作最多可以让多少个数字等于x 
    ll sum=0,cnt=0;//记录当前操作次数和相等数字个数 
    for(ll i=1;i<=n;i++) b[i]=0;//初始化 
    for(ll i=1;i<=n;i++){
    	b[i]=abs(x-a[i]);//保存每一个数的差值 
	}
	sort(b+1,b+1+n);//差值小的放在前面，可以保证最多数字相等 
	for(ll i=1;i<=n;i++){
		if(sum+b[i]<=m){
			sum+=b[i];
			cnt++;
		}else{
			return cnt;
		}
	}
	return cnt;
}
int main(){
    freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	ll mx=0,mi=0x3f3f3f3f;
	for(ll i=1;i<=n;i++){
		cin>>a[i];
		mx=max(mx,a[i]);
		mi=min(mi,a[i]);
	}
	ll l=mi,r=mx;
	ll ans=0;
	//使所有值为mid 
	while(l<=r){
		ll mid=(l+r)/2;
		if(check(mid)>=ans){
		    r=mid-1;
			ans=max(ans,check(mid));
		}else{
			l=mid+1;
		}
	}
	//cout<<check(3);
	cout<<ans;
	return 0;
} 
