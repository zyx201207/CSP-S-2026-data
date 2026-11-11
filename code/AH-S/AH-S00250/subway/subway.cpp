#include <bits/stdc++.h>
using namespace std;

int c,n,m,d,q,cntsid[510001],to[500001][21];
long long w[510001],sidv[500001][21],ans=0,dis[602];
bool zt[602];

struct edge{
	int to;
	long long v;
};

long long smv[602][602];


int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
	for(int i=1;i<=m;i++) scanf("%lld",&w[i]);
	for(int i=1;i<=n;i++){
		int cs;
		scanf("%d",&cs);
		while(cs--){
			int tox;
			scanf("%d",&tox);
			cntsid[tox]++;
			to[tox][cntsid[tox]]=i;
			scanf("%lld",&sidv[tox][cntsid[tox]]);
		}
	}
	memset(smv,-1,sizeof(smv));
	for(int i=1;i<=m;i++){
		for(int j=1;j<=cntsid[i];j++){
			for(int k=1;k<=cntsid[i];k++){
				if(j==k) continue ;
				int a=to[i][j],b=to[i][k];
				long long val=sidv[i][j]+sidv[i][k];
				if(smv[a][b]==-1) smv[a][b]=val,smv[b][a]=val;
				else if(smv[a][b]>val) smv[a][b]=val,smv[b][a]=val;
			}
		}
	}
	while(q--){
		vector <edge> v[602];
		for(int i=1;i<=n;i++){
			for(int j=1;j<i;j++){
				if(smv[i][j]!=-1){
					v[i].push_back({j,smv[i][j]});
					v[j].push_back({i,smv[i][j]});
				}
			}
		}
		ans=0;
		int x,y;
		scanf("%d%d",&x,&y);
		ans+=w[x]+w[y];
		for(int i=1;i<=cntsid[x];i++){
			v[0].push_back({to[x][i],sidv[x][i]});
		}
		for(int i=1;i<=cntsid[y];i++){
			v[to[y][i]].push_back({n+1,sidv[y][i]});
		}
		memset(dis,0x3f,sizeof(dis));
		memset(zt,0,sizeof(zt));
		queue <int> q;
		q.push(0);
		dis[0]=0;
		zt[0]=1;
		while(!q.empty()){
			int now=q.front();
			q.pop();
			zt[now]=0;
			for(int i=0;i!=int(v[now].size());i++){
				if(dis[v[now][i].to]>dis[now]+v[now][i].v){
					dis[v[now][i].to]=dis[now]+v[now][i].v;
					if(zt[v[now][i].to]==0){
						q.push(v[now][i].to);
						zt[v[now][i].to]=1;
					}
				}
			}
		}
		printf("%lld\n",ans+dis[n+1]);
	}
	return 0;
}
