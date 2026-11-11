#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int M=5e5+10;
int c,n,m,D,Q,W[M],a[M],t[M];
struct node{
	int v;
	long long w;
};
vector<node>e[M];

ll d[M],vis[M];
priority_queue< pair<ll,int> >q;
void dij(int x,int y){
	for(int i=0;i<=m;i++)d[i]=1e18,vis[i]=0;
	d[x]=0;
	while(q.size())q.pop();
	q.push({0,x});
	while(q.size()){
		pair<ll,int>p=q.top();
		q.pop();
		int u=p.second;
		if(u==y){
			printf("%lld\n",(W[x]+W[y]-p.first));
			return;
		}
		if(vis[u])continue;
		vis[u]=1;
		for(auto f : e[u]){
			int v=f.v,w=f.w;
			if(d[v]>d[u]+w){
				d[v]=d[u]+w;
				q.push({-d[v],v});
			}
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%d%d%d%d%d",&c,&n,&m,&D,&Q);
	for(int i=1;i<=m;i++)scanf("%d",&W[i]);
	for(int i=1;i<=n;i++){
		int k;
		scanf("%d",&k);
		for(int j=1;j<=k;j++){
			scanf("%d%d",&a[j],&t[j]);
			for(int l=1;l<j;l++){
				e[a[l]].push_back({a[j],t[l]+t[j]});
				e[a[j]].push_back({a[l],t[l]+t[j]});
			}
		}
	}
	while(Q--){
		int x,y;
		scanf("%d%d",&x,&y);
		dij(x,y);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
