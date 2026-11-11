#include<bits/stdc++.h>
#define ll long long
const int N=2e5+999; 
using namespace std;
struct dada{
	ll a,b;
}a[N];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ll t=1;
	//scanf("%lld",&t);
	while(t--){
		ll n;
		scanf("%lld",&n);
		ll len=0;
		for(ll i=1;i<=n;i++){
			scanf("%lld",&a[i].a);
			char c;
			cin>>c;
			a[i].b=(ll)(c-'a');
			len+=a[i].a;
		}
		ll i=1,j=n,leni=0,lenj=0,sur=0,c=-1,ans=0;
		while(i<=j){
			if(leni<lenj){
				sur=leni;
				leni+=a[i].a;
				i++;
			}else if(leni>lenj){
				sur=lenj;
				lenj+=a[j].a;
				j--;
			}else{
				sur=leni;
				leni+=a[i].a,lenj+=a[j].a;
				i++,j--;
			}
			if(a[i-1].b==a[j+1].b){
				continue;
			}else {
				ans+=min(leni-sur,lenj-sur);
			}
		}
		printf("%lld",ans);
	}
	return 0;
}
