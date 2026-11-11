#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e2+5;
int c,t;
int n,k;
vector<int>a[N];
bool b[N];
int g[N],tnt;
int maxn;
int dis[N];
bool vis[N];
queue<int>q;
bool tt[N];
int ans;
void dfs2(int x){
	tt[x]=1;
	for(int i=0;i<a[x].size();i++){
		int v=a[x][i];
		if(!b[v]||tt[v])continue;
		dfs2(v);
	}
}
void spfa(int x){
	memset(dis,0x3f,sizeof(dis));
	memset(vis,0,sizeof(vis));
	dis[x]=0;
	q.push(x);
	while(q.size()){
		int u=q.front();q.pop();
		vis[u]=0;
		for(int i=0;i<a[u].size();i++){
			int v=a[u][i];
			if(dis[u]+1<dis[v]){
				dis[v]=dis[u]+1;
				if(!vis[v]){
					vis[v]=1;
					q.push(v);
				}
			}
		}
	}
}
void dfs(int x,int t){
	if(x==t+1){
		tnt=0;
		for(int i=1;i<=n;i++){
			if(b[i])g[++tnt]=i;
		}
		maxn=0;
		int cnt=0;
		memset(tt,0,sizeof(tt));
		for(int i=1;i<=tnt;i++){
			int mina=1e7;
			spfa(g[i]);
			if(!tt[g[i]]){
				cnt++;
				dfs2(g[i]);
			}
			for(int j=1;j<=tnt;j++){
				if(i!=j)mina=min(mina,dis[g[tnt]]);
			}
			maxn=max(maxn,mina);
		}
		if(cnt<=2&&maxn<ans){
			ans=maxn;
		}
		return;
	}
	for(int i=1;i<=n;i++){
		if(b[i])continue;
		b[i]=1;
		dfs(x+1,t);
		b[i]=0;
	}
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	while(t--){
		scanf("%d %d",&n,&k);
		for(int i=1;i<=n;i++)a[i].clear();
		for(int i=1;i<n;i++){
			int x,y;
			scanf("%d %d",&x,&y);
			a[x].push_back(y);
			a[y].push_back(x);
		}
		ans=1e8;
		dfs(1,k);
		printf("%d\n",ans);
	}
	return 0;
} 
