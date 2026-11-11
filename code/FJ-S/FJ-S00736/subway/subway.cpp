#include<bits/stdc++.h>
#define int long long
using namespace std;
int c,n,m,d,q;
int w[500005];
struct f{
	int v,w,nxt;
}e[250005];
int h[505],cnt;
void add(int u,int v,int w){
	e[++cnt]={v,w,h[u]};
	h[u]=cnt;
	return;
}
int a[500005][21];
int b[500005];
int t[500005][21];
int ee[505][505];
int dist[505][505];
int vs[505];
int dij(int s){
	memset(vs,0,sizeof vs);
	priority_queue<pair<int,int> > q;
	dist[s][s]=0;
	q.push({0,s});
	while(!q.empty()){
		int u=q.top().second;
		q.pop();
		if(vs[u]==1){
			continue;
		}
		vs[u]=1;
		for(int i=h[u];i;i=e[i].nxt){
			int v=e[i].v;
			int w=e[i].w;
			if(vs[v]==1){
				continue;
			}
			int sum=dist[s][u]+w;
			if(sum<dist[s][v]){
				dist[s][v]=sum;
				q.push({-sum,v});
			}
		}
	}
	return 0;
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%lld%lld%lld%lld%lld",&c,&n,&m,&d,&q);
	for(int i=1;i<=m;i++){
		scanf("%lld",&w[i]);
	}
	int k;
	for(int i=1;i<=n;i++){
		scanf("%lld",&k);
		int r,ti;
		for(int j=1;j<=k;j++){
			scanf("%lld%lld",&r,&ti);
			a[r][++b[r]]=i;
			t[r][b[r]]=ti;
//			cout<<r<<" "<<b[r]<<" "<<i<<endl;
		}
	}
	memset(ee,0x3f,sizeof ee);
	for(int i=1;i<=m;i++){
		for(int j=1;j<=b[i];j++){
			for(int k=j+1;k<=b[i];k++){
				if(t[i][j]+t[i][k]<ee[a[i][j]][a[i][k]]){
					ee[a[i][j]][a[i][k]]=t[i][j]+t[i][k];
				}
				if(t[i][j]+t[i][k]<ee[a[i][k]][a[i][j]]){
					ee[a[i][k]][a[i][j]]=t[i][j]+t[i][k];
				}
//				cout<<i<<" "<<a[i][j]<<" "<<a[i][k]<<" "<<ee[j][k]<<endl;
			}
		}
	}
	for(int u=1;u<=n;u++){
		for(int v=1;v<=n;v++){
			if(ee[u][v]==0x3f3f3f3f3f3f3f3f){
				ee[u][v]=0;
			}
		}
	}
	for(int u=1;u<=n;u++){
		for(int v=1;v<=n;v++){
//			cout<<ee[u][v]<<" ";
			if(ee[u][v]){
//				cout<<u<<" "<<v<<endl;
				add(u,v,ee[u][v]);
			}
		}
//		cout<<endl;
	}
	memset(dist,0x3f,sizeof dist);
	for(int i=1;i<=n;i++){
		dij(i);
//		for(int j=1;j<=n;j++){
//			cout<<dist[i][j]<<' ';
//		}
//		cout<<endl;
	}
	int u,v;
	for(int i=1;i<=q;i++){
		cin>>u>>v;
		int ans=0x3f3f3f3f3f3f3f3f;
		for(int j=1;j<=b[u];j++){
			for(int k=1;k<=b[v];k++){
				if(t[u][j]+t[v][k]+dist[a[u][j]][a[v][k]]<ans){
					ans=t[u][j]+t[v][k]+dist[a[u][j]][a[v][k]];
				}
			}
		}
		cout<<ans+w[u]+w[v]<<endl;
	}
	return 0;
}
/*
0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3
76pts
*/
