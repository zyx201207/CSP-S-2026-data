#include<bits/stdc++.h>
#define int long long 
using namespace std;
const int maxn=5e5+10;
const int inf=1e18;
inline int read(){
	int s=0,f=1;char ch=getchar();
	while(!isdigit(ch)){if(ch=='-')f=-1;ch=getchar();}
	while(isdigit(ch)){s=s*10+ch-'0';ch=getchar();}
	return s*f;
}
inline void print(int x){
	if(x<10){putchar(x+'0');return;}
	print(x/10);putchar(x%10+'0');
}
int dis[510][510];
int w[maxn];
struct node{int v,w;};
vector<node>g[maxn];
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	memset(dis,0x3f,sizeof(dis));
	int c=read(),n=read(),m=read(),d=read(),q=read(),tmp=-1;
	for(int i=1;i<=m;i++)w[i]=read();
	for(int i=1;i<=n;i++){
		int k=read();
		for(int j=1;j<=k;j++){
			int a=read(),t=read();
			if(tmp==-1)tmp=t;
			g[i].push_back(node{a+n,t});
			g[a+n].push_back(node{i,t});
		}
	}
	for(int u=1;u<=n;u++){
		for(auto i:g[u]){
			for(auto j:g[i.v]){
				if(j.v!=u){
					dis[u][j.v]=min(dis[u][j.v],i.w+j.w);
				}
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(i==j){
				dis[i][j]=0;
				continue; 
			}
			for(int k=1;k<=n;k++){
				dis[i][j]=min(dis[i][k]+dis[k][j],dis[i][j]);
			}
		}
	}
	for(int i=1;i<=q;i++){
		int u=read(),v=read(),mi=inf;
		for(auto i:g[n+u]){
			for(auto j:g[n+v]){
				mi=min(mi,dis[i.v][j.v]+i.w+j.w);
			}
		}print(mi+w[u]+w[v]);putchar('\n');
	}
	return 0;
}
