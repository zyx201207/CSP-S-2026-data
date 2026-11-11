#include<bits/stdc++.h>
#define ll long long 
#define iff 0x3f3f3f3f3f3f3f3f
using namespace std;
const long long MAXN=505;
const long long MAXEDGE=2000005;
int qwe,n,m,d,q;
struct cyx{
	int to;
	ll val;
}edge[MAXEDGE];
vector<cyx> head[MAXN];
int road[25],len;
ll w[MAXN],cc[MAXEDGE];

bool vis[MAXN];
ll bfs(int a,int b,ll c){
	vis[a]=1;
	if(a==b) return 0;
	ll ans=iff;
	for(int i=0;i<head[a].size();i++){
		if(!vis[head[a][i].to])
		ans=min(ans,bfs(head[a][i].to,b,c)+head[a][i].val);
	}
	return ans;
}


int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);	
	scanf("%d%d%d%d%d",&qwe,&n,&m,&d,&q);	
	for(int i=1;i<=m;i++){
		scanf("%d",&w[i]);
	}
	for(int i=1;i<=n;i++){
		scanf("%d",&len);
		for(int j=1;j<=len;j++){
			scanf("%d",&road[j]);
			scanf("%d",&cc[j]);
			for(int z=1;z<j;z++){
				int a=road[z],b=road[j];
				ll c=cc[z]+cc[j];
				head[a].push_back({b,c});
				head[b].push_back({a,c});
			}
		}
	}
	int l,r;
	for(int i=1;i<=q;i++){
		scanf("%d%d",&l,&r);
		if(l!=r)
		printf("%lld\n",bfs(l,r,0)+w[l]+w[r]);
		else printf("0\n");
		memset(vis,0,sizeof(vis));
	}
	
	
	
	return 0;
} 
