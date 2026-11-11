#include <bits/stdc++.h>
using namespace std;
const int max_=2e3+5;
int n,k,dis[max_][max_];
vector<int>v[max_];
bitset<max_>qwq,vis;
void dfs1(int x,int fa){
	vis[x]=1;
	for(int i:v[x]){
		if(i==fa){
			continue;
		}
		if(qwq[i]){
			dfs1(i,x);
		}
	}
}
signed main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int c,t;
	cin>>c>>t;
	if(c<=3){
		while(t--){
			int qwqans=2e9;
			cin>>n>>k;
			for(int i=1;i<=n;i++){
				v[i].clear();
			}
			for(int i=1;i<=n;i++){
				for(int j=1;j<=n;j++){
					dis[i][j]=0;
				}
			}
			qwq.reset();
			vis.reset();
			for(int i=1;i<n;i++){
				int x,y;
				cin>>x>>y;
				v[x].push_back(y);
				v[y].push_back(x);
				dis[x][y]=1;
				dis[y][x]=1;
			}
			for(int i=1;i<=n;i++){
				for(int j=1;j<=n;j++){
					if(i==j){
						dis[i][j]=0;
					}else if(dis[i][j]!=1){
						dis[i][j]=1e9;
					}
				}
			}
			for(int k=1;k<=n;k++){
				for(int i=1;i<=n;i++){
					for(int j=1;j<=n;j++){
						dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
					}
				}
			}
			for(int i=0;i<(1<<n);i++){
				qwq.reset();
				vis.reset();
				int t=0;
				for(int j=0;j<n;j++){
					if(i>>j&1){
						t++;
						qwq[j+1]=1;
					}
				}
				if(t!=k){
					continue;
				}
				int cnt=0;
				for(int j=1;j<=n;j++){
					if(qwq[j]&&!vis[j]){
						dfs1(j,0);
						cnt++; 
					}
				}
				if(cnt>2){
					continue;
				}
				int ans=0;
				for(int j=1;j<=n;j++){
					int tans=1e9;
					for(int k=1;k<=n;k++){
						if(qwq[k]){
							tans=min(tans,dis[j][k]);
						}
					}
					ans=max(ans,tans);
				}
				qwqans=min(qwqans,ans);
			}
			cout<<qwqans<<'\n'; 
		}
	}
	return 0;
}
