#include<bits/stdc++.h>
using namespace std;
#define N 2000005
typedef long long ll;
inline ll read(){
	register ll x=0,f=1ll;char ch=getchar();
	while(!isdigit(ch)){if (ch=='-')f=-1;ch=getchar();}
	while(isdigit(ch)){x=(x<<3ll)+(x<<1ll)+(ch^48);ch=getchar();}
	return x*f;
}
int C,T;
ll n,d;
ll p[N],c[N],nxt[N];
inline void solve(){
	n=read();d=read();
	for(int i=1;i<=n;i++)p[i]=read();
	ll delta=p[2]-p[1];
	ll x=d/delta;
	if (x==0||(n-x*2+1<=0)||d>=(p[n]-p[1])||d<delta*2)cout<<0<<'\n';
	else cout<<n-x*2+1<<'\n';
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	C=read();T=read();
	while(T--)solve();
	return 0;
}
