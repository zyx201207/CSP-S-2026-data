#include<bits/stdc++.h>
const int QWQ=5e5+5;
using namespace std;
using LL=long long;
const LL inf=1e18;
template<typename T=int>
inline T read(){
	T x=0; int f=1; char ch=getchar();
	for (;ch<'0'||ch>'9';ch=getchar())
		if (ch=='-') f=-1;
	for (;ch>='0'&&ch<='9';ch=getchar())
		x=(x<<1)+(x<<3)+(ch^48);
	return x*f;
}
int Tp,n,m,d,q,tu[QWQ]; LL f[505][505];
int p[QWQ][22],wp[QWQ][22],cp[QWQ];
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	Tp=read(),n=read(),m=read(),d=read(),q=read();
	for (int i=1;i<=m;i++) tu[i]=read();
	for (int i=1;i<=n;i++){
		int k=read();
		for (int j=1;j<=k;j++){
			int x=read(),t=read();
			p[x][++cp[x]]=i,wp[x][cp[x]]=t;
		}
	}
	for (int i=1;i<=n;i++)
	for (int j=1;j<=n;j++) f[i][j]=i==j ? 0:inf;
	for (int i=1;i<=m;i++)
	for (int j=1;j<=cp[i];j++)
	for (int k=j+1;k<=cp[i];k++){
		int u=p[i][j],v=p[i][k];
		f[u][v]=min(f[u][v],(LL)wp[i][j]+wp[i][k]);
		f[v][u]=min(f[v][u],(LL)wp[i][j]+wp[i][k]);
	}
	for (int k=1;k<=n;k++)
	for (int i=1;i<=n;i++)
	for (int j=1;j<=n;j++)
		f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
	for (int i=1;i<=q;i++){
		int x=read(),y=read(); LL ans=inf;
		if (x==y){ puts("0"); continue; }
		for (int j=1;j<=cp[x];j++)
		for (int k=1;k<=cp[y];k++)
			ans=min(ans,f[p[x][j]][p[y][k]]+wp[x][j]+wp[y][k]);
		printf("%lld\n",ans+tu[x]+tu[y]);
	}
	return 0;
}
