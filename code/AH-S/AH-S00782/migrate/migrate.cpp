#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int c,T;
int n;
ll d;
ll x[2000005];
ll dis[5005][5005];
bool vis[5005][5005];
int ans,cnt;
void dfs(int u,int v,int x,int y){
	if(x>dis[y][v])return ;
	if(u==v){
		if(dis[y][v]==x)ans++;
		return ;
	}
	for(int i=1;i<=n;i++){
		if(i==u)continue;
		if(vis[u][i])dfs(i,v,x+1,y);
	}
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>T;
	while(T--){
		cnt=0;
		memset(x,0,sizeof(x));
		memset(vis,0,sizeof(vis));
		memset(dis,0x3f,sizeof(dis));
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>x[i];
		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				if(abs(x[j]-x[i])<=d)dis[i][j]=dis[j][i]=1,vis[i][j]=vis[j][i]=1;
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(i==j)continue;
				for(int k=1;k<=n;k++){
					if(k==i || k==j)continue;
					dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
				}
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				if(dis[i][j]==0x3f3f3f3f)continue;
//				cout<<i<<","<<j<<" "<<dis[i][j]<<"\n";
				ans=0;
				dfs(i,j,0,i);
				if(ans==2){
					cnt++;
//					cout<<i<<" "<<j<<"\n";
				}
			}
		}
		cout<<cnt<<"\n";
	}
	return 0;
} 
