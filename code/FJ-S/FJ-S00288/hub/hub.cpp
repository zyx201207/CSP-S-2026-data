#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
#define ll long long
#define il inline
#define re register int
#define rl register ll
#define gc getchar
using namespace std;
const int MN=1e5+5;
ll n,k,ans,head[MN],fa[MN],tot;
struct edge{ll to,nxt;}e[MN<<1];
il ll read(){ll x=0,f=1;char ch=gc();while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=gc();}while(ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+(ch^48);ch=gc();}return x*f;}
il void write(rl x){if(x<0){putchar('-');write(-x);return;}if(x>9)write(x/10);putchar(x%10+'0');}
il void add(rl u, rl v){e[++tot]={v,head[u]};head[u]=tot;}
il ll find(rl x){return x==fa[x]?x:fa[x]=find(fa[x]);}
il void solve(){
	n=read();k=read();
	for(re i=1; i<n; ++i){ll u=read(),v=read();}
	if(k&1)--n;n=(n+1)/2;
	write((n-k+3)/4+1);putchar('\n');
}
il void solve1(){
	tot=0;for(re i=1; i<=n; ++i) head[i]=0;
	n=read();k=read();ans=n/k-1;
	for(re i=1; i<=n; ++i) fa[i]=i;
	for(re i=1; i<n; ++i){ll u=read(),v=read();}
	write(ans);putchar('\n');
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ll cid=read(),T=read();
	if(cid<=3){while(T--)solve1();return 0;}
	while(T--)solve();
	return 0;
}//261031

