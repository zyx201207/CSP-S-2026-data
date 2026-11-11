#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5*1e5+10;
ll n,a[N],cf[N],m,ans,sm[N],ha[N];
ll fen(ll x){
	ll l=1,r=x,mid,res;
	while(l<=r){
		mid=(l+r)/2;
		if(ha[mid]>m)
			l=mid+1;
		else{
			r=mid-1;
			res=mid;
		}
	}
	return res;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(ll i=1;i<=n;i++)
		scanf("%lld",&a[i]);
	sort(a+1,a+n+1);
	for(ll i=n;i>=1;i--){
		cf[i]=a[i]-a[i-1];
		sm[i]=cf[i]+sm[i+1];
		ha[i]=sm[i]+ha[i+1];
	}
	for(ll i=n;i>=2;i--){
		ans=max(i-fen(i)+2,ans);
		for(ll j=1;j<=i;j++)
			ha[j]-=(i-j+1)*ha[i];
	}
	printf("%lld",ans);
	return 0;
} 
