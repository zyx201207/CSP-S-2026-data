#include<bits/stdc++.h>
using namespace std;
const int MAXN=1e7;
using ll=long long;
ll n,m;
ll a[1200000];
ll cnt[1200000];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
       cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		cnt[i]=cnt[i-1]+a[i];
	}
	ll ans=0;
	for(int i=1;i<=n;i++){
		if(a[i]==a[i+1])continue;
		ll l=1,r=i;
		while(l<=r){
			ll mid=(l+r)/2;
			ll zz=cnt[i]-cnt[mid-1];
			ll need=(i-mid+1)*a[i]-zz;
			//cout<<i<<" "<<mid<<" "<<need<<endl;
			if(need<=m)r=mid-1,ans=max(ans,i-mid+1);
			else l=mid+1;
		}
    }
	 cout<<ans;
    return 0;
}
//Oct31==Dec25?
