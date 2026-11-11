#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=20;
int a[N];
struct Edge{
	int to,nxt;
}edge[N<<1];
int head[N],cnt=0;
void add(int u,int v){
	edge[++cnt].to=v,edge[cnt].nxt=head[u],head[u]=cnt;
}
int n,k,ans=1e18;
int dis[N][N];
int tg[N];
int fa[N];
int find(int x){
	if(fa[x]==x)return x;
	return fa[x]=find(fa[x]);
}
void dfs(int now,int cc){
	if(now==n+1){
		if(cc!=k)return;
		for(int i=1;i<=n;i++)fa[i]=i;
		for(int i=1;i<=n;i++){
			if(!tg[i])continue;
			for(int j=head[i];j;j=edge[j].nxt){
				int v=edge[j].to;
				if(!tg[v])continue;
				if(find(i)!=find(v))fa[find(v)]=find(i);
			}
		}
		int po=0;
		for(int i=1;i<=n;i++)if(tg[i]&&fa[i]==i)po++;
		if(po>2)return;
//		cout<<"state:\n";
//		for(int i=1;i<=n;i++)cout<<tg[i]<<" ";
//		cout<<"\nfa:";
//		for(int i=1;i<=n;i++)cout<<fa[i]<<" ";
//		cout<<"\n";
		int maxn=0;
		for(int i=1;i<=n;i++){
			if(tg[i])continue;
			int mm=1e18;
			for(int j=1;j<=n;j++){
				if(i==j||!tg[j])continue;
				mm=min(mm,dis[i][j]);
			}
//			cout<<i<<"~~~"<<mm<<"\n";
			maxn=max(maxn,mm);
		}
//		cout<<"maxn:"<<maxn<<"\n"; 
		ans=min(ans,maxn);
		return;
	}
	tg[now]=1;
	dfs(now+1,cc+1);
	tg[now]=0;
	dfs(now+1,cc);
}
void work(){
	cin>>n>>k;ans=1e18;
	for(int i=1;i<=n;i++)head[i]=0;cnt=0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++)dis[i][j]=1e18;
		dis[i][i]=0;
		tg[i]=0;
	}
	for(int i=1,u,v;i<n;i++)cin>>u>>v,add(u,v),add(v,u),dis[u][v]=dis[v][u]=1;
	for(int p=1;p<=n;p++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				dis[i][j]=min(dis[i][j],dis[i][p]+dis[p][j]);
			}
		}
	}
//	for(int i=1;i<=n;i++){
//		for(int j=1;j<=n;j++){
//			cout<<i<<" "<<j<<":"<<dis[i][j]<<"\n";
//		}
//	}
	dfs(1,0);
	cout<<ans<<"\n";
}
signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int c,T;cin>>c>>T;
	while(T--)work();
	return 0;
} 
/*
0 2
5 2
1 2
2 3
3 4
4 5
10 3
1 2
1 3
2 4
2 5
3 6
3 7
3 8
7 9
9 10
*/
