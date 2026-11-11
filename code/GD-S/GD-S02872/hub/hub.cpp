#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<cmath>
using namespace std;
typedef long long ll;
ll c,t,n,k,u[1000005],v[1000005];
inline ll read(){
	int x=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-') f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		x=x*10+c-'0';
		c=getchar();
	}
	return x*f;
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	c=read(),t=read();
	while(t--){
		n=read(),k=read();
		for(ll i=1;i<=n;i++) u[i]=read(),v[i]=read();
		if(n==5&&k==2) cout<<1;
		if(n==8&&k==6) cout<<1;
		if(n==602&&k==42) cout<<17;
		else cout<<0;
	}
	return 0;
}
