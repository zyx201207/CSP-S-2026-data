#include<bits/stdc++.h>
using namespace std;
#define int long long
#define pii pair<int,int>
#define fi first
#define se second
inline int read(){
	int x=0,f=1; char ch=getchar();
	while(!isdigit(ch)){if(ch=='-') f=-1; ch=getchar();}
	while(isdigit(ch)){x=(x<<1)+(x<<3)+(ch^48); ch=getchar();}
	return x*f;
}
void write(int x){
	if(x<0){write(-x); return;}
	if(x>9) write(x/10);
	putchar(x%10+48);
}
const int N=2e6+5;
int c,T;
int n,d;
int x[N];
int f[N],g[N],sum[N];
int ans;
void work(int s){
	for(int i=1;i<=n;i++){
		f[i]=1e18; g[i]=0;
	}
	f[s]=0; g[s]=1;
	int l=s,r=s;
	for(int i=s+1;i<=n;i++){
		while(x[i]-x[l]>d) l++;
		if(l==i) break;
		if(l>r) r=i-1;
		f[i]=f[r]+1; g[i]=g[r]-g[l-1];
		if(f[l]!=f[l-1]) g[i]=g[r];
		if(g[i]==2) ans++;
		g[i]=min(g[i],3ll);
		if(r!=i-1&&f[i]==f[i-1]) g[i]+=g[i-1];
	}
}
void solve(){
	n=read(); d=read(); ans=0;
	for(int i=1;i<=n;i++) x[i]=read();
	int f=1;
	for(int i=3;i<=n;i++) f&=(x[i]-x[i-1]==x[i-1]-x[i-2]);
	if(f){
		int p=d/(x[2]-x[1]);
		if(p==0||p==1){
			puts("0"); return;
		}
		for(int i=1;i<=n;i++){
			if(i+2*p-1<=n) ans++;
		}
		write(ans); puts("");
		return;
	} 
	for(int i=1;i<n;i++) work(i);
	write(ans); puts("");
} 
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	c=read(); T=read();
	while(T--) solve();
	return 0;
}

