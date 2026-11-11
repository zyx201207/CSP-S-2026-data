#include <bits/stdc++.h>
using namespace std;
int w[505];//每个地铁站的地铁口走到站厅需要的时间
int xian[505][50005];//每条线路经过的站点
int zhan[505];//每条线路经过的站点和
int t[505][50005];//t[i][j]表示i线路到j站点展厅
vector <pair<int,int>> v[50005]; 
int road[500005];//到站台 
priority_queue<pair<int,int>>q;
int d;
int en;
int w1;
void dij(){
	while(!q.empty()){
		int now = q.top().first;
		int noww = q.top().second; 
		q.pop();
		for(int i=0;i<v[now].size();i++){
			int u = v[now][i].first;//点
			int w = v[now][i].second;//路线
			int sum = road[now] ;
			if(noww ==0){
				sum += t[w][now];
			}else if(noww != w){
				//cout << now << " " << u << " " << sum << endl;
				sum +=t[w][now]+t[noww][now];
			}
			//cout << sum << endl;
			/*
			if(u==en){
				sum+=t[w][u];
			}
			*/
			if(sum<road[u]){
				//cout << now << " " << u << " " << sum << endl;
				if(u==en){
					w1 = w;
				}
				road[u] = sum;
				q.push({u,w});
			}
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int c,n,m,d,p;
	cin >> c >> n >> m >> d >> p;
	for(int i=1;i<=m;i++){
		cin >> w[i];
	} 
	for(int i=1;i<=n;i++){
		cin >> zhan[i];
		for(int j=1;j<=zhan[i];j++){
			cin >> xian[i][j];
			cin >> t[i][j];
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=zhan[i];j++){
			if(j==1){
				v[xian[i][j]].push_back({xian[i][j+1],i});
			}else if(j==zhan[i]){
				v[xian[i][j]].push_back({xian[i][j-1],i});
			}else{
				v[xian[i][j]].push_back({xian[i][j+1],i});
				v[xian[i][j]].push_back({xian[i][j-1],i});
			}
		}
	}
	/* 
	for(int i=1;i<=m;i++){
		for(int j=0;j<v[i].size();j++){
			cout << v[i][j] << " ";
		}
		cout << endl;
	}
	*/
	while(p--){
		for(int i=1;i<=500005;i++){
			road[i] = 1e9;
		}
		cin >> d >> en;
		q.push({d,0});
		//cout << road[d] << endl;
		road[d]=w[d];
		dij();
		/*
		for(int i=1;i<=m;i++){
			cout << road[i] << endl ;
		}
		*/
		cout << road[en]+w[en] +t[w1][en]<< "\n";
	}
	return 0;
} 
/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2
 
0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3
*/
