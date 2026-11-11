#include <bits/stdc++.h>
using namespace std;
const long long MAXN=5e2+5,MAXM=5e5+5;
long long c,n,m,d,Q;
long long w[MAXM];
vector<pair<long long,long long> > t1[MAXM],t2[MAXN];
vector<pair<long long,long long> > tu[MAXN];
long long dis[MAXN][MAXN];
bool vis[MAXN];
priority_queue<pair<long long,long long> > q;
void djstl(int x){
	memset(vis,0,sizeof(vis));
	memset(dis[x],0x3f,sizeof(dis[x]));
	dis[x][x]=0;
	while(q.size()) q.pop();
	q.push({0,x});
	while(q.size()){
		long long id=q.top().second;q.pop();
		if(vis[id]) continue;
		vis[id]=1;
		long long len=tu[id].size();
		for(int i=0;i<len;i++){
			long long mb=tu[id][i].first,w=tu[id][i].second+dis[x][id];
			if(w<dis[x][mb]){
				dis[x][mb]=w;
				q.push({-w,mb});
			}
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>c>>n>>m>>d>>Q;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++){
		int k;cin>>k;
		while(k--){
			long long o,w;
			cin>>o>>w;
			t1[o].push_back({i,w});
			t2[i].push_back({o,w});
		}
	}
	memset(dis,0x3f,sizeof(dis));
	for(int i=1;i<=n;i++) dis[i][i]=0;
	for(int i=1;i<=n;i++){
		long long len=t2[i].size();
		for(int j=0;j<len;j++){
			long long mb=t2[i][j].first,w1=t2[i][j].second;
			long long len2=t1[mb].size();
			for(int k=0;k<len2;k++){
				long long mb2=t1[mb][k].first,w2=t1[mb][k].second;
				dis[mb2][i]=dis[i][mb2]=min(dis[i][mb2],w1+w2);
			}
		}
	}
	for(int i=1;i<=n;i++)
		for(int j=i+1;j<=n;j++)
			if(dis[i][j]<dis[0][0]){
				tu[i].push_back({j,dis[i][j]});
				tu[j].push_back({i,dis[i][j]});
			}
	for(int i=1;i<=n;i++)
		djstl(i);
	while(Q--){
		long long x,y;
		cin>>x>>y;
		long long l1=t1[x].size(),l2=t1[y].size();
		long long mi=1000000000000000000ll;
		for(int i=0;i<l1;i++)
			for(int j=0;j<l2;j++){
				long long mb1=t1[x][i].first,w1=t1[x][i].second;
				long long mb2=t1[y][j].first,w2=t1[y][j].second;
				mi=min(mi,w[x]+w[y]+w1+w2+dis[mb1][mb2]);
			}
		cout<<mi<<'\n';
	}
	return 0;
}
