#include<bits/stdc++.h>
using namespace std;
const int maxn=1e6+3;
const long long INF=1e18+3;

inline int read(){
	int res=0;
	char c;c=getchar();
	while(c<'0'||c>'9')c=getchar();
	while(c>='0'&&c<='9'){
		res=res*10+c-'0';
		c=getchar();
	}
	return res;
}
int c,n,m,d,q;

long long f[503][503],w[maxn];
struct edge{
	long long v,t;
};
vector<edge>e[maxn],sub[maxn];

int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=1;i<=n;i++){
		int k;k=read();
		for(int j=1;j<=k;j++){
			int a,t;
			a=read(),t=read();
			e[a].push_back(edge{i,t});
			sub[i].push_back(edge{a,t});
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			f[i][j]=INF;
			if(i==j)f[i][j]=0;
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=0;j<sub[i].size();j++){
			int pla=sub[i][j].v,tim=sub[i][j].t;
			for(int k=0;k<e[pla].size();k++){
				int v=e[pla][k].v;
				if(i==v)continue;
				f[i][v]=min(f[i][v],tim+e[pla][k].t);
			}
		}
	}
	
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			for(int k=1;k<=n;k++){
				if(i==j||j==k||i==k)continue;
				f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
			}
		}
	}
	
	for(int i=1;i<=q;i++){
		int x,y;
		x=read(),y=read();
		long long ans=INF;
		for(int j=0;j<e[x].size();j++){
			int u=e[x][j].v;
			for(int k=0;k<e[y].size();k++){
				int v=e[y][k].v;
				ans=min(ans,f[u][v]+e[x][j].t+e[y][k].t);
			}
		}
		ans+=w[x]+w[y];
		printf("%lld\n",ans);
	}
	return 0;
}
