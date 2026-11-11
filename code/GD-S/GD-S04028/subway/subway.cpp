#include<bits/stdc++.h>
using namespace std;
#define gc getchar
int read(){
	short f=1,c=gc();
	int x=0;
	while(c!=0&&(c<'0'&&c>'9')){
		if(c==EOF)return 0;
		c=gc();
	}if(c=='-'){f=-1;c=gc();}
	while(c>='0'&&c<='9'){
		x=x*10+c-'0';
		c=gc();
	}return x*f;
}
short c,n,d;
int m,k[502],q,g[502][502];
void flo(){
	for(int u=0;u<=n;++u)
		for(int v=0;v<=n;++v){
			if(u==v)continue;
			for(int k=0;k<=n;++k)
				g[u][v]=g[v][u]=min(g[u][v],g[u][k]+g[k][v]);
		}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	for(int i=0;i<=n;++i)
		for(int j=0;j<=n;++j)
			g[i][j]=2e9;
	c=read(),n=read(),m=read(),d=read(),q=read();
	int w;
	for(int i=1;i<=m;++i)
		w=read(),g[i][0]=g[0][i]=w;
	for(int i=1;i<=n;++i){
		k[i]=read();
		int a[2];
		for(int j=1;j<=k[i];++j){
			a[j%2]=read(),w=read();//w=t_i,j
			if(j==1)continue;
			g[a[(j+1)%2]][a[j%2]]=w;
			g[a[j%2]][a[(j+1)%2]]=w;
		}
	}
	flo();
	int x,y;
	while(q--){
		x=read(),y=read();
		cout<<g[x][y]<<'\n';
	}
}
