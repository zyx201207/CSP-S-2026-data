#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll read(){
	ll x=0ll,f=1ll;
	char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-')f*=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		x*=10;
		x+=(ch-'0');
		ch=getchar();
	}
	return x*f;
}
ll c,t,n,d;
ll a[2001000];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	c=read();t=read();
	while(t--){
		n=read();d=read();
		for(int i=1;i<=n;i++){
			a[i]=read();
		}
	}
	return 0;
}
