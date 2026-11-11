#include <bits/stdc++.h>
#define N 505
#define M 500005
#define D 25
#define ll long long
#define fi first
#define se second
using namespace std;
int n,c,m,d,q,x,y,k,cnt[M],a[M];
pair<int,int> b[M][D];
ll g[N][N],ans;
inline void read(int &x){
	x=0;
	char ch=getchar();
	while(ch>57||ch<48) ch=getchar();
	while(ch>=48&&ch<=57){
		x=x*10+(ch^48);
		ch=getchar();
	}
}
void write(ll x){
	if(x>9) write(x/10);
	putchar((x%10)^48);
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	memset(g,0x3f,sizeof(g));
	read(c),read(n),read(m),read(d),read(q);
	for(int i=1;i<=m;i++) read(a[i]);
	for(int i=1;i<=n;i++){
		read(k);
		for(int j=1;j<=k;j++){
			read(x),read(y);
			b[x][++cnt[x]]={i,y};
		}
	}
	for(int i=1;i<=m;i++) for(int j=1;j<=cnt[i];j++) for(int k=1;k<=cnt[i];k++) if(j!=k) 
		g[b[i][j].fi][b[i][k].fi]=min(g[b[i][j].fi][b[i][k].fi],(ll)b[i][j].se+b[i][k].se);
	for(int i=1;i<=n;i++) g[i][i]=0;
	for(int k=1;k<=n;k++) for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) g[i][j]=min(g[i][j],g[i][k]+g[k][j]);
	while(q--){
		ans=(ll)2e18;
		read(x),read(y);
		for(int j=1;j<=cnt[x];j++) for(int k=1;k<=cnt[y];k++) ans=min(ans,b[x][j].se+b[y][k].se+g[b[x][j].fi][b[y][k].fi]);
		write(ans+a[x]+a[y]),putchar('\n');
	}
	return 0;
}
