#include<bits/stdc++.h>
using namespace std;
long long x,y,c,n,m,dd,qq,w[500005],a,t,k,vi[505],vis[505][505],d[505][505],p[505],net[505];
struct D{
	long long id,w;
};
priority_queue<D> q;
bool operator<(D x,D y){
	return x.w>y.w;
}
vector<D> v[500005];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>dd>>qq;
	for(int i=1;i<=500;i++)
	for(int j=1;j<=500;j++)
	vis[i][j]=d[i][j]=1e15;
	for(int i=1;i<=m;i++)
	scanf("%lld",&w[i]);
	for(int i=1;i<=n;i++){
		cin>>k;
		for(int j=1;j<=k;j++){
			scanf("%d%lld",&a,&t);
			v[a].push_back(D{i,t});
		}
	}
	for(int i=1;i<=m;i++){
		int l=v[i].size();
		for(int j=0;j<l;j++){
		for(int o=0;o<l;o++){
		vis[v[i][j].id][v[i][o].id]=min(v[i][j].w+v[i][o].w,vis[v[i][j].id][v[i][o].id]);
		vis[v[i][o].id][v[i][j].id]=vis[v[i][j].id][v[i][o].id];
	    }}
	}
	for(int i=1;i<=n;i++){
		d[i][i]=0;
		q.push(D{i,0});
		for(int j=0;j<=n;j++){
			p[j]=j-1;
			net[j]=j+1;
		}
		for(int j=1;j<=n;j++)
		vi[j]=0;
		while(!q.empty()){
			D t=q.top();
			q.pop();
			net[p[t.id]]=net[t.id];
			p[net[t.id]]=p[t.id];
			vi[t.id]=1;
			for(int j=0;j<=n;j=net[j]){
				if(d[i][j]>d[i][t.id]+vis[t.id][j]){
					d[i][j]=d[i][t.id]+vis[t.id][j];
				    q.push(D{j,d[i][j]});
			    }
			}
		}
	}
	for(int i=1;i<=qq;i++){
		scanf("%d%d",&x,&y);
		int l=v[x].size(),l2=v[y].size();
		long long ans=1e16;
		for(int i=0;i<l;i++)
		for(int j=0;j<l2;j++)
		ans=min(d[v[x][i].id][v[y][j].id]+v[x][i].w+v[y][j].w+w[x]+w[y],ans);
		printf("%lld\n",ans);
	}
}
