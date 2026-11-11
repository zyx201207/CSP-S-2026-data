#include<bits/stdc++.h>
using namespace std;
#define int long long
int c, t, n, k, f[25], dis[25], cnt, vis[25];
vector<int> vc[200005];
void dfs(int u){
	vis[u]=1;
	for(int i=0;i<vc[u].size();i++){
		int to=vc[u][i];
		if(f[to]==1&&vis[to]==0){
//			cout << u << "->" << to << endl;
			dfs(to);
		}
	}
}
void dfs1(int u){
	for(int i=0;i<vc[u].size();i++){
		int to=vc[u][i];
//		cout << u << "->" << to << endl;
		if(f[to]==1)continue;
		if(dis[to]>dis[u]+1){
//			cout << u << " " << to << endl;
			dis[to]=dis[u]+1;
			dfs1(to);
		}
	}
}
signed main(){
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	cin >> c >> t;
	while(t--){
		int ans=0, minn=LLONG_MAX;
		cin >> n >> k;
		for(int i=1;i<=n;i++)vc[i].clear();
		for(int i=1;i<n;i++){
			int x, y;
			cin >> x >> y;
			vc[x].push_back(y);
			vc[y].push_back(x);
		}
		for(int i=0;i<(1<<n);i++){
			memset(vis, 0, sizeof(vis));
			ans=0;
			int x=i, num=0, cnt=0;
			for(int j=1;j<=n;j++){
				dis[j]=LLONG_MAX;
				vis[j]=0;
				if(x%2==1){
					dis[j]=0;
					f[j]=1;
					num++;	
				}else f[j]=0;
				x/=2;
			}
//			cout << "A" << i << endl;
			
			if(num==k){
				for(int i=1;i<=n;i++){
					if(f[i]==1&&vis[i]==0){
						dfs(i);
						cnt++;
						
					}
				}
				if(cnt!=2)continue;
				
//				cout << "OK" << endl;
//				for(int i=1;i<=n;i++){
//					cout << dis[i] << " "; 
//				}
//				cout << endl;
				for(int i=1;i<=n;i++){
					if(f[i]==1){
						for(int j=0;j<vc[i].size();j++){
							if(f[vc[i][j]]==0){
								dfs1(i);
//								if(f[2]==1&&f[7]==1&&f[9]==1){
//									cout << i << ":" << endl;
//									for(int k=1;k<=n;k++){
//										cout << dis[k] << " "; 
//									}
//									cout << endl;
//								}
								
								break;
							}
						}
					}
				}
				for(int i=1;i<=n;i++){
					ans=max(ans, dis[i]);
				}
				minn=min(minn, ans);
			}
		}
		cout << minn << endl;	
	}
	return 0;
}
