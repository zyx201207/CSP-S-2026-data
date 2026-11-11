/*
*/ 
#include<bits/stdc++.h>
#define qwe(i,l,r) for(int i=(l);(i)<=(r);++i)
#define ewq(i,l,r) for(int i=(l);(i)>=(r);--i)
#define qwex(e,x) for(int e=(x);e;e=ne[e])
#define ll long long
#define int ll
#define pii pair<int,int>
#define fir first
#define sec second
#define low(x) (x)&(-(x))
#define whlie while
using namespace std;
inline int read(){
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){
		f=ch=='-'?-f:f;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		x=(x<<3)+(x<<1)+(ch^48);
		ch=getchar();
	}
	return f*x;
}
const int N=5e5+5,M=505;
int n,m;
int f[M][M],a[N];
int b[N][22],t[N][22];
int d[N];
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	read(); n=read();m=read();read();int q=read();
	qwe(i,1,m)a[i]=read();
	qwe(i,1,n){
		int len=read();
		qwe(j,1,len){
			int x=read();
			++d[x];
			b[x][d[x]]=i;
			t[x][d[x]]=read();
		}
	}
	qwe(i,1,n)qwe(j,1,n)if(i!=j)f[i][j]=1e18;
	qwe(x,1,m){
		qwe(i,1,d[x]){
			qwe(j,i+1,d[x]){
				int u=b[x][i],v=b[x][j];
				f[v][u]=f[u][v]=min(f[u][v],t[x][i]+t[x][j]);
			}
		}
	}
	qwe(k,1,n){
		qwe(i,1,n){
			qwe(j,1,n){
				f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
			}
		}
	}
//	qwe(i,1,n){
//		qwe(j,1,n)cout<<f[i][j]<<' ';
//		cout<<'\n';
//	}
	while(q--){
		int x=read(),y=read(),ans=2e18;
		qwe(i,1,d[x]){
			qwe(j,1,d[y]){
				ans=min(ans,f[b[x][i]][b[y][j]]+t[x][i]+t[y][j]);
			}
		}
//		if(x==2&&y==3){
//			cout<<d[x]<<' '<<d[y]<<'\n';
//		}
		cout<<ans+a[x]+a[y]<<'\n';
	}
}
