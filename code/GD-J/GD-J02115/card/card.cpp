#include <bits/stdc++.h>
using namespace std;

int n, m;
int a[(int)5e5+4];
bool vis[(int)3e5+4];
int ans[(int)3e5+4];
int main(){
	//freopen("card.in", "r", stdin);
	//freopen("card.out", "w", stdout);
	cin >> n >> m;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
	}
	deque<int> dq;
	for(int i = 1; i <= n; i++){	//i表示从第i张牌开始用 
		memset(vis, 0, sizeof(vis));
		for(int j = i; j <= n; j++){	//遍历这一次游戏的牌 
			if(!vis[a[j]]) dq.push_back(j);
			else{
				while(a[dq.back()] != a[j])	//维护一个a[j]内仅出现一次的队列 
					dq.pop_back();
			}
		}/*
		for(int j = dq.front(); j <= dq.back(); j++)
			cout << 
			ans[a[j]]++;*/
		while(!dq.empty()){
			ans[a[dq.front()]]++;
			cout << a[dq.front()] << ' ';
			dq.pop_front();
		}
		cout << endl;
	}
	for(int i = 1; i <= m; i++)
		cout << ans[i] << ' ';
	return 0;
}
