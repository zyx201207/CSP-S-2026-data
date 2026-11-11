#include<bits/stdc++.h>
using namespace std;
const int N=5000;
int n,d,c,t;
int x[N];
int dis[N][N],cnt[N][N];
bool vis[N][N];
void prim(){
	for(int i=1;i<=n;i++) dis[i][i]=0;
	for(int i=n;i>=1;i--){
		for(int j=n;j>=1;j--){
			for(int k=1;k<=n;k++){
				if(dis[i][j]==dis[i][k]+dis[k][j]){
					cnt[i][j]++;
				}else if(dis[i][j]>dis[i][k]+dis[k][j]){
					dis[i][j]=dis[i][k]+dis[k][j];
					cnt[i][j]=1;
				}
			}
		}
	}
	return;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		memset(dis,0x3f,sizeof(dis));
		memset(cnt,0,sizeof(cnt));
		memset(vis,0,sizeof(vis));
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>x[i];
			dis[i-1][i]=x[i]-x[i-1];
			dis[i][i-1]=x[i]-x[i-1];
		}
		prim();
		int ans=0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(cnt[i][j]==2&&dis[i][j]<=d&&vis[i][j]==0){
					vis[i][j]=1;
					vis[j][i]=1;
					ans++;
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
