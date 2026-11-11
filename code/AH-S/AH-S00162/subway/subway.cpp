#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=6e5+5;
int n,m,c,d,ah[N],que;
struct cross{
	int id,dsi;
};
struct node{
	int id,s;
};
vector<node> link[500005];
vector<cross> cr[500005];
int ds[505][505];
inline int read(){
	int x=0;
	char ch=getchar();
	while(ch<'0'||ch>'9')ch=getchar();
	while(ch>='0'&&ch<='9')
		x=x*10+(ch-48),ch=getchar();
	return x;
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	memset(ds,0x3f,sizeof ds);
	c=read(),n=read(),m=read(),d=read(),que=read();
	for(int i=1;i<=m;i++)ah[i]=read();
	for(int i=1;i<=n;i++)ds[i][i]=0;
	for(int i=1;i<=n;i++){
		int k=read();
		for(int j=1;j<=k;j++){
			int u=i,v=read(),w=read();
			cr[v].push_back({i,w});
			bool op=0;
			for(int i=0;i<link[v].size();i++){
				int to=link[v][i].id;
				if(ds[u][to]>link[v][i].s+w)ds[u][to]=ds[to][u]=link[v][i].s+w;
				if(u==to){
					op=1;
					link[v][i].s=min(link[v][i].s,w);
				}
			}
			if(!op)link[v].push_back({u,w});
		}
	}
	for(int k=1;k<=n;k++){
		for(int i=1;i<n;i++){
			for(int j=i+1;j<=n;j++){
					if(ds[j][i]>ds[i][k]+ds[k][j])ds[j][i]=ds[i][j]=ds[i][k]+ds[k][j];
			}
		}
	}
	while(que--){
		int st=read(),ed=read();
		int ans=1e18;
		for(int i=0;i<cr[st].size();i++){
			for(int j=0;j<cr[ed].size();j++){
				int u=cr[st][i].id,v=cr[ed][j].id;
				int cmp=ah[st]+ah[ed]+cr[st][i].dsi+cr[ed][j].dsi+ds[u][v];
				if(ans>cmp)ans=cmp;
			}
		}
		printf("%lld\n",ans);
	}
}
