#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=505,M=5e5+5;
int C,n,m,d,q;
int f[N][N];
int w[M];
struct node{
	int v,x;
};
vector<node> g[M];
int read(){
	int x=0;
	char c=getchar();
	while(!isdigit(c)) c=getchar();
	while(isdigit(c)) x=x*10+c-'0',c=getchar();
	return x;
}
void write(int x){
	if(x<10){putchar(x+'0');return;}
	write(x/10);
	putchar(x%10+'0');
}
signed main(){
	//ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	C=read(),n=read(),m=read(),d=read(),q=read();
	for(int i=1;i<=m;i++){
		w[i]=read();
	}
	memset(f,0x3f,sizeof(f));
	for(int i=1;i<=n;i++) f[i][i]=0;
	for(int i=1;i<=n;i++){
		int k=read();
		for(int j=1;j<=k;j++){
			int a=read(),t=read();
			for(node p:g[a]){
				int v=p.v,x=p.x;
				f[v][i]=f[i][v]=min(f[v][i],x+t);
			}
			g[a].push_back({i,t});
		}
	}
	for(int k=1;k<=n;k++)
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
	while(q--){
		int x,y;
		x=read(),y=read();
		int ans=0x3f3f3f3f3f3f3f3f;
		for(node v1:g[x])
			for(node v2:g[y]){
				ans=min(ans,v1.x+v2.x+f[v1.v][v2.v]);
			}
		ans+=w[x]+w[y];
		write(ans);putchar('\n');
	}
	return 0;
}
