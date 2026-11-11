#include <bits/stdc++.h>
using namespace std;

int n, m;
int card[(int)5e5 + 5];
vector<int> tal;
set<int> f;
int ans[(int)5e5 + 5];

int main(){
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	cin >> n >> m;
	for(int i = 1; i <= n; i++){
		cin >> card[i];
	}
	for(int i = 1; i <= n; i++){
		tal.clear();
		f.clear();
		for(int j = i; j <= n; j++){
			if(!f.count(card[j])){
				f.insert(card[j]);
				tal.push_back(card[j]);
			}else{
				for(int k = tal.size() - 1; k > 0; k--){
					if(tal[k] != card[j]){
						f.erase(tal[k]);
						tal[k] = 0;
					}
					if(tal[k] == card[j]){
						break;
					}
				}
			}
		}
		for(auto k : tal){
			ans[k]++;
		}
	}
	
	for(int i = 1; i <= m; i++){
		cout << ans[i] << " ";
	}
	return 0;
}
