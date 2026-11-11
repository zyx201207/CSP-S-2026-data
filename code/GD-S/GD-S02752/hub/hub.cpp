#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int ma=1e6+5;
ll dis[1005][1005];
int n,k;
bool c[ma],vis[ma];
vector<int>e[ma];
void dfs(int idx){
	vis[idx]=1;
	for(int i=0;i<e[idx].size();i++){
		if(c[e[idx][i]]&&!vis[idx])dfs(e[idx][i]);
	}
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	int C,T;
	cin>>C>>T;
	while(T--){
		cin>>n>>k;
		memset(dis,-1,sizeof(dis));
		for(int i=1;i<n;i++){
			dis[i][i]=0;
			int u,v;
			cin>>u>>v;
			dis[u][v]=dis[v][u]=1;
			e[u].push_back(v);
			e[v].push_back(u);
		}
		dis[n][n]=0;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int k=i+1;k<=j;k++){
					if(dis[i][k]>=0&&dis[k][j]>=0)dis[i][j]=dis[j][i]=dis[i][k]+dis[k][j];
				}
			}
		}
//		for(int i=1;i<=n;i++){
//			for(int j=1;j<=n;j++){
//				cout<<dis[i][j]<<" ";
//			}
//			cout<<"\n";
//		}
		ll num=1,ans=INT_MAX;
		for(int i=1;i<=n;i++)num*=2;
		for(int i=1;i<=num;i++){
//			cout<<i<<" ";
			int x=i,cnt=0;
			for(int j=1;j<=n;j++){
				c[n-j+1]=x%2;
				x/=2;
				if(c[n-j+1])cnt++;
			}
			if(cnt!=k)continue;
			cnt=0;
			bool flag=0;
			for(int j=1;j<=n;j++){
				if(c[j]&&!vis[j]){
					cnt++;
					if(cnt>2){
						flag=1;
						break;
					}
					dfs(j);
				}
			}
//			cout<<"mid\n";
			if(flag)continue;
			ll mx=0;
			for(int i=1;i<=n;i++){
				if(c[i])continue;
				for(int j=1;j<=n;j++){
					if(!c[j])continue;
					mx=max(mx,dis[i][j]);
				}
			}
			ans=min(ans,mx);
			
		}
		memset(vis,0,sizeof(vis));
		for(int i=1;i<=n;i++)e[i].clear();
		cout<<ans<<'\n';
	}
	return 0;
}
/*
*/
