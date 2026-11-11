#include<bits/stdc++.h>
using namespace std;
template<typename T>
inline void read(T &x){
	x=0;
	int f=1;
	char ch=getchar();
	while(!isdigit(ch)){
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while(isdigit(ch)) x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
	x*=f;
	return;
}
template<typename T>
inline void write(T x){
	if(x<0) x=-x,putchar('-');
	if(x>9) write(x/10);
	putchar('0'+x%10);
}
#define fi first
#define se second
#define chkmin(x,y) (x=min(x,y))
#define chkmax(x,y) (x=max(x,y))
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> PII;
typedef pair<ll,int> PLI;
const int N=2e6+5;
int n,nxt[N],pre[N],f[N],g[N];
ll d,x[N],sl[N],sr[N];
void solve(){
	read(n),read(d);
	for(int i=1;i<=n;++i) read(x[i]);
	for(int i=1;i<=n+1;++i) pre[i]=nxt[i]=0;
	for(int i=1,r=1;i<=n;++i){
		while(r<n&&x[r+1]-x[i]<=d) ++r;
		nxt[i]=r;
	}
	for(int i=n,l=n;i>=1;--i){
		while(l>1&&x[i]-x[l-1]<=d) --l;
		pre[i]=l;
	}
	for(int i=1;i<=n+1;++i) sl[i]=sr[i]=f[i]=g[i]=0;
	for(int i=1,p=1;i<=n;++i)
		while(p<=n&&nxt[p]==i){
			if(pre[i]==p) f[i]+=f[p];
			++f[i],++p;
		}
	for(int i=n,p=n;i>=1;--i){
		while(p>=1&&pre[p]==i){
			if(nxt[i]==p) g[i]+=g[p];
			++g[i],--p;
		}
	}		
	ll ans=0;
	for(int i=1,p=1;i<=n;++i)
		while(p<=n&&nxt[p]==i){
			if(p<i-1){
				if(pre[i-1]!=p) ++sl[i];
				else sl[i]+=f[p]+1;	
			}
			++p; 
		}
	for(int i=n,p=n;i>=1;--i)
		while(p>=1&&pre[p]==i){
			if(p>i+1){
				if(nxt[i+1]!=p) ++sr[i];
				else sr[i]+=g[p]+1;	
			}
			--p; 
		}
	sl[1]=sr[n]=0;
	for(int i=1;i<n;++i) ans+=1ll*sl[i+1]*sr[i];
	write(ans);
	putchar('\n');
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c=1,T=1;
	read(c),read(T);
	while(T--) solve();
	return 0;
} 
