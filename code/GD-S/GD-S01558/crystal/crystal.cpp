#include<bits/stdc++.h>
using namespace std;
const int maxn=5e5+5;
#define ll long long
ll n,m,a[maxn],s[maxn],res=0;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(ll i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
//	cout<<a[1]<<' '<<a[n]<<endl;
	for(int i=1;i<=n;i++)s[i]=s[i-1]+a[i];
//	cout<<s[n]<<' '<<a[n]*n<<endl;
	for(ll i=1;i<=n;i++){
		ll l=1,r=i,ans=i;
		while(l<=r){
			ll mid=(l+r)>>1;
			int k=1ll*a[i]*(i-mid+1)-(s[i]-s[mid-1]);
//			cout<<k<<'\n';
			if(k<=m)r=mid-1,ans=mid;
			else l=mid+1;
		}
		res=max(res,i-ans+1);
//		cout<<i<<' '<<ans<<endl;
	}
	cout<<res<<endl;
	return 0;
}
