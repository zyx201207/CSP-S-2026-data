#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a[500200];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ll n,m,mv=0,tv=0,ans=1;
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	
	sort(a+1,a+n+1);
	mv=a[1];
	ll i=1;
	for(ll j=1;j<=n;){
	
		if((a[j]-mv)*(j-i)+tv<=m){
			ans=max(ans,j-i+1);	
			tv+=(a[j]-mv)*(j-i);
			mv=a[j];
			j++;
		
		}else{
			
			tv-=mv-a[i];
			i++;
		
		}
	
	}
	printf("%lld",ans);
	return 0;
}
