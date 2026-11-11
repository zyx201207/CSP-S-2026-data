#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,k;
ll a[5000010];
ll ans;
ll qz[5000010];
ll pf[5000010];
bool cmp(ll a,ll b){
    return a<b;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>k;
	for(ll i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1,cmp);
	ll r=n,l=n-1,cnt=a[n]-a[l];
	while(l>=1){
		ans=max(r-l+1,ans);
		l--;
		cnt=cnt+a[r]-a[l];
		if(cnt>k){
			ll c=r-l+1;
			cnt=cnt-(a[r]-a[r-1])*c;
			r--;
		}
	}
    cout<<ans<<endl;
	return 0;
}
/*
5 5
1 2 4 8 9
*/
