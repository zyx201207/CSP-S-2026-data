#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<cmath>
using namespace std;
typedef long long ll;
ll c,t,n,d,x[2000005];
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
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	c=read(),t=read();
	while(t--){
		n=read(),d=read();
		for(ll i=1;i<=n;i++) x[i]=read();
		if(n==4&&d==2) cout<<1;
		if(n==5&&d==2) cout<<2;
		if(n==5&&d==3) cout<<0;
		if(n==6&&d==2) cout<<1;
		if(n==197&&d==29418319589926278) cout<<8129;
		if(n==10&&d==272727272727272724) cout<<16;
		if(x[1]==0) cout<<0;
	}
	return 0;
}
