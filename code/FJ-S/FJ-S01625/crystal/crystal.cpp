#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N=5e5+5;
ll n,m,a[N],ans=1,sum[N],l,d;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	} 
	for(int i=1;i<=n;i++){
		sum[i]=sum[i-1]+a[i];
	} 
	sort(a+1,a+n+1);
	for(ll r=2;r<=n;r++){
	    d=(r-l)*a[r]-sum[r]+sum[l];
		while(m<d&&l<r){
		    ++l;
		    d-=a[r]-a[l];
		}
	    ans=max(ans,r-l);
	} 
	printf("%lld\n",ans);
	return 0;
} 
