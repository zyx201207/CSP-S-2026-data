#include<bits/stdc++.h>
using namespace std;
long long n,m,a[1919810],he,t,l,r,q,ans,ppp,qqq;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);he+=a[i];
	}sort(a+1,a+n+1);
	if(a[1]==a[n]){
		cout<<n;return 0;
	}else if(he+m>=a[n]*n){
		cout<<n;return 0;
	}l=n,r=n,q=m;
	while(r>=1&&l>=1){
		if(a[l]-a[r-1]<=q&&r-1>0){
			r--;q-=a[l]-a[r];
			ans=max(ans,l-r+1);
		}else{
			q+=(a[l]-a[l-1])*(l-r);l--;
		}
	}printf("%lld",ans);
	
	return 0;
}//Oct31==Dec25?