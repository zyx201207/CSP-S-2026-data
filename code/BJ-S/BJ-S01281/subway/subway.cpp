#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10,M=510;
typedef long long ll;
ll inf=1e18,ans=inf;
ll dis[M][M],w[N];
int k[M];
int c,n,m,q,d;
struct node{
	int id;
	ll w;
};
vector<ll>a[M],t[M];
vector<node>tmp[N];
int main(){	
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
	for(int i=1;i<=m;i++)scanf("%lld",&w[i]);
	for(int i=1;i<=n;i++){
		scanf("%d",&k[i]);
		for(int j=0;j<=k[i];j++){a[i].push_back(0);t[i].push_back(0);}
		for(int j=1;j<=k[i];j++){
			scanf("%lld%lld",&a[i][j],&t[i][j]);
			tmp[a[i][j]].push_back({i,t[i][j]});
		}
	}
	for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)dis[i][j]=(i!=j)*inf;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=k[i];j++){
			for(int k=0;k<tmp[a[i][j]].size();k++){
				int v=tmp[a[i][j]][k].id;
				ll w=tmp[a[i][j]][k].w;
				dis[i][v]=min(dis[i][v],t[i][j]+w);
			}
		}
	}
	/*for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++)cout<<dis[i][j]<<' ';
		cout<<endl;
	}*/
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			for(int k=1;k<=n;k++){
				if(dis[i][k]==inf || dis[k][j]==inf)continue;
				dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
			}
		}
	}
	while(q--){
		int x,y;
		ans=inf;
		scanf("%d%d",&x,&y);
		for(int i=0;i<tmp[x].size();i++){
			int v=tmp[x][i].id;
			ll w1=tmp[x][i].w;
			for(int j=0;j<tmp[y].size();j++){
				int u=tmp[y][j].id;
				ll w2=tmp[y][j].w;
				//cout<<u<<','<<v<<':'<<dis[u][v]<<endl;
				ans=min(ans,dis[u][v]+w1+w2);
			}
		}
		printf("%lld\n",ans+w[x]+w[y]);
	}
	return 0;
}