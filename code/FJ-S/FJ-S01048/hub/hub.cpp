#include<bits/stdc++.h>
using namespace std;
/*
int vis[1000005],dt[1000005],jp[1000005][21];
void dfs(vector<int>&adj[],int x){
	for(int j=1;j<=20;j++){
		jp[x][j]=jp[jp[x][j-1]][j-1];
	}
	for(int i:adj[x]){
		if(!vis[i]){
			dt[i]=dt[x]+1,dp[i][0]=x;
			dfs(i);
		}
	}
}
void lca(vector<int>&adj,int& dt[],int& jp[][],int x,int y){
	if(dt[x]<dt[y]){
		swap(x,y); 
	}
	int dtx=dt[x],dty=dt[y];
	for(int i=20;i>=0;i--){
		if(dt[jp[x][i]]<=dt[y]){
			x=jp[x][i];
		}
	}
	if(x==y){
		return dtx-dty;
	}
	for(int i=20;i>=0;i--){
		if(jp[x][i]!=jp[y][i]){
			x=jp[x][i],y=jp[y][i];
		}
	}
	return (dtx-dt[jp[x][0]])+(dty-dt[jp[y][0]]);
*/
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int c,t;
	cin>>c>>t;
	while(t--){
		int n,k,ans[1000005];
		vector<int>adj[1000005];
		//memset(dt,0,sizeof(dt));
		//memset(jp,0,sizeof(jp));
		memset(ans,0,sizeof(ans));
		cin>>n>>k;
		if(n==k){
			cout<<"0\n";
			continue;
		}
		/*
		for(int i=1;i<=n;i++){
			int u,v;
			cin>>u>>v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		dt[1]=1,jp[1][0]=1;
		dfs(adj,1,vis,dt,jp);
		for(int i=1;i<n;i++){
			for(int j=i+1;j<=n;j++){
				int nw=lca(i,j);
				for(int ck=1;ck<=k+1;ck++){
					if(nw>ans[ck]){
						for(int nk=ck+1;nk<=k+1;nk++){
							ans[nk]=ans[nk-1];
						}
						ans[ck]=nw;
						break;
					}
				}
			}
		}
		cout<<ans[k+1]<<'\n';
		*/
	}
	return 0;
}
