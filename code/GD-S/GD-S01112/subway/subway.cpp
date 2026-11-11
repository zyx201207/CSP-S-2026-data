#include <bits/stdc++.h>
#define i64 long long
using namespace std;
const int N = 505, M = 5e5+5;
i64 w[M];

struct tedge{
	int to;
	i64 sz;
};
vector<tedge> v[M]; 

i64 dis[N][N];

int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr); 
	
	int c, n, m, d, q;
	cin >> c >> n >> m >> d >> q;
	
	for(int i = 1;i <= m;i++){
		cin >> w[i];
	}
	for(int i = 1;i <= n;i++){
		int k;
		cin >> k;
		while(k--){
			int a;
			i64 t;
			cin >> a >> t;
			v[a].push_back({i, t});
		}
	}
	
	memset(dis, 0x3f, sizeof dis);
	
	for(int i = 1;i <= m;i++){
		for(int j = 0;j < v[i].size();j++){
			for(int k = j+1;k < v[i].size();k++){
				int tj = v[i][j].to, tk = v[i][k].to;
				i64 szj = v[i][j].sz, szk = v[i][k].sz;
				dis[tj][tk] = min(dis[tj][tk],szj+szk);
				dis[tk][tj] = min(dis[tk][tj],szj+szk);
			}
		}
	}
	
	for(int i = 1;i <= n;i++) dis[i][i] = 0;
	
	for(int k = 1;k <= n;k++){
		for(int i = 1;i <= n;i++){
			for(int j = 1;j <= n;j++){
				if(i!=j) dis[i][j] = min(dis[i][j],dis[i][k]+dis[k][j]);
			}
		}
	}
	
	while(q--){
		int x, y;
		cin >> x >> y;
		
		i64 ans = LLONG_MAX;
		
		for(int i = 0;i < v[x].size();i++){
			for(int j = 0;j < v[y].size();j++){
				int tj = v[x][i].to, tk = v[y][j].to;
				i64 szj = v[x][i].sz, szk = v[y][j].sz;
				ans = min(ans,szj+szk+dis[tj][tk]);
			}
		}
		
		cout << ans + w[x] + w[y] << "\n";
	} 
}
/*
对于每一条line跑一个到其他所有line的最短路
然后对于每一次询问d^2找出最短的il, ol搭配
哦！！！使用floyd即可过这题 
*/
