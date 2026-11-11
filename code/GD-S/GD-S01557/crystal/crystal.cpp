#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll a[500005];
ll n,m;
bool check(ll mid){
	ll sum=1e18;
	for(ll i=mid;i<=n;i++){
		ll sum1=0;
		for(ll j=1;j<=mid-1;j++){
			sum1+=a[i]-a[i-j];
		}
		sum=min(sum1,sum);
	}
	return sum<=m;
}
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>m;
    a[0]=0;
    ll ca=0;bool flag=1;
    for(int i=1;i<=n;i++){
    	cin>>a[i];
    	ll k=a[i]-a[i-1];
    	if(i<=2)ca=k;
    	else if(ca!=k&&flag)flag=0;
	}
	sort(a+1,a+n+1);
	if(flag==true){
	    ll cnt=0;
	    for(int i=n;i>=2&&m>=0;i--){
	        cnt++;
		    m-=a[i]-a[i-1];
		    a[i-1]=a[i];
	    }
	    cout<<cnt;
	    return 0;
    }
	ll l=1,r=n,ans=0;
	while(l<=r){
		ll mid=l+(r-l)/2;
		if(check(mid)){
			l=mid+1;
			ans=mid;
		}else{
			r=mid-1;
		}
	}
	cout<<ans;
    return 0;
}
//8 7 5 1 0
//1 2 4 1
/*



*/
//21 13 6 1 0
//6:4+2*1
//13:4*2+2+3*1
//21:4*3+2*2+4*1+1
