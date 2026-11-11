#include <bits/stdc++.h>
using namespace std;


int main(){
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	vector<pair<int, int>> a; // 数值，前驱 
	a.push_back({-1,-1});
	for (int i=1;i<=n;i++){
		int v;
		cin >> v;
		a.push_back({v,a[i-1].first});
	}
	int game=n;
	vector<int> ans(m+5,0); // 点数为i的留下次数 
	while(game--){
		// 进行game=n场游戏
		// 被改变前驱的下标集 
		queue<int> changed;
		int lastchanged=n-game;
		for (int i=n-game;i<=n;i++){
			// 一局游戏  第i张牌 
			int k = a[i].first;
			
			bool haved=false;
			for (int j=lastchanged;j<i;j++){
//				cout << a[j].first << "?=" << k << ",";
				if (a[j].first==k){
//					cout << a[j].first << "==" << k << " ";
					haved = true;
					break;
				}
			}
			if (haved) {
				// 把前面的都拿走 
				a[i].second=-1;
				changed.push(i);
				lastchanged=i;
			}
		}
//		if (changed.size()==0){
//			for (int)
//		}
//		cout << "————"; 
		for (int j=lastchanged;j<=n;j++){
//			cout << a[j].first<< " ";
			ans[a[j].first]++;
		}
//			cout << endl;	
		while(!changed.empty()){
			a[changed.front()].second=a[changed.front()-1].first;
//			cout << a[changed.front()].first << "的前面一个是" << a[changed.front()-1].first << " "; 
			changed.pop();
		}
//		for (int i=1;i<=n;i++){
//			cout << a[i].first << "," << a[i].second << " ";
//		}
//		cout << endl;
	}
	for (int i=1;i<=m;i++){
		cout << ans[i] << " ";
	}
} 
