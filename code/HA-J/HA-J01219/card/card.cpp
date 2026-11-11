#include <bits/stdc++.h>
using namespace std;

stack<int> a;
vector<int> into_;

int main(){
	freopen("card1.in", "r", stdin);
	freopen("card.out", "w", stdout);
//	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	int n, m; cin >> n >> m;
	bool card_[m+5];
	for (int j=0; j<m; j++) card_[j]=0;
	for (int i=0; i<n; i++){
		int x; cin >> x;
		into_.push_back(x);
	}
	
	int ans[m+5];
	for (int j=0; j<m; j++) ans[j]=0;
	for (int i=0; i<n; i++){
		for (int j=i; j<n; j++){
			if (card_[into_[j]]){
				int x=-1;
				while(x!=into_[j]){
					x = a.top(); a.pop();
				}
			}
			a.push(into_[j]);
			card_[into_[j]] = 1;
		}
		for (int j=0; j<m; j++) card_[j]=0;
		bool ttt = a.empty();
		while(!ttt){
			ttt=a.empty();
			int u = a.top();
			a.pop();
			ans[u]++;
		}
	}
	
	for (int i=1; i<=m; i++){
		cout << ans[i] << " ";
	}
	
	return 0;
} 
