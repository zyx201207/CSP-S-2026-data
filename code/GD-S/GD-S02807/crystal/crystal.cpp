#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=5e5+5;
ll a[N],d[N],s[N];
ll ans=-1;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ll n,m; scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	sort(a+1,a+1+n);
	for(int i=2;i<=n;i++){
		d[i]=a[i]-a[i-1];
		s[i]=s[i-1]+(ll)(i-1)*d[i];
	}
	ll l=1,r=1;
	for(;l<=n;l++){
		for(;r<=n;r++){
			if(s[r]-s[l]>m){
				ans=max(ans,r-l);
				break;
			}
		}
	}
	printf("%lld",ans);
	
	
	return 0;
}
