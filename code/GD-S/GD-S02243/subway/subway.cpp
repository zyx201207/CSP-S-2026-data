#include<bits/stdc++.h>
using namespace std;
const int inf=1e9+1;
const int M=1e3+1;
int a[500005];
int g[M][M];
int que[M][M];
vector<int> G[M];
struct dit{
	int id[21]={};
	int ti[21]={};
	int tot=0;
}t[501];
int dis[M];
bool vis[M];
int ans=0;
bool cmp(int x,int y){
	return dis[x]<dis[y];
}
void dfs(int s,int e){
	if(s==e||vis[s]){
		return;
	}
	//out<<s<<"\n";
	vis[s]=1;
	for(int i=0;i<G[s].size();i++){
		dis[G[s][i]]=min(g[s][G[s][i]]+dis[s],dis[G[s][i]]);
	}
	sort(G[s].begin(),G[s].end(),cmp);
	for(int i=0;i<G[s].size();i++)dfs(G[s][i],e);
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		cin>>t[i].tot;
		for(int j=1;j<=t[i].tot;j++){
			cin>>t[i].id[j]>>t[i].ti[j];
		}
		for(int j=1;j<=t[i].tot;j++){
			for(int k=j+1;k<=t[i].tot;k++){
				if(g[t[i].id[j]][t[i].id[k]]==0){
					G[t[i].id[j]].push_back(t[i].id[k]);
					G[t[i].id[k]].push_back(t[i].id[j]);
					g[t[i].id[j]][t[i].id[k]]=t[i].ti[j]+t[i].ti[k];
					g[t[i].id[k]][t[i].id[j]]=t[i].ti[j]+t[i].ti[k];	
				}
				else{
					g[t[i].id[j]][t[i].id[k]]=min(g[t[i].id[j]][t[i].id[k]],t[i].ti[j]+t[i].ti[k]);
					g[t[i].id[k]][t[i].id[j]]=min(g[t[i].id[k]][t[i].id[j]],t[i].ti[j]+t[i].ti[k]);
				}
			}
		}
	}
//	for(int i=1;i<=m;i++){
//		for(int j=0;j<G[i].size();j++){
//			cout<<G[i][j]<<" ";
//		}
//		cout<<endl;
//	}
	for(int i=1;i<=q;i++){
		int st,en;
		cin>>st>>en;
		if(que[st][en]!=0){
			cout<<que[st][en]<<endl;
			continue;
		}
		for(int j=1;j<=m;j++) dis[j]=inf,vis[j]=0;
		dis[st]=0;
		dfs(st,en);
		cout<<dis[en]+a[st]+a[en]<<endl;
		que[st][en]=dis[en]+a[st]+a[en];
	}
	return 0;
}
