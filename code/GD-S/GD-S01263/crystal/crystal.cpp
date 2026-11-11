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
int File=file(crystal);
int n=read();
ll m=read();
ll a[500005];
signed main(){
	nf()a[i]=read();
	sort(a+1,a+n+1);
	ll L=1,val=0,prev=-1e12;
	ll ans=1;
	nf(){
		val+=(a[i]-prev)*(i-L);
		while(val>m){
			val-=a[i]-a[L++];
		}
		ans=max(ans,i-L+1);
		prev=a[i];
	}
	write(ans);
}
