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
int File=file(subway);
int CID=read();
int n=read(),m=read(),d=read(),q=read();
basic_string<int>p[500005],val[500005];
int w[500005];
ll dis[505][505];
int N[500005];
signed main(){
	memset(dis,0x3f,sizeof dis);
	tf(m)w[i]=read();
	nf()dis[i][i]=0;
	nf(){
		int c=read();
		while(c--){
			int x=read(),d=read();
			p[x]+=i;val[x]+=d;
		}
	}
	tf(m){
		N[i]=p[i].size();
		for(int a=0;a<N[i];a++){
			for(int b=a+1;b<N[i];b++){
				dis[p[i][a]][p[i][b]]=dis[p[i][b]][p[i][a]]=min(dis[p[i][a]][p[i][b]],(ll)val[i][a]+val[i][b]);
			}
		}
	}
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
			}
		}
	}
	tf(q){
		int x=read(),y=read();
		ll ans=1e18;
		for(int a=0;a<N[x];a++){
			for(int b=0;b<N[y];b++){
				ans=min(ans,val[x][a]+val[y][b]+dis[p[x][a]][p[y][b]]);
			}
		}
		write(ans+w[x]+w[y]);putchar(10);
	}
}
