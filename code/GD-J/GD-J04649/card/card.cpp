#include<bits/stdc++.h>
#define int long long
using namespace std;

int n, m;
int cards[1000000];
int ans[1000000];
vector<int> cur;
bool vis[1000000];

bool check(int st){
	for (int i = st;i <= n;i++){
		if (!vis[cards[i]]){
			cur.push_back(cards[i]);
			vis[cards[i]] = true;
		}else{
			bool flag = false;
			for (int i = 0;i < cur.size();i++){
				if (cur[i] == cards[i]) flag = true;
				if (flag){
					vis[cur[i]] = false;
					cur.erase(cur.begin() + i);
				}
			}
			cur.push_back(cards[i]);
			vis[cards[i]] = true;
		}
	}
	for (int i = 0;i < cur.size();i++){
		ans[cur[i]]++;
	}
	return false;
}

signed main(){
//	freopen("card.in", "r", stdin);
//	freopen("card.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1;i <= n;i++) cin >> cards[i];
	for (int i = 1;i <= n;i++){
		check(i);
	}
	for (int i = 1;i <= m;i++){
		cout << ans[i] << " ";
	}
}
