#include<bits/stdc++.h>
using namespace std;
const int N=15;
int n,k,dist[N][N],dt[N][N];
int d[N],ans[N],lss=1e9;
void dfs(int last,int x,int p){
	if(p>2) return ;
	if(x==k){
		memset(ans,0x3f,sizeof ans);
		for(int i=0;i<k;i++){
			for(int j=1;j<=n;j++){
				ans[j]=min(ans[j],dt[d[i]][j]);
			}
		}
		int sh=-99;
		for(int i=1;i<=n;i++) sh=max(sh,ans[i]);
		lss=min(lss,sh);
		return ;
	}
	for(int i=last+1;i<=n;i++){
		for(int j=0;j<x;j++){
			if(dist[j][i]) {
				d[x]=i;
				dfs(i,x+1,p);
				d[x]=0;
				break;
			}
		}
		d[x]=i;
		dfs(i,x+1,p+1);
		d[x]=0;
	}
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); 
	int c,t;
	cin>>c>>t;
	while(t--){
		lss=1e9;
		cin>>n>>k;
		memset(dist,0x3f,sizeof dist);
		memset(dt,0x3f,sizeof dt);
		for(int i=1;i<=n;i++) dist[i][i]=0;
		for(int i=1;i<n;i++){
			int u,v;
			cin>>u>>v;
			dist[u][v]=dist[v][u]=dt[u][v]=dt[v][u]=1;
		} 
		for(int mid=1;mid<=n;mid++){
			for(int i=1;i<=n;i++){
				for(int j=1;j<=n;j++){
					dt[i][j]=min(dt[i][j],dt[i][mid]+dt[mid][j]);
				}
			}
		}
		dfs(0,0,0);
		cout<<lss<<"\n";
	}
	return 0;
}
