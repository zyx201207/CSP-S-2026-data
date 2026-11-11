#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int c,n,m,d,Q,sum;
int k[N];
long long w[N],dist[510][510];
vector<long long>a[N],t[N],eg[N],id[N];
struct node{
	long long x;
	int l,r;
	bool operator <(const node a)const{
		return x<a.x;
	}
	bool operator >(const node a)const{
		return x>a.x;
	}
};
priority_queue<node,vector<node>,greater<node> >q;
pair<int,int>qp[N];
map<pair<int,int>,bool>mp;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%d%d%d%d%d",&c,&n,&m,&d,&Q);
	for(int i=1;i<=m;i++)scanf("%lld",&w[i]);
	for(int i=1;i<=n;i++){
		scanf("%d",&k[i]);
		for(int j=0;j<k[i];j++){
			long long x,y;
			scanf("%lld%lld",&x,&y);
			a[i].push_back(x);
			t[i].push_back(y);
			eg[x].push_back(i);
			id[x].push_back(j);
		}
	}
	memset(dist,0x3f,sizeof dist);long long INF=dist[0][0];
	for(int l=1;l<=m;l++){
		int len=eg[l].size();
		for(int i=0;i<len;i++){
			int x=eg[l][i];dist[x][x]=0;
			for(int j=i;j<len;j++){
				int y=eg[l][j];
				if(t[x][id[l][i]]+t[y][id[l][j]]<0)continue;
				dist[x][y]=min(dist[x][y],t[x][id[l][i]]+t[y][id[l][j]]);
				dist[y][x]=min(dist[y][x],dist[x][y]);
			}
		}
	}
	for(int i=1;i<=n;i++)for(int j=i;j<=n;j++)if(dist[i][j]!=INF)q.push({dist[i][j],i,j}),qp[++sum]={i,j};
	while(!q.empty()){
		node t=q.top();q.pop();
		if(dist[t.l][t.r]<t.x)continue;
		for(int i=1;i<=sum;i++){
			int l=qp[i].first,r=qp[i].second;
			if(dist[l][r]>dist[l][t.l]+t.x+dist[t.r][r]){
				if(dist[l][t.l]==INF||dist[t.r][r]==INF)continue;
				dist[l][r]=dist[l][t.l]+t.x+dist[t.r][r];
				dist[r][l]=dist[l][r];
				q.push({dist[l][r],l,r});
			}
		}
		for(int i=1;i<=sum;i++){
			int l=qp[i].first,r=qp[i].second;
			if(dist[t.l][t.r]>dist[t.l][l]+dist[l][r]+dist[r][t.r]){
				if(dist[t.l][l]==INF||dist[r][t.r]==INF)continue;
				dist[t.l][t.r]=dist[t.l][l]+dist[l][r]+dist[r][t.r];
				dist[t.r][t.l]=dist[t.l][t.r];
				q.push({dist[t.l][t.r],t.l,t.r});
			}
		}
		if(mp[{t.l,t.r}]==false){
			mp[{t.l,t.r}]=true;
			qp[++sum]={t.l,t.r};
		}
	}
	while(Q--){
		int x,y;
		scanf("%d%d",&x,&y);
		long long ans=INF;
		for(int i=0;i<eg[x].size();i++)
			for(int j=0;j<eg[y].size();j++)
				ans=min(ans,dist[eg[x][i]][eg[y][j]]+t[eg[x][i]][id[x][i]]+t[eg[y][j]][id[y][j]]);
		printf("%lld\n",ans+w[x]+w[y]);
	}
	return 0;
}