#include<bits/stdc++.h>
#include<queue>
using namespace std;

const int MAXN=1e6+10;

struct edge{
	int x,y,pre;
}e[MAXN<<1];

int c,t,n,k,elen,ans;
bool flag;
int last[MAXN],cnt[MAXN];
bool vis[MAXN],inq[MAXN];

void build(int u,int v){
	e[++elen]={u,v,last[u]},last[u]=elen;
}

int bfs(int id){
	queue<int> q;cnt[id]=0;q.push(id);
	for (int i=1;i<=n;i++)
		inq[i]=0;
	while (!q.empty()){
		int u=q.front();q.pop();
		if (vis[u]) return cnt[u];
		if (inq[u]) continue;
		inq[u]=1;
		for (int i=last[u];i;i=e[i].pre){
			int v=e[i].y;
			cnt[v]=cnt[u]+1;q.push(v);
		}
	}
}

void query(){
	int res=0;
	for (int i=1;i<=n;i++)
		res=max(res,bfs(i));
	ans=min(ans,res);
}

void dfs(int u,int cnt,bool f){
	vis[u]=1;
	if (cnt==k) query();
	else{
		for (int i=last[u];i;i=e[i].pre){
			int v=e[i].y;
			if (vis[v]) continue;
			dfs(v,cnt+1,f);
		}
		if (f==1)
			for (int i=1;i<=n;i++)
				if (!vis[i]) dfs(i,cnt+1,!f);
	}
	vis[u]=0;
}

int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	scanf("%d%d",&c,&t);
	while (t--){
		scanf("%d%d",&n,&k);flag=(n&1),elen=0,ans=MAXN;
		for (int i=1;i<=n;i++)
			last[i]=0,vis[i]=0;
		for (int i=1;i<n;i++){
			int u,v;scanf("%d%d",&u,&v);
			build(u,v),build(v,u);
			flag&=((i<=n/2)?(u==i&&v==i+1):(u==i-n/2&&v==i+1));
		}
		if (flag){
			if (n==k) printf("0\n");
			else if (k>=n/2) printf("1\n");
			else printf("%d\n",(n/2-k+1)/2+1);
			continue;
		}
		for (int i=1;i<=n;i++)
			dfs(i,1,1);
		printf("%d\n",ans);
	}
	return 0;
}
