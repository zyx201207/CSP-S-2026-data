#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=5005;
int c,t,n,d,a[maxn],dis[maxn][maxn],his[maxn][maxn],ans;
bool vis[maxn];
/*
void dijkstra(int s){
	dis[s][s]=0;
	priority_queue<PII,vector<PII>,greater<PII> >q;
	q.push({0,s});
	while(!q.empty()){
		int u=q.top().second;
		int v=q.top().first;
		q.pop();
		for(int i=1;i<=n;i++){
			
		}
	}
}*/
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		memset(dis,0,sizeof(dis));
		ans=0;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(abs(a[i]-a[j])>d)dis[i][j]=INT_MAX;
				else dis[i][j]=1;
			}
		}
		dis[1][1]=0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				for(int k=1;k<=n;k++){
					if(min(dis[i][k],dis[i][j]+dis[j][k])==dis[i][k]){
						ans++;
					}
					dis[i][k]=min(dis[i][k],dis[i][j]+dis[j][k]);
				}
			}
		}/*
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(his[i][j]==dis[i][j]){
					ans++;
					his[i][j]=-1;
				}else if(his[i][j]!=-1){
					his[i][j]=dis[i][j];
				}
			}
		}*/
		cout<<ans;
	}
	return 0;
}

