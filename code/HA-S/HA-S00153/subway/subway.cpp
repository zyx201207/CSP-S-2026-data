#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,w[500100],pre[600100],l;
struct fun{
	int to,ne,le;
}ms[10001000];
void add(int u,int v,int w){
	ms[++l]={v,pre[u],w},pre[u]=l;
}
long long mp[510][510];//,MP[510][510];
bool MP[510][510];
int X,TI;
#define PII pair<long long,int>
priority_queue<PII> Q;
void dfs(){
	Q.push({0,X});
	while(!Q.empty()){
		int x=Q.top().second;Q.pop();
		TI++;
		for(int i=1;i<=n;i++)if(mp[X][x]+mp[x][i]<mp[X][i]||(mp[X][x]+mp[x][i]==mp[X][i]&&MP[X][i]==0)){
			mp[X][i]=mp[X][x]+mp[x][i];MP[X][i]=1;
			Q.push({-mp[X][i],i});
		}
	}
}
int id[500100][21],D[500100],z[500100][21];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
	for(int i=1;i<=m;i++)scanf("%d",&w[i]);
	for(int i=1,k,x,z;i<=n;i++){
		scanf("%d",&k);
		while(k--){
			scanf("%d%d",&x,&z);
			add(x,i,z);
		}
	}
	for(int i=1;i<=m;i++){
		//重新建边：已知路径总数并不多，故重新建边 
		for(int j=pre[i];j;j=ms[j].ne){
			int to=ms[j].to;
			id[i][++D[i]]=to,z[i][D[i]]=ms[j].le;
		}
	}
	memset(mp,0x3f,sizeof mp);
	for(int i=1;i<=n;i++)mp[i][i]=0;
	for(int i=1;i<=m;i++)
		for(int j=1;j<D[i];j++)
			for(int k=j+1;k<=D[i];k++){
				mp[id[i][j]][id[i][k]]=mp[id[i][k]][id[i][j]]=min(mp[id[i][j]][id[i][k]],(long long)z[i][j]+z[i][k]);
			}
	for(X=1;X<=n;X++)dfs();
	while(q--){
		int u,v;
		scanf("%d%d",&u,&v);
		long long ans=LLONG_MAX;
		for(int i=1;i<=D[u];i++)
			for(int j=1;j<=D[v];j++){
				ans=min(ans,(long long)z[u][i]+z[v][j]+mp[id[u][i]][id[v][j]]);
			}
		printf("%lld\n",ans+w[u]+w[v]);
	}
	return 0;
}
