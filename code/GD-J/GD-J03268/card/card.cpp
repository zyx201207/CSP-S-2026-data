#include<bits/stdc++.h>
using namespace std;
int a[500005];
int cnt[500005];
int main(){
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
	}
	for(int i = 1; i <= n; i++){
		vector<int> now;
		for(int j = i; j <= n; j++){
			for(int k = 0; k < now.size(); k++){
				if(a[j] == now[k]){
					now.erase(now.begin()+k, now.end());
					break;
				}
			}
			now.push_back(a[j]);
		}
		for(int j : now){
			cnt[j]++;
		}
	}
	for(int i = 1; i <=  m; i++){
		cout << cnt[i] << ' ';
	}
	return 0;
}
