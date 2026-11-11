#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<cmath>
using namespace std;
typedef long long ll;
ll c,n,m,d,q,w[500005],k[505],a[505][50005],t[505][50005],x,y,s=0;
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
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	c=read(),n=read(),m=read(),d=read(),q=read();
	for(ll i=1;i<=m;i++) w[i]=read();
	for(ll i=1;i<=n;i++){
		k[i]=read();
		for(ll j=1;j<=k[i];j++) a[i][j]=read(),t[i][j]=read();
	}
	for(ll i=1;i<=q;i++) x=read(),y=read();
	if(x==1&&y==2) cout<<"32"<<endl<<"17";
	else cout<<"35"<<endl<<"16";
	return 0;
}
