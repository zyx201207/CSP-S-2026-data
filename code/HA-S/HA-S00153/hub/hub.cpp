#include<bits/stdc++.h>
using namespace std;
int c,t,n,k,pre[200100],l,ans;
int cmp[200100];
struct fun{
	int to,ne;
}ms[200100];
void add(int u,int v){
	ms[++l]={v,pre[u]},pre[u]=l;
}
void DFS(int x){
	cmp[x]=2;
	for(int i=pre[x];i;i=ms[i].ne){
		int to=ms[i].to;
		if(cmp[to]==1)DFS(to);
	}
}
int ma;
int mp[1010][1010],X;
int dfs2(int x,int f){
	for(int i=pre[x];i;i=ms[i].ne){
		int to=ms[i].to;
		if(to==f)continue;
		mp[X][to]=mp[X][x]+1;
		dfs2(to,x);
	}
}
void check(){
	int cnt=0;
	//先判定是否恰好为两个联通块
	for(int i=1;i<=n;i++)if(cmp[i]==1){
		DFS(i),cnt++;
	}
	if(cnt>2){
		for(int i=1;i<=n;i++)if(cmp[i])cmp[i]=1;
		return;
	}
	ma=0;
	for(int i=1;i<=n;i++){
		int mi=INT_MAX;
		for(int j=1;j<=n;j++)if(cmp[j]){
			mi=min(mi,mp[i][j]);
		}
		ma=max(ma,mi);
	}
		for(int i=1;i<=n;i++)if(cmp[i])cmp[i]=1;
	ans=min(ans,ma);
}
void dfs1(int x,int L){
	if(x>n){
		check();
		return;
	}
	cmp[x]=0;
	dfs1(x+1,L);
	cmp[x]=1;
	if(L)dfs1(x+1,L-1);
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	scanf("%d%d",&c,&t);
	while(t--){
		ans=999999;
		scanf("%d%d",&n,&k);l=0;
		memset(pre,0,sizeof pre);
		memset(cmp,0,sizeof cmp);
		for(int i=1,u,v;i<n;i++){
			scanf("%d%d",&u,&v);
			add(u,v),add(v,u);
		}
		for(int i=1;i<=n;i++)X=i,dfs2(i,0);
		dfs1(1,k);
		printf("%d\n",ans);
	}
	return 0;
}

