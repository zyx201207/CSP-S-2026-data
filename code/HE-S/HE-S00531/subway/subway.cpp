#include <bits/stdc++.h>
using namespace std;
const int M=5e5+5;
const int D=505;
int c,n,m,d,q,x,y;
long long w[M];
int num,a;
long long dis[D][D];
long long ans,t;
vector<pair<int,long long> > g[M];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
//	cin>>c>>n>>m>>d>>q;
	scanf("%d %d %d %d %d",&c,&n,&m,&d,&q);
	for(int i=1;i<=m;i++) scanf("%lld",&w[i]);
	for(int i=1;i<=n;i++){
		scanf("%d",&num);
		for(int j=1;j<=num;j++){
			scanf("%d %lld",&a,&t);
			g[a].push_back(make_pair(i,t));
		}
	}
	memset(dis,0x3f,sizeof(dis));
	for(int i=1;i<=n;i++) dis[i][i]=0;
	for(int i=1;i<=m;i++){
		for(auto u:g[i]){
			for(auto v:g[i]){
				dis[u.first][v.first]=min(dis[u.first][v.first],u.second+v.second);
			}
		}
	}
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			if(i==k || dis[i][k]==dis[0][0]) continue;
			for(int j=1;j<=n;j++){
				if(i==j || j==k || dis[j][k]==dis[0][0]) continue;
				dis[i][j]=min(dis[i][k]+dis[k][j],dis[i][j]);
			}
		}
	}
	while(q--){
		scanf("%d %d",&x,&y);
		ans=dis[0][0];
		for(auto u:g[x]){
			for(auto v:g[y]){
				ans=min(w[x]+w[y]+u.second+v.second+dis[v.first][u.first],ans);
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}

