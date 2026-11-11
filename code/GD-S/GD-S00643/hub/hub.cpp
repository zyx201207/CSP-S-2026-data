#include<bits/stdc++.h>
#define ll long long
using namespace std;

const int MaxN=4e3+100;

int c,t,n,k,tmp;
struct EDGE{
	int nxt,to;
}edge[MaxN*2];
int head[MaxN],fa[MaxN];
ll dis[MaxN][MaxN];
bool b[MaxN];
void add(int u,int v){
	edge[++tmp].to=v;
	edge[tmp].nxt=head[u];
	head[u]=tmp;
}

int find(int x){
	return fa[x]=(fa[x]==x?x:find(fa[x]));
}
void merge(int x,int y){
	x=find(x),y=find(y);
	if(x==y)return ;
	fa[x]=y;
}

bool check(int s){
	int sum=0;
	for(int i=1;i<=n;i++){
		b[i]=((s>>(i-1))&1);
		sum+=b[i];
	}
	if(sum!=k)return false;
	for(int i=1;i<=n;i++)fa[i]=i;
	for(int u=1;u<=n;u++){
		if(!b[u])continue;
		for(int i=head[u];i;i=edge[i].nxt){
			int v=edge[i].to;
			if(b[v])merge(u,v); 
		}
	}
	sum=1;
	for(int i=1;i<=n;i++){
		if(!b[i])continue;
		for(int j=i+1;j<=n;j++){
			if(!b[j])continue;
			if(find(i)!=find(j))sum++,merge(i,j);
		}
	}
	return sum<=2;
}

void dfs(int s,int u,int f){
	for(int i=head[u];i;i=edge[i].nxt){
		int v=edge[i].to;
		if(v==f)continue;
		dis[s][v]=dis[s][u]+1;
		dfs(s,v,u);
	}
}

int main(){
	ios::sync_with_stdio(false);
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	
	cin>>c>>t;
	while(t--){
		cin>>n>>k;
		tmp=0;
		memset(head,0,sizeof(head));
		for(int i=1;i<n;i++){
			int u,v;
			cin>>u>>v;
			add(u,v);
			add(v,u);
		}
		for(int i=1;i<=n;i++)dfs(i,i,0);
		ll ans=1e18;
		for(int s=0;s<(1<<n);s++){
			if(check(s)){
				ll maxs=0;
				for(int i=1;i<=n;i++){
					if(b[i])continue;
					ll sum=1e18;
					for(int j=1;j<=n;j++){
						if(b[j])sum=min(sum,dis[i][j]);
					}
					maxs=max(maxs,sum);
				}
				ans=min(ans,maxs);
			} 
		}
		cout<<ans<<"\n";
	}
	
	return 0;
} 
