#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5+100;
long long n,k,dis[maxn];
vector<int>g[maxn];
void dfs(int cur,long long st,int fa){
	dis[cur] = min(dis[cur],st);
	int siz = g[cur].size();
	for(int i = 0;i<siz;i++){
		int nxt = g[cur][i];
		if(nxt == fa)continue;
		dfs(nxt,st+1,cur);
	}
}
int main(){
	freopen("hub.in","r",stdout);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);	
	int c,t,x,y;
	cin>>c>>t;
	while(t--){
		cin>>n>>k;
		for(int i = 1;i<=n;i++)g[i].clear();
		for(int i = 1;i<n;i++){
			cin>>x>>y;
			g[x].push_back(y);
			g[y].push_back(x);
		}
		long long ma = INT_MAX;
		memset(dis,0x3f,sizeof(dis));
		if(k == 1){
			for(int i = 1;i<=n;i++){
				dfs(i,0,0);
				long long ans = 0;
				for(int l = 1;l<=n;l++)ans = max(ans,dis[l]);
				ma = min(ma,ans);
				memset(dis,0x3f,sizeof(dis));				
			}
			cout<<ma<<'\n';
		}else if(k == 2){
			for(int i = 1;i<=n;i++){
				for(int j = i+1;j<=n;j++){
					dfs(i,0,0);
					dfs(j,0,0);
					long long ans = 0;
					for(int l = 1;l<=n;l++)ans = max(ans,dis[l]);
					ma = min(ma,ans);
					memset(dis,0x3f,sizeof(dis));
				}
			}
			cout<<ma<<'\n';
		}else if(k == 3){
			for(int i = 1;i<=n;i++){
				for(int j = i+1;j<=n;j++){
					for(int k = j+1;k<=n;k++){
						dfs(i,0,0);
						bool flag = 0;
						for(int l = 1;l<=n;l++){
							if(dis[j] != 1 && dis[k] != 1)flag = 1;
						}
						if(flag){
							memset(dis,0x3f,sizeof(dis));
							continue;
						}
						dfs(j,0,0);
						dfs(k,0,0);
						long long ans = 0;
						for(int l = 1;l<=n;l++)ans = max(ans,dis[l]);
						ma = min(ma,ans);
						memset(dis,0x3f,sizeof(dis));
					}
				}
			}
			cout<<ma<<'\n';
		}else if(k == 4){
			for(int i = 1;i<=n;i++){
				for(int j = i+1;j<=n;j++){
					for(int k = j+1;k<=n;k++){
						for(int ii = k+1;ii<=n;ii++){
							dfs(i,0,0);
							bool flag = 0;
							for(int l = 1;l<=n;l++){
								if(dis[j] != 1 && dis[k] != 1 && dis[ii] != 1)flag = 1;
							}
							if(flag){
								memset(dis,0x3f,sizeof(dis));
								continue;
							}
							dfs(j,0,0);
							dfs(k,0,0);							
							dfs(ii,0,0);
							long long ans = 0;
							for(int l = 1;l<=n;l++)ans = max(ans,dis[l]);
							ma = min(ma,ans);
							memset(dis,0x3f,sizeof(dis));
						}
					}
				}
			}
			cout<<ma<<'\n';
			for(int i = 1;i<=n;i++){
				for(int j = i+1;j<=n;j++){
					for(int k = j+1;k<=n;k++){
						for(int ii = k+1;ii<=n;ii++){
							for(int ij = ii+1;ij<=n;ij++){
								dfs(ij,0,0);
								bool flag = 0;
								for(int l = 1;l<=n;l++){
									if(dis[j] != 1 && dis[k] != 1 && dis[i] != 1 && dis[ii] != 1)flag = 1;
								}
								memset(dis,0x3f,sizeof(dis));
								if(flag){
									continue;
								}
								dfs(ii,0,0);
								dfs(k,0,0);
								dfs(i,0,0);
								dfs(j,0,0);
								long long ans = 0;
								for(int l = 1;l<=n;l++)ans = max(ans,dis[l]);
								ma = min(ma,ans);
								memset(dis,0x3f,sizeof(dis));
							}
						}
					}
				}
			}
			cout<<ma<<'\n';
		}
	}
	return 0;
} 
/*
0 2
5 2
1 2
2 3
3 4
4 5
10 3
1 2
1 3
2 4
2 5
3 6
3 7
3 8
7 9
9 10

*/
