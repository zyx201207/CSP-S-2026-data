#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,m,a[1000005],s[1000005],ans;
bool pA,pB;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(ll i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=i) pA=1;
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++) s[i]=s[i-1]+a[i];
	if(n<=5000){
		for(ll i=1;i<=n;i++){
			ll t=m,s=0;
			for(ll j=i;j>=1;j--){
				if(a[j]<=a[i]&&a[i]-a[j]<=t) t-=a[i]-a[j],s++;
				else break;
			}
			ans=max(ans,s);
		}
		cout<<ans;
	}else{
		if(pA==0){
			ll ma=INT_MIN;
			for(int i=0;i<n;i++){
				if((1+i)*i/2<=m) ma=i;
				else break;
			}
			cout<<ma+1;
		}else{
			for(int i=2;i<n;i++){
				if(a[i+1]-a[i]!=a[2]-a[1]) pB=1;
			}
			if(pB==0){
				ll ma=INT_MIN,d=a[2]-a[1];
				for(int i=0;i<n;i++){
					if((d+i*d)*i/2<=m) ma=i;
					else break;
				}
				cout<<ma+1;
			}else{
				ll cnt=0,l=1,r=1;
				while(l<=n&&r<=n&&l<=r){
					if(cnt+(a[r+1]-a[r])*(r-l+1)<=m) cnt+=(a[r+1]-a[r])*(r-l+1),r++,ans=max(ans,r-l+1);
					else{
						l++;
						cnt-=s[r]-s[l-1]-a[l-1];
						ans=max(ans,r-l+1);				
					}
				}
				cout<<ans;
			}
		}
	}

	return 0;
}
