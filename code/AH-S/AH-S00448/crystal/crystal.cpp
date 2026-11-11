#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=5e5+10;
ll n,m;
ll s[N],mx;
ll sum[N];

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(ll i=1;i<=n;i++){
		 scanf("%lld",&s[i]);
		 sum[i]=sum[i-1]+s[i];
	}
	sort(s+1,s+1+n);
	if(n<=5000){
		for(ll i=1;i<=n;i++){
			ll ans=0,temp=0;
			for(ll j=1;j<=i-1;j++){
				 ans+=s[i]-s[j];
				 if(ans>m) break;
				 temp++;
			}
			mx=max(mx,temp+1);
		}
		cout<<mx;
	}else{
		for(ll i=1;i<=n;i++){
			ll temp=(i-1)*s[i];
			for(ll j=i-1;j>=1;j--){
				if(temp-sum[j]<=m){
					mx=max(mx,j);
					break;
				}
				temp-=s[i];
			}
		}
		cout<<mx;
	//}
	return 0; 
}
