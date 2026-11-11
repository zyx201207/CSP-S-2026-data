//GZ-S00209 黄琨淇 安顺市实验学校 
#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,ans = 0x3f3f3f3f,w[50010],a[510][50010],t[510][50010],k[510];
int vis[510];
vector<pair<int,int> >T[510];
int fl[510][510];
vector<pair<int,int> >v[50010];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin >> c >> n >> m >> d >> q;
	for(int i = 1;i <= m;i++)cin >> w[i];
	for(int i = 1;i <= n;i++){
		cin >> k[i];
		for(int j = 1;j <= k[i];j++){
			cin >> a[i][j] >> t[i][j];
			for(int k = 0;k < v[a[i][j]].size();k++){
				int u = v[a[i][j]][k].first,tot = v[a[i][j]][k].second;
				if(!fl[i][u]){
					T[i].push_back({u , t[i][j] + t[u][tot]});
					T[u].push_back({i , t[i][j] + t[u][tot]});
					fl[u][i] = fl[i][u] = t[i][j] + t[u][tot];
				}else{
					T[i].push_back({u , min(t[i][j] + t[u][tot] , fl[u][i])});
					T[u].push_back({i , min(t[i][j] + t[u][tot] , fl[u][i])});
					fl[u][i] = fl[i][u] =  min(t[i][j] + t[u][tot] , fl[u][i]);
				}
			}
			v[a[i][j]].push_back({i,j});
		}
	}
	while(q--){
		int x,y;
		cin >> x >> y;
		int minn = 0x3f3f3f3f;
		for(int i = 0;i < v[x].size();i++){
			int st = v[x][i].first,tot = v[x][i].second;
			queue<int>q;
			memset(vis,0,sizeof(vis));
			ans = 0x3f3f3f3f;
			q.push(st);
			while(!q.empty()){
				int u = q.front();
				q.pop();
				for(int i = 0;i < v[y].size();i++){
					int en = v[y][i].first,tot2 = v[y][i].second;
					if(u == en){
						ans = min(ans,vis[u] + w[x] + t[st][tot] + w[y] + t[en][tot2]);
					}
				}
				for(int i = 0;i < T[u].size();i++){
					int v_ = T[u][i].first,lon = T[u][i].second;
					if(!vis[v_]){
						q.push(v_);
						vis[v_] = lon + vis[u];
					}
				}
			}
			minn = min(minn,ans);
		}
		cout << minn << endl;
	}
	return 0;
} 
