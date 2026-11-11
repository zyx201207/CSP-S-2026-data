#include <bits/stdc++.h>
using namespace std;
int n;
int m;
vector<int> a;
int main(){
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	cin >> n >> m;
	for(int i = 1; i <= n; i++){
		int x;
		cin >> x;
		a.push_back(x);
	}
	int ans[300005] = {0};
	for(int i = 0; i < n; i++){
		bool use[300005] = {0};
		vector<int> mn;
		for(int l = i; l < n; l++){
			if(use[a[l]]){
				while(mn.back() != a[l]){
					use[mn.back()] = false;
					mn.pop_back();
				}
			}
			else{
				use[a[l]] = true;
				mn.push_back(a[l]);
			}
		}
		for(auto l : mn){
			ans[l]++;
		}
	}
	for(int i = 1; i <= m; i++){
		cout << ans[i] << " ";
	}
	return 0;
}
