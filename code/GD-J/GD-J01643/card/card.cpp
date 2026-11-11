#include<iostream>
#include<vector>
#include<unordered_map> 
#include<utility>
using namespace std;

const int M = 5e5 + 10;
int a[M];
int ans[M];

int main(){
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int n, m; // 牌的数量和点数种类数
	cin >> n >> m;
	for(int i = 1; i <= n; i++) cin >> a[i];
	
	// 开始游戏
	for(int i = 1; i <= n; i++){
		vector<int> cur;
		//vector<pair<int, int>> del;
		int pos[M];
		for(int j = 0; j < M; j++){
			pos[j] = -1;
		}
		for(int j = i; j <= n; j++){
			if(pos[a[j]] != -1){
				//cout << "由于已经出现了 " << a[j] << "在位置"<< pos[a[j]] << " 我要删除"<< endl; 
				cur.erase(cur.begin() + pos[a[j]], cur.begin() + (int)cur.size());
				for(int k = pos[a[j]]; k < (int)cur.size(); k++) pos[k] = -1;
				//for(int k = i; k <= n; k++) cout << pos[a[k]] << ' ';
				//cout << endl;
				pos[a[j]] = -1;
			}
			cur.push_back(a[j]);
			pos[a[j]] = (int)cur.size() - 1;
			//
			//cout << "当前局势：" ;
			//cout << endl;
			//
		}
		for(auto it : cur){
			//cout << "在第" << i << "局，" << it << "存在" << endl; 
			ans[it]++;
		}
	} 
	
	for(int i = 1; i <= m; i++){
		cout << ans[i] << ' ';
	}
	
	return 0;
}
