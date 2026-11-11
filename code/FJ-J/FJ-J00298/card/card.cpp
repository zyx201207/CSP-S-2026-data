#include<bits/stdc++.h>
using namespace std;

int n, m;//n:游戏的局数和牌数 m:拍的种类数量
int cards[500005] = {};//cards[i] -> 编号为i的卡牌的点数 
int ans[300005] = {};//ans]i] -> 点数为i的牌有几局游戏在结束时留在桌上 
bool where[300005] = {};//where[i] -> 点数为i的牌是否在桌面上
stack<int>s;//s:桌面上的牌 
	
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	
	cin >> n >> m;
	for(int i = 1; i <= n; i++){
	 	cin >> cards[i];
	}
	
	
	for(int t = 1; t <= n; t++){
		fill(where, where + 300005, false);
		
		for(int i = t; i <= n; i++){
			if(!where[cards[i]]){
				s.push(cards[i]);
				where[cards[i]] = true;
			}
			if(where[cards[i]]){
				while(s.top() != cards[i]){
					where[s.top()] = false;
					s.pop();
				}
			}
		}
		
		while(!s.empty()){
			ans[s.top()]++;
			s.pop();
		}
	}
	
	for(int i = 1; i <= m; i++){
		cout << ans[i] << ' ';
	}
	
	return 0;
}
