#include<bits/stdc++.h>
using namespace std;


int c,t,n,d;
int x[5005];
int cnt[5005][5005],cntt[5005][5005];
int vis[5005];
int tim[5005];
void bfs(int l){
	queue<int> q;
	q.push(l);
	vis[l]=0;
	tim[l]++;
	while(!q.empty()){
		int u=q.front();
		q.pop();
		for(int i=u+1;i<=n;i++){
			if(x[i]-x[u]>d)break;
			if(vis[i]<vis[u]+1)continue;
			q.push(i);
			tim[i]+=tim[u];
			vis[i]=vis[u]+1;
		}
	}
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		int ans=0;
		cin>>n>>d;
		for(int i=1;i<=n;i++)cin>>x[i];
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				cnt[i][j]=cntt[i][j]=1e9;
			}
		}
		for(int i=1;i<=n;i++){
			for(int a=1;a<=n;a++){
				tim[a]=0;
				vis[a]=1e9;
			}
			bfs(i);
			for(int j=1;j<=n;j++){
				if(vis[j]<cnt[i][j]){
					cnt[i][j]=vis[j];
					cntt[i][j]=tim[j];
				}
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(cntt[i][j]==2)ans++;
				//cout<<cntt[i][j]<<" ";
			}
			//cout<<endl;
		}
		cout<<ans<<"\n";
	}
	return 0;
}
