#include<bits/stdc++.h>
using namespace std;
const int N=3100;
vector<int>e[N];
int fa[N];
int a[N],t[N],ans=1e9;
int len[N][N],dep[N],st[N][N],vis[N];
int n,k;
int find(int x){
	if(fa[x]==x)return x;
	return fa[x]=find(fa[x]);
}
void dfs1(int x,int y){
	if(x>=y){
		memset(t,0,sizeof(t));
		int f=0;
		for(int i=1;i<=k;i++){
			if(!t[fa[a[i]]])f++;
		}
		if(f<=2){
			int sum=0;
			for(int i=1;i<=n;i++){
				int num=0;
				for(int j=1;j<=k;j++){
					if(a[i]==a[j])continue;
					num=min(num,len[i][j]);
				}
				sum=max(sum,num);
			}
			ans=min(ans,sum);
		}
	}
	for(int i=1;i<=n;i++){
		if(!vis[i]){
			int lin[N];
			for(auto j:e[i]){
				int ii=find(i),jj=find(j);
				lin[j]=jj;
				if(ii!=jj)fa[jj]=ii;
			}
			vis[i]=1;
			dfs1(x+1,y);
			for(auto j:e[i]){
				int ii=find(i),jj=find(j);
				fa[jj]=lin[j];
			}
			vis[i]=0;
		}
	} 
}
void dfs2(int x,int de,int fa){
	st[0][x]=fa;
	dep[x]=de;
	for(auto i:e[x]){
		if(i!=fa)dfs2(i,de+1,x);
	}
}
int lca(int x,int y){
	if(dep[x]<dep[y])swap(x,y);
	int sum=0;
	for(int i=20;i>=0;i--){
		if(dep[x]-(1<<i)>=dep[y])x=st[x][i],sum+=(1<<i);
	}
	if(x==y)return sum;
	for(int i=20;i>=0;i--){
		if(st[x][i]!=st[y][i]){
			x=st[x][i];
			y=st[y][i];
			sum+=(1<<i)*2;
		}
	}
	sum+=2;
	return sum;
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int c,t;cin>>c>>t;
	while(t--){
		cin>>n>>k;
		for(int i=1;i<=n;i++)e[i].clear();
		for(int i=1;i<n;i++){
			int u,v;cin>>u>>v;
			e[u].push_back(v);
			e[v].push_back(u);
		}
		memset(vis,0,sizeof(vis));
		memset(dep,0,sizeof(dep));
		dfs2(1,1,0);
		for(int k=1;k<=20;k++){
			for(int i=1;i<=n;i++)st[i][k]=st[st[i][k-1]][k-1];
		}
		for(int i=1;i<=n;i++){
			for(int j=i;j<=n;j++){
				int num=lca(i,j);
				len[i][j]=num;
				len[j][i]=num;
			}
		}
		ans=1e9;
		dfs1(0,k);
		cout<<1<<'\n';
	}
	return 0;
}
