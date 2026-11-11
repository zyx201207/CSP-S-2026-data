#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll t,n,a[200010];
char c[200010];
void try64(){
	string s;
	for(ll i=1;i<=n;i++){
		while(a[i]--) s+=c[i];
	}	
	ll ans=0;
	for(ll i=0;i<ll(s.size()/2);i++){
		if(s[i]!=s[s.size()-i-1]) ans++;
	}	
	printf("%lld",ans);
}	
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%lld",&t);
	for(ll i=1;i<=t;i++) scanf("%lld %c",&a[i],&c[i]);
	n=0;	
	c[t+1]=' ';
	ll sum=0;
	for(ll i=1;i<=t;i++){
		sum+=a[i];
		if(c[i]!=c[i+1]){
			a[++n]=sum;
			c[n]=c[i];
			sum=0;
		}
	}
	for(ll i=1;i<=n;i++) scanf("%lld %c",&a[i],&c[i]);
	if(n==1) printf("0");
	else if(n==2){
		if(c[1]==c[2]) printf("0");
		else printf("%lld",min(a[1],a[2]));
	}
	else try64();
	return 0;
}
