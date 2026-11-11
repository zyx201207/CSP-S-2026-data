#include<iostream>
#include<queue>
using namespace std;

int fa[200010];

int find_anc(int u){
	if(fa[u]==u)return u;
	return fa[u]=find_anc(fa[u]);
}

void clear(int n){
	for(int i=0;i<n;i++)fa[i]=i;
}

int head[200010],nxt[200010],to[200010];
int cur;

void add(int u,int v){
	to[cur]=v;
	nxt[cur]=head[u];
	head[u]=cur++;
}

bool vis[200010];
int dis[200010];

int bfs(int sta,int n){
	queue<int>q;
	for(int i=0;i<n;i++)dis[i]=1e9,vis[i]=0;
	for(int i=0;i<n;i++){
		if((sta>>i)&1)q.push(i),dis[i]=0;
	} 
	while(q.size()){
		int u=q.front();
		q.pop();
		if(vis[u])continue;
		vis[u]=1;
		for(int i=head[u];~i;i=nxt[i]){
			int v=to[i];
			q.push(v);dis[v]=min(dis[v],dis[u]+1);
		}
	}
	int ma=0;
	for(int i=0;i<n;i++)ma=max(ma,dis[i]);
	return ma;
}

void solve(){
	int n,k;
	cin>>n>>k;
	cur=0;
	for(int i=0;i<n;i++)head[i]=-1;
	for(int i=1;i<n;i++){
		int u,v;cin>>u>>v;
		u--,v--;
		add(u,v),add(v,u);
	}
	int ans=1e9;
	for(int i=0;i<(1<<n);i++){
		clear(n);
		int cnt=0;
		for(int j=0;j<n;j++)cnt+=(i>>j)&1;
		if(cnt!=k)continue;
		for(int j=0;j<n;j++){
			if((i>>j)&1){
				for(int k=head[j];~k;k=nxt[k]){
					int v=to[k];
					if((i>>v)&1){
						int fj=find_anc(j),fv=find_anc(v);
						if(fj==fv)continue;
						fa[fv]=fj;
					}
				}
			}
		}
		bool fl=1;
		int x=-1,y=-1;
		for(int j=0;j<n;j++){
			if((i>>j)&1){
				int fj=find_anc(j);
				if(x==fj)continue;
				else if(x==-1)x=fj;
				else{
					if(y==-1)y=fj;
					else if(y==fj)continue;
					else{
						fl=0;break;
					}
				}
			}
		}
		if(!fl)break;
		ans=min(bfs(i,n),ans);
//		cout<<i<<" "<<bfs(i,n)<<"\n";
	}
	cout<<ans<<"\n";
}

int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int c,t;
	cin>>c>>t;
	while(t--)solve();
}
