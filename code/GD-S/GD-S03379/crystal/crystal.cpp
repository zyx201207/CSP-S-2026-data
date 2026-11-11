#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define endl "\n"
#define Endl "\n",void()
#define End void()
namespace kong{bool st;}
const int N=5*1e5+7;
ll n,a[N],sum[N],ans,m;
void solve(){
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++) sum[i]=sum[i-1]+a[i];
	for(int i=1;i<=n;i++){
		ll l=1,r=i,res=i;
		while(l<=r){
			ll mid=(l+r)/2,tot=sum[i]-sum[mid-1]-(i-mid+1)*a[i]+m;
			if(tot>=0) res=mid,r=mid-1;
			else l=mid+1; 
		}
		ans=max(ans,i-res+1);
	}
	return cout<<ans<<Endl;
}
namespace kong{bool ed;double MB(){return abs(&st-&ed)*1.0/1024/1024;}}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	int _=1;
//	cin>>_;
	while(_--) solve(); 
	cerr<<endl<<kong::MB()<<endl;
	return 0;
} 
