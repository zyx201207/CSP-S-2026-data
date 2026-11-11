#include<bits/stdc++.h>
using namespace std;
#define int long long
int c,T;
int n,d;
const int N=305;
vector<int>vt[N];
int dis[N][N],cnt[N][N],vis[N];
queue<int>q;
void bfs(int s,int *dis,int *cnt){
	for(int i=1;i<=n;i++)vis[i]=0,dis[i]=1145141919810;
	for(int i=1;i<=n;i++)cnt[i]=0;
	while(!q.empty())q.pop();
	q.push(s);
	dis[s]=0;cnt[s]=1;
	vis[s]=1;
	while(!q.empty()){
		int u=q.front();
		q.pop();
		for(int v:vt[u]){
			if(vis[v]){
				if(dis[u]+1==dis[v])if(cnt[v]<=2)cnt[v]+=cnt[u];
				continue;
			}
			dis[v]=dis[u]+1;
			cnt[v]=cnt[u];
			vis[v]=1;
			q.push(v); 
		}
	}
	return;
}
int x[N];
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>c>>T;
	while(T--){
		cin>>n>>d;
		for(int i=1;i<=n;i++)vt[i].clear();
		for(int i=1;i<=n;i++)cin>>x[i];
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(i==j)continue;
				if(abs(x[i]-x[j])<=d){
					vt[i].push_back(j); 
				}
			}
		}
		for(int i=1;i<=n;i++)bfs(i,dis[i],cnt[i]);
		int ans=0;
		for(int i=1;i<=n;i++)
			for(int j=i+1;j<=n;j++)if(cnt[i][j]==2)ans++;
		cout<<ans<<'\n';
	}
	return 0;
}

