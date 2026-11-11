#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=5e5+10;
ll n,m,a[N],c[N],f[N],fc[N],maxi=0;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+1+n);
	c[1]=0;f[1]=0;fc[1]=0;
	c[0]=0;f[0]=0;fc[0]=0;
	for(int i=2;i<=n;i++){
		c[i]=a[i]-a[i-1];
		f[i]=f[i-1]+c[i];
		fc[i]=fc[i-1]+f[i];
	}
	for(int i=1;i<=n;i++){
		ll l=1,r=i,ans=i;
		while(l<=r){
			ll mid=(l+r)>>1;
			ll len=i-mid;
			ll k=1ll*len*f[i];
			if(mid!=i)k=k-fc[i-1]+fc[mid-1];
			if(k<=m){
				ans=mid;
				r=mid-1;
			}else l=mid+1;
		}
		int mx=i-ans+1;
		maxi=max(mx*1ll,maxi);
	}
	cout<<maxi;
	return 0;
}

