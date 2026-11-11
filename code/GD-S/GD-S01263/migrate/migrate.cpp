#include<bits/stdc++.h>
using namespace std;
#define ll long long  
#define oF(l,r,i) for(int i=l;i<=r;i++) 
#define of(l,r) for(int i=l;i<=r;i++) 
#define tF(n,i) oF(1,n,i)
#define tf(n) oF(1,n,i)
#define nF(i) oF(1,n,i)
#define nf() oF(1,n,i)
#define fin(x) freopen(#x".in","r",stdin)
#define fout(x) freopen(#x".out","w",stdout)
#define file(x) (fin(x),fout(x),0)
inline ll read(){
	ll x=0;
	short f=1;
	char c=getchar();
	while(c<48||c>57){
		if(c==45)f=-1;
		c=getchar();
	}
	while(c>=48&&c<=57){
		x=(x<<1)+(x<<3)+(c^48);
		c=getchar();
	}
	return f*x;
}
void write(ll x){
	if(x<0)x=~x+1,putchar(45);
	if(x>9)write(x/10);
	putchar(x%10|48);
}
int File=file(migrate);
int CID=read(),T=read();
ll a[2000005];
int nxt[2000005],pre[2000005];
int f[2000005],g[2000005];
int df[2000005],dg[2000005];
signed main(){
	while(T--){
		int n=read();
		ll d=read();
		nf()a[i]=read();
		nxt[n]=n;
		for(int i=n-1;i;i--){
			nxt[i]=nxt[i+1];
			while(a[nxt[i]]-a[i]>d)nxt[i]--;
		}
		pre[1]=1;
		for(int i=2;i<=n;i++){
			pre[i]=pre[i-1];
			while(a[i]-a[pre[i]]>d)pre[i]++;
		}
		ll ans=0;
		nf()df[i]=f[i]=0;
		nf(){
			int r=nxt[i],_r=nxt[i-1];
			if(r^i){
				f[r]++;df[r]++;
				if(_r<r)f[r]+=f[i];
				if(_r<r-1)df[r]+=f[i];
			}
		}
		nf()dg[i]=g[i]=0;
		for(int i=n;i;i--){
			int p=pre[i],_p=pre[i+1];
			if(p^i){
				g[p]++;dg[p]++;
				if(_p>p)g[p]+=g[i];
				if(_p>p+1)dg[p]+=g[i];
			}
		}
		for(int i=1;i<n;i++){if(nxt[i]!=i+1&&pre[i+1]!=i)ans+=(ll)dg[i]*df[i+1];}
		write(ans);putchar(10);
	}
}
