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
const ll asd=5e5+50;
ll new_n=1;
ll n,m,a[asd]={},detla[asd]={},last=1,ans=0;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	n=read(); m=read();
	for(ll i=1;i<=n;i++)  a[i]=read();
	sort(a+1,a+n+1);
	for(ll i=2;i<=n;i++){
		detla[i]=(a[i]-a[i-1])*(i-1)+detla[i-1];
	}
	for(ll i=2,tmp=0,num=0;i<=n;i++){
		for(ll j=1;j<=i;j++){
			if((detla[i]-detla[j])/j<=m){
				tmp=i-j+1;
				if(tmp>ans) ans=tmp;
			}
		}
	}
	cout<<ans;
	return 0;
} 
