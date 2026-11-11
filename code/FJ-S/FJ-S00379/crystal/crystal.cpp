#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=5e5+10;
ll n,m,a[N],sum[N],ans;
inline ll read(){
	ll x=0,f=1;
	char ch=getchar();
	while(ch<'0' || ch>'9'){
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while(ch>='0' && ch<='9'){
		x=(x<<1)+(x<<3)+(ch^48);
		ch=getchar();
	}
	return x*f;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);	
	n=read(); m=read();
	for(ll i=1;i<=n;i++) a[i]=read();
	sort(a+1,a+n+1);
	for(ll i=1;i<=n;i++) sum[i]=sum[i-1]+a[i];
	for(ll i=1;i<=n;i++){
		ll l=1,r=i,d=0;
		while(l<=r){
			ll mid=(l+r)/2;
			ll tmp=a[i]*(i-mid+1)-(sum[i]-sum[mid-1]);
			if(tmp<=m) d=mid,r=mid-1;
			else l=mid+1;
		}
		ans=max(ans,i-d+1);
	} 
	cout<<ans;
	return 0;
}
