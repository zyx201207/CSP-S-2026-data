#include<bits/stdc++.h>
#define ll long long
#define Pii pair<int,int>
#define Pil pair<int,ll>
#define Fi first
#define Se second
using namespace std;
namespace IO{
	bool Isdigit(char c){return c>='0'&&c<='9';}
	template<typename T>inline void read(T &x){
		char c=getchar();bool f=0;x=0;
		while(!Isdigit(c)){if(c=='-')f=1;c=getchar();}
		while(Isdigit(c))x=(x<<3)+(x<<1)+(c^48),c=getchar();
		x=f?-x:x;
	}
}
using namespace IO;
const ll Inf=1e18;
const int N=5e5+10,M=505;
vector<Pil> G[N];
int C,n,m,d,Q;
ll w[N],D[M][M];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	read(C),read(n),read(m),read(d),read(Q);
	for(int i=1;i<=m;i++)read(w[i]);
	for(int i=1,k;i<=n;i++){
		read(k);
		for(int j=1,x,t;j<=k;j++){
			read(x),read(t);
			G[x].push_back(make_pair(i,t));
		}
	}
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			if(i!=j)D[i][j]=Inf;
	for(int i=1;i<=m;i++){
		int L=G[i].size();
		for(int x=1;x<L;x++)
			for(int y=0;y<x;y++){
				int u=G[i][x].Fi,v=G[i][y].Fi;
				ll wu=G[i][x].Se,wv=G[i][y].Se;
				if(D[u][v]>wu+wv)D[u][v]=D[v][u]=wu+wv;
			}
	}
	for(int k=1;k<=n;k++)
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				D[i][j]=min(D[i][j],D[i][k]+D[k][j]);
	int x,y,L1,L2;
	while(Q--){
		read(x),read(y);
		ll Res=Inf;
		L1=G[x].size(),L2=G[y].size();
		for(int i=0;i<L1;i++)
			for(int j=0;j<L2;j++)
				Res=min(Res,G[x][i].Se+G[y][j].Se+D[G[x][i].Fi][G[y][j].Fi]);
		printf("%lld\n",Res+w[x]+w[y]);
	}
}