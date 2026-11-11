// 24 pts
#include<bits/stdc++.h>
using namespace std;
const int N = 5e5 + 5, M = 3e5 + 5;
int n, m, a[N], ans[N];
int main(){
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	cin >> n >> m;
	for(int i = 1;i <= n;i++) cin >> a[i];
	for(int i = 1;i <= n;i++){
		vector<int> card;
		for(int j = i;j <= n;j++){
			auto res = find(card.begin(), card.end(), a[j]);
			if(res != card.end()) card.erase(res, card.end());
			card.push_back(a[j]);
		}
		for(int j = 0;j < card.size();j++) ans[card[j]]++;
	}
	for(int i = 1;i <= m;i++) cout << ans[i] << " ";
	return 0;
}
