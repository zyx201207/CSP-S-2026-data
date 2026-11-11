#include<bits/stdc++.h>
#define ll long long
using namespace std;
//constexpr int N=1e5+5;
int c,t;
inline ll read(){
	ll x=0,y=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-') y=-1LL;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		x=x*10LL+(c-'0');
		c=getchar();
	}
	return x*y;
}
inline void write(ll x){
	if(x<0){
		putchar('-');
		x=-x;
	}
	if(x>=10) write(x/10);
	putchar(x%10+'0');
}
int main(){
//	freopen("subway4.in","r",stdin);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	c=read(); t=read();
	while(t--){
		int n=0;
		ll d=0;
		n=read(); d=read();
		vector<ll>a(n+5);
		for(int i=1;i<=n;i++){
			a[i]=read();
		}
		write(ceil(n/4.0));
		printf("\n");
	}
	return 0;
}

