#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N=200010;
ll n,a[N],c[N],as,u[N],t[N];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%lld",&n);
	for(int i=1;i<=n;i++){
		char d;
		scanf("%lld %c",&a[i],&d);c[i]=d-'a';
		u[i]=a[i]+u[i-1];
	}
	for(int i=n;i>=1;i--)t[i]=t[i+1]+a[i];
	ll j=n+1;
	for(ll i=1;i<=n;i++){
		if(c[i]!=c[j]){
			as+=max(min(t[j],u[i])-u[i-1],0ll);
		}
		while(u[i]>t[j]){
			j--;
			if(j<=i)break;
			if(c[j]!=c[i]){
				if(t[j]<=u[i]){
					as+=a[j];
				}
				else{
					as+=u[i]-t[j+1];
				}
			}
		}
		if(j<=i)break;
	}
	printf("%lld",as);
	return 0;
}
