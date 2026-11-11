#include <bits/stdc++.h>
using namespace std;
int x[5005];
int dis[5005][5005]; 
//咕咕嘎嘎 这长得好像多源最短路
//不对  为什么会有两条最短路  是我见得太少了吗
//还真是  我一个星期都没有刷题 
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	while(t--){
		int n,d;
		cin>>n>>d;
		for(int i = 1;i <= n; i++){
			int juli;
			cin>>juli;
			x[i] = juli;
		}
		for(int i = 1;i <= n; i++){
			for(int j = 1;j <= n;j++){
				dis[i][j] = dis[j][i] = x[j] - x[i];
			}
		}
		//居然是多测  孩子们我没救了 跳吧  
		//不对 好像可以写 有救了
		//忘记最短路怎么写了 好笑吗 很好笑 快来笑我 
		//遗迹： 
//		queue<int> q;
//		q.push(x[0]);
//		while(!q.empty()){
//			int u = q.top();
//			q.pop();
//		int afo = 0;
		for(int k = 1;k <= n;k++){
			for(int i = 1;i <= n;i++){
				for(int j = i+1;j <= n;j++){
					if(dis[i][k] + dis[k][j] <= dis[i][j] && dis[i][k] + dis[k][j] <= d){
						dis[i][j] = dis[i][k] + dis[k][j];
					}
				}
			}
		}int ans = 0;
		for(int k = 1;k <= n;k++){
			int cnt = 0;
			for(int i = 1;i <= n;i++){
				for(int j = i+1;j <= n;j++){
					if(dis[i][k] + dis[k][j] == dis[i][j]){
						cnt++;
					}
				}
			}
			if(cnt >= 2) ans++;
		}
		//我写了个集贸哦 不写了 
		cout<<ans<<endl;
	} 
	
	return 0;
}
