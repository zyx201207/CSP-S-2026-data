#include<bits/stdc++.h>
using namespace std;
typedef pair<long long,int> PII;
typedef pair<int,int> PI;
vector<PI> g[500010];
long long dist[500010]; 
long long w[500010];
int k[510];
int a[500010];
int t[500010];
int s[500010];
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q;
	scanf("%d %d %d %d %d",&c,&n,&m,&d,&q);
	for(int i=1;i<=m;i++){
		scanf("%lld",&w[i]);
	}
	for(int i=1;i<=n;i++){
		scanf("%d",&k[i]);
		s[i]=s[i-1]+k[i];
		for(int j=1;j<=k[i];j++){
			scanf("%d %d",&a[s[i-1]+j],&t[s[i-1]+j]);
			g[a[s[i-1]+j]].push_back({i,s[i-1]+j});
		}
	}
	for(int r=1;r<=q;r++){
		int x,y;
		scanf("%d %d",&x,&y);
		priority_queue<PII,vector<PII>,greater<PII>> q;
		memset(dist,0x3f,sizeof dist);
		q.push({0ll,x});
		dist[x]=0ll;
		while(q.size()){
			PII now=q.top();
			q.pop();
			int u=now.second;
			if(now.first>dist[u]) continue;
			if(u==y) break;
			for(auto xx:g[u]){
				int cc=t[xx.second];
				for(int i=1;i<=k[xx.first];i++){
					int v=a[s[xx.first-1]+i],cost=t[s[xx.first-1]+i];
					if(u==v) continue;
					if(dist[u]+cost+cc<dist[v]){
						dist[v]=dist[u]+cost+cc;
						q.push({dist[v],v});
					}
				}
			}
		}
		printf("%lld\n",w[x]+dist[y]+w[y]); 
	}
	return 0;
}

