#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<queue>
#include<map>
#include<vector>
using namespace std;
#define int long long
int c,n,m,d,q;
int w[500005],k[505];
struct node{
	int to,val;
	operator < (const node &x) const
    { return val>x.val; }
};
vector<node> g[600005];
int dis[600005];
bool vis[600005];
int dij(int s,int t){
	priority_queue<node,vector<node> > q;
	for(int i=1;i<=n+m;i++) dis[i]=1e17;
	memset(vis,0,sizeof(vis));
	dis[s]=0;
	vis[s]=1;
	q.push(node{s,0});
	while(!q.empty()){
		node u=q.top();
		q.pop();
		for(int i=0;i<g[u.to].size();i++){
			int v=g[u.to][i].to;
			if(dis[v]>dis[u.to]+g[u.to][i].val){
				dis[v]=dis[u.to]+g[u.to][i].val;
				if(!vis[v]){
					vis[v]=1;
					q.push(node{v,dis[v]});
				}
			}
		}
	}
	return dis[t];
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%lld %lld %lld %lld %lld\n",&c,&n,&m,&d,&q);
	for(int i=1;i<=m;i++) scanf("%lld ",&w[i]);
	if(c==20||c==21){
		map<int,int> mp,kk2,kk3;
		int minn=1e7;
		for(int i=1;i<=n;i++){
		scanf("%lld ",&k[i]);
		int x,y;
		for(int j=1;j<=k[i];j++){
			scanf("%lld %lld ",&x,&y);
			g[m+i].push_back(node{x,y});
			g[x].push_back(node{m+i,y});
			if(mp[x]==1){
				mp[x]=3;
				minn=min(minn,y+kk2[x]);
				kk3[x]=y;
			}else{
				mp[x]=i;
				kk2[x]=y;
			}
		}
	}
	int x,y;
	while(q--){
		scanf("%lld %lld\n",&x,&y);
		if(mp[x]==mp[y]&&mp[x]!=3) cout<<w[x]+w[y]+kk2[x]+kk2[y]<<endl;
		else if(mp[x]==mp[y]&&mp[x]==3) cout<<w[x]+w[y]+min(kk2[x]+kk2[y],kk3[x]+kk3[y])<<endl;
		else if(mp[x]==3){
			if(mp[y]==1) cout<<w[x]+w[y]+kk2[x]+kk2[y]<<endl;
			else cout<<w[x]+w[y]+kk3[x]+kk2[y]<<endl;
		}else if(mp[y]==3){
			if(mp[x]==1) cout<<w[x]+w[y]+kk2[x]+kk2[y]<<endl;
			else cout<<w[x]+w[y]+kk2[x]+kk3[y]<<endl;
		}else cout<<w[x]+w[y]+minn+kk2[x]+kk2[y]<<endl;
	}
	return 0;
	}
	for(int i=1;i<=n;i++){
		scanf("%lld ",&k[i]);
		int x,y;
		for(int j=1;j<=k[i];j++){
			scanf("%lld %lld ",&x,&y);
			g[m+i].push_back(node{x,y});
			g[x].push_back(node{m+i,y});
		}
	}
	int x,y;
	while(q--){
		scanf("%lld %lld\n",&x,&y);
		printf("%lld\n",dij(x,y)+w[x]+w[y]);
	}
	return 0; 
} 
