#include<bits/stdc++.h>
using namespace std;
#define maxn 2000005
#define ll long long
#define frp freopen
#define fio(in,out) frp(in,"r",stdin),frp(out,"w",stdout)
void bug(){cout<<endl;}
template<typename T,typename ... Ts>
void bug(T x,Ts ... y){cout<<x<<" ",bug(y...);}
template<typename T=int>
T read(){
	T res=0,f=1;char c;
	for(;(c=getchar())<'0'||c>'9';c=='-'?f=-f:0);
	while(c>='0'&&c<='9')res=(res<<3)+(res<<1)+c-'0',c=getchar();
	return res*f;
}
int n,V,f[4],g[4],F[maxn][65],to[maxn];
ll d,x[maxn],ans;
int encode(int *f){
	int i,ret=0;
	for(i=0;i<3;++i)ret+=(f[i]<<(2*i));
	return ret;
}
void decode(int x,int *f){
	int i;
	for(i=0;i<3;++i)f[i]=(x>>(2*i))&3;
}
int main(){
	fio("migrate.in","migrate.out");
	read();
	int i,j,k,S,T=read();
	while(T--){
		n=read(),d=read<ll>();ans=0;
		for(i=1;i<=n;++i){
			x[i]=read<ll>();
			memset(F[i],0,sizeof(F[i]));
		}
		int l=1;
		for(i=1;i<=n;++i){
			while(l<=i&&x[i]-x[l]>d)++l;
			to[i]=l;
		}
		for(i=1;i<=n;++i){
			int p=to[i],lst=i;
			for(S=0;S<64;++S){
				decode(S,f);
				memset(g,0,sizeof(g));
				int a,b;
				for(k=p,b=0;k<=min(i-1,p+2);++k,++b)
					for(j=i,a=0;j<=min(n,i+2);++j,++a)
						if(x[j]-x[k]<=d)g[b]+=f[a];
				for(k=0;k<3;++k)g[k]=min(g[k],3);
				int w=0; 
				if(f[0]==1&&f[1]==1){
					w=to[i+2]-to[i+1];
				}
				if(f[0]==2&&g[0]==2)w=to[i+1]-to[i];
				F[i][S]=F[to[i]][encode(g)]+w;
//				bug("!",i,S,F[i][S]);
			}
			memset(f,0,sizeof(f));
			for(j=to[i],k=0;j<=min(i-1,to[i]+2);++j,++k)f[k]=1;
//			bug("#",i,k,encode(f));
			ans+=F[to[i]][encode(f)];
		}
		printf("%lld\n",ans);
	}
	return 0;
}

