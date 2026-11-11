#include<bits/stdc++.h>
#define ll long long
#define gc getchar
using namespace std;
ll read(){
	ll x=0,f=1; char c=gc();
	while(c<'0' or c>'9') { if(c=='-') f=-1; c=gc(); }
	while(c>='0' and c<='9') { x=x*10+c-'0'; c=gc(); }
	return x*f;
}
const ll asd=2e6+90;
ll c,t,n,d,a[asd]={};
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	c=read(); t=read();
	while(t--){
		ll sum=0,detla=0;
		n=read(); d=read();
		for(ll i=1;i<=n;i++){
			a[i]=read();
			if(i!=1) if(a[i]-a[i-1]==a[2]-a[1]) sum++,detla=a[2]-a[1]; 
		}
		if(sum==n-1){
			if(d<=detla or (a[n])/(d/2)<=3) cout<<0<<"\n";
			else cout<<((a[n])/(d/2)-3)+1<<"\n";
			continue;
		}
	}
}
