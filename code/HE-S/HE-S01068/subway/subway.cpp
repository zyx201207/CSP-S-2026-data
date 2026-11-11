#include<bits/stdc++.h>
#define ll long long
#define gc getchar
using namespace std;
int read(){
	int x=0,f=1; char c=gc();
	while(c<'0' or c>'9') { if(c=='-') f=-1; c=gc(); }
	while(c>='0' and c<='9') { x=x*10+c-'0'; c=gc(); }
	return x*f;
}
const ll asd=5e5+1;
const ll qwe=25;
ll c,n,m,d,q,val[asd]={};
ll tt[asd][qwe]={};
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	c=read(); n=read(); m=read(); d=read(); q=read();
	for(ll i=1;i<=m;i++) val[i]=read();
	for(ll i=1,k=0;i<=n;i++){
		k=read();
		for(ll j=1,a,t;j<=k;j++){
			a=read(); t=read();
		}
	}
}
