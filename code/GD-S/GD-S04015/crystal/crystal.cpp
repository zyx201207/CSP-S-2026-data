#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,m,a[500005],s[500005],ans;
bool check(ll x){
	return m>=s[x];
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin>>n>>m;
    for(ll i=1;i<=n;i++){
    	cin>>a[i];
	}
	sort(a+1,a+n+1);
	s[1]=0;
	for(ll i=2;i<=n;i++){
		s[i]=s[i-1]+(i-1)*(a[i]-a[i-1]);
	}
	ll l=0,r=n+1;
	while(r-l>1){
	    ll mid=(l+r)>>1;
	    if(check(mid)){
		    ans=mid;
		    l=mid;
	    }else r=mid;
	}
	cout<<ans;
	return 0;
}
