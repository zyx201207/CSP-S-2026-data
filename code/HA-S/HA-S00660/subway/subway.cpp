#include<bits/stdc++.h>
using namespace std;
#define intt long long
namespace IO{
	inline intt read(){
		intt x=0,f=1;char ch=getchar();
		for(;ch<'0'||ch>'9';ch=getchar())if(ch=='-')f=-1;
		for(;ch>='0'&&ch<='9';ch=getchar())x=(x<<3)+(x<<1)+ch-'0';
		return x*f;
	}
	inline void write(intt x){
		if(x<0)putchar('-'),x=-x;
		if(x>9)write(x/10);
		putchar(x%10+'0');return;
	}
	inline void print(intt x,bool fl=1){
		write(x);if(fl)putchar('\n');
		else putchar(' ');return;
	}
}using namespace IO;
namespace Code{
	#define For(i,a,b) for(int i=(a);i<=(b);i++)
	#define Rep(i,a,b) for(int i=(a);i>=(b);i--)
	#define pb push_back
	#define mk make_pair
	typedef pair<intt,intt>PII;
	typedef vector<intt>Vntt;
	const intt N=510,M=5e5+10;
	intt A[M];
	intt f[N][N];
	vector<PII>pre[M];
	inline void main(){
		intt c=read(),n=read(),m=read(),d=read(),q=read();
		For(i,1,m)A[i]=read();
		For(i,1,n){
			intt k=read();
			For(j,1,k){
				intt x=read(),y=read();
				pre[x].pb(mk(i,y));
			}
		}
		memset(f,0x3f,sizeof(f));
		For(i,1,n)f[i][i]=0;
		For(i,1,m){
			for(PII x:pre[i]){
				for(PII y:pre[i]){
					intt u=x.first,v=y.first;
					if(u==v)continue;
					f[u][v]=min(f[u][v],x.second+y.second);
				}
			}
		}
		For(k,1,n)For(i,1,n)For(j,1,n){
			f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
		}
		while(q--){
			intt x=read(),y=read();
			intt Ans=1e18;
			for(PII u:pre[x])for(PII v:pre[y]){
				Ans=min(Ans,u.second+f[u.first][v.first]+v.second);
			}
			print(Ans+A[x]+A[y]);
		}
		return;
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	Code::main();
	return 0;
}

