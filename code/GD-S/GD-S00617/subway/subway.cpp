#include<bits/stdc++.h>
using namespace std;
const int N=5e5+100;
int c,n,m,d,q;
int w[N];
int sum;
vector<pair<int,int> > a[N];
vector<pair<int,int> > b[N];
bool vis1[N],vis0[N];
int l[N];
void dfs(int u,int p,int v,int ans){
//	printf("%d %d %d\n",u,p,ans);
	if(u==v){/*printf("\n");*/sum=min(sum,ans);return;}
	if(p==0){
		vis0[u]=true;
		for(auto i : a[u]){
			if(vis1[i.first])continue;
			dfs(i.first,1,v,ans+i.second);
		}
//		vis0[u]=false;
	}else{
		vis1[u]=true;
		for(auto i : b[u]){
			if(vis0[i.first])continue;
			dfs(i.first,0,v,ans+i.second);
		}
//		vis1[u]=false;
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
	for(int i=1;i<=m;i++)scanf("%d",&w[i]);
	for(int i=1;i<=n;i++){
		scanf("%d",&l[i]);
		for(int j=1,x,y;j<=l[i];j++)scanf("%d%d",&x,&y),a[x].push_back({i,y}),b[i].push_back({x,y});
	}
	while(q--){
		memset(vis1,false,sizeof(vis1));
		memset(vis0,false,sizeof(vis0));
		sum=1e9;
		int u,v;
		scanf("%d%d",&u,&v);
		dfs(u,0,v,w[u]+w[v]);
		printf("%d\n",sum);
	} 
	return 0;
}

