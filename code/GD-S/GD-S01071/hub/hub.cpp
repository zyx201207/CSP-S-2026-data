#include<bits/stdc++.h>
using namespace std;
int c,T;
int n,k;
int nxt[2000005],to[2000005],hd[1000005],cnt;
const int inf=(1e9);
void add(int u,int v){
	nxt[++cnt]=hd[u];
	to[cnt]=v;
	hd[u]=cnt;
}
int p[1000005],bzp[1000005];
bool bz[1000005];
void dfs(int x){
	bz[x]=1;
	for(int i=hd[x];i;i=nxt[i]){
		if(bz[to[i]]==1||bzp[to[i]]==0) continue;
		dfs(to[i]);
	}
}
int dis[4005][4005];
int get(int x){
	int ans=inf;
	for(int i=1;i<=n;i++){
		if(bzp[i]){
			ans=min(ans,dis[x][i]);
		}
	}
	return ans;
}
int ans=inf;
void dg(int x,int lst){
	if(x>k){
		for(int i=1;i<=n;i++) bz[i]=0;
		int cnt=0;
		for(int i=1;i<=k;i++){
			if(!bz[p[i]]){
				cnt++,dfs(p[i]);
			}
		}
		if(cnt>2) return;
		int ls=0;
		for(int i=1;i<=n;i++){
			if(bzp[i]==1) continue;
			ls=max(ls,get(i));
		}
//		if(ls==1)
//		{
//			for(int i=1;i<=k;I++){
//				
//			}
//		}
		ans=min(ans,ls);
		return;
	}
	for(int i=lst+1;i<=n;i++)
	{
		p[x]=i,bzp[i]=1;
		dg(x+1,i);
		bzp[i]=0;
	}
}
bool bzz[4005];
void bfs(int x)
{
	for(int i=1;i<=n;i++) dis[x][i]=inf,bzz[i]=0;
	dis[x][x]=0;
	queue<int>q;
	q.push(x);
	while(!q.empty()){
		int u=q.front();
		q.pop();
		bzz[u]=1;
		for(int i=hd[u];i;i=nxt[i]){
			if(bzz[to[i]]) continue;
			if(dis[x][to[i]]>dis[x][u]+1){
				dis[x][to[i]]=dis[x][u]+1;
				q.push(to[i]); 
			}
		}
	}
}
signed main(){
//	freopen("hub1.in","r",stdin);
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	scanf("%d%d",&c,&T);
	while(T--)
	{
		scanf("%d%d",&n,&k);
		for(int i=1;i<=n;i++) hd[i]=0;
		cnt=0;
		int in1,in2;
		for(int i=1;i<n;i++)
		{
			scanf("%d%d",&in1,&in2);
			add(in1,in2),add(in2,in1);
		}
		for(int i=1;i<=n;i++) bfs(i);
//		for(int i=1;i<=n;i++)
//		{
//			for(int j=i+1;j<=n;j++)
//			{
//				cout<<dis[i][j]<<" ";
//			}
//			cout<<endl<<endl;
//		}
		ans=inf;
		dg(1,0);
		printf("%d\n",ans);
	}
}
//0 1
//10 3
//1 2
//1 3
//2 4
//2 5
//3 6
//3 7
//3 8
//7 9
//9 10

