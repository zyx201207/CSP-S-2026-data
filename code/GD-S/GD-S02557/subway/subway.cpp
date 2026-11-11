#include<bits/stdc++.h> 
#define int long long

using namespace std;


const int M = 5e5 + 5;
const long long INF = 1e9;
int c,n,m,d,qq;


int w[M];


vector<pair<int,int>> E[M * 50];
int vis[M * 50];
int dis[M * 50];

int tag;
int no[505],t[505];
signed main(){
	
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	
//	cout << 1;
	cin >> c >> n >> m >> d >> qq;
	for(int i = 1;i <= m;i ++){
		cin >> w[i] ;
	}
	tag = m + 1;
	for(int i = 1;i <= n;i ++){
		int k;
		cin >> k;
		for(int j = 1;j <= k;j ++){
			cin >> no[j] >> t[j];
		}
		for(int j = 1;j <= k;j ++){
			E[tag].push_back({no[j],t[j]});
			E[no[j]].push_back({tag,t[j]});
			
			
			if(j == 1) E[tag].push_back({tag + 1,0});
			else if(j == k) E[tag].push_back({tag - 1,0});
			else{
				E[tag].push_back({tag + 1,0});
				E[tag].push_back({tag - 1,0});
			}
			tag ++;
		}
	}
//	for(int i = 1;i < tag;i ++){
//		cout << i << '*' << ' ' ;
//		for(auto u : E[i]){
//			cout << u.first << ' ' << u.second << ' ';
//		}
//		cout << endl;
//	}
	
	while(qq --){
		int s,e;
		cin >> s >> e;
		priority_queue<pair<int,int>> q;
		
		for(int i = 1;i < tag;i ++){
			vis[i] = 0;
			dis[i] = 1e17;
		}
		q.push({0,s});
		dis[s] = 0;
		
		while(!q.empty()){
			int thd = (0 - q.top().first);
			int thi = q.top().second;
			q.pop();
			
			if(vis[thi]) continue;
			vis[thi] = 1;
			
			for(auto u : E[thi]){
				if(thd + u.second < dis[u.first]){
					dis[u.first] = thd + u.second;
					q.push({-dis[u.first],u.first});
				}
			}
		}
		cout << dis[e] + w[s] + w[e] << endl;
	}
	return 0;
}
/*
0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3
*/
