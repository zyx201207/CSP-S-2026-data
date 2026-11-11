#include<bits/stdc++.h>
using namespace std;
#define int long long
#define N 505
#define M 100005
int n,m,c,d,q;
int w[N];
int num[M],v[M][N],t[M][N];
int valv[N],valw[N];
int dis[M];
bool vis[M];
bool vis_j[M];
struct NUM{
	int v,w;
};
vector <NUM> edge[M];
void djs(int start){
	for(int i=1;i<=n;i++){
		dis[i]=1e12+111;
		vis[i]=false;
		vis_j[i]=false;
	}
	vis[start]=true;
	dis[start]=0;
	for(int i=1;i<=n;i++){
		int j=-1,mn=1e12;
		for(int k=1;k<=n;k++){
			if(vis_j[k]) continue;
			if(dis[k]<mn){
				mn=dis[k];
				j=k;
			}
		}
		//cout<<j<<" "<<mn<<"\n";
		if(j==-1) return;
		vis_j[j]=true;
		for(auto [v,w] : edge[j]){
			if(vis[v]) continue;
			vis[v]==true;
			dis[v]=min(dis[v],dis[j]+w);
			//cout<<"   "<<v<<" "<<dis[v]<<"\n";
		}
	}
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>m>>n>>d>>q;
	for(int i=1;i<=n;i++) cin>>w[i];
	for(int i=1;i<=m;i++){
		cin>>num[i];
		for(int j=1;j<=num[i];j++) cin>>v[i][j]>>t[i][j];
	}
	for(int k=1;k<=m;k++){
		for(int i=1;i<=num[k];i++){
			for(int j=i+1;j<=num[k];j++){
				edge[v[k][i]].push_back({v[k][j],t[k][i]+t[k][j]});
				edge[v[k][j]].push_back({v[k][i],t[k][i]+t[k][j]});
			}
		}
	}
	while(q--){
		int u,v;
		cin>>u>>v;
		if(u>v) swap(u,v);
		djs(u);
		cout<<dis[v]+w[u]+w[v]<<"\n";
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 


