#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=510;
const int M=5e5+10;
struct node{
	int x;
	ll y;
};
int cid,n,m,d,q,w[M];
ll f[N][N];
vector<node> g[M];
inline ll read(){
	ll x=0;
	int f=1;
	char ch=getchar();
	while(ch<'0' || ch>'9'){
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while(ch>='0' && ch<='9') x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
	return x*f;
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cid=read(),n=read(),m=read(),d=read(),q=read();
	for(int i=1;i<=m;i++) w[i]=read();
	for(int i=1,k;i<=n;i++){
		k=read();
		for(int j=1;j<=k;j++) g[read()].push_back({i,read()});
	}
	memset(f,0x3f,sizeof f);
	for(int i=1;i<=m;i++)
		for(node xx:g[i])
			for(node yy:g[i]){
				if(xx.x==yy.x) continue;
				f[xx.x][yy.x]=f[yy.x][xx.x]=min(f[xx.x][yy.x],xx.y+yy.y);
			}
	for(int i=1;i<=n;i++) f[i][i]=0;
	for(int k=1;k<=n;k++)
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				if(i!=j && i!=k && j!=k)
					f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
	while(q--){
		int x,y;
		ll ans=1e18;
		x=read(),y=read();
		for(node xx:g[x])
			for(node yy:g[y])
				ans=min(ans,f[xx.x][yy.x]+xx.y+yy.y);
		printf("%lld\n",ans+w[x]+w[y]);
	}
	return 0;
}
