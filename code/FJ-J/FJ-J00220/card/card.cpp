#include <bits/stdc++.h>
using namespace std;
int n, m, x, ans[3010];
bool c[3010];
vector<int> a, b;
int main(){
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	cin >> n >> m;
	for(int i = 0;i < n;i++){
		cin >> x;
		a.push_back(x);
	}
	for(int j = 0;j < n;j++){
		for(int i = j;i < n;i++){
			while(c[a[i]]){
				c[b[b.size() - 1]] = 0;
				b.pop_back();
			}
			b.push_back(a[i]);
			c[a[i]] = 1;
		}
		for(int i = 1;i <= m;i++){
			if(c[i]){
				ans[i]++;
				c[i] = 0;
			}
		}
		for(int i = 0;i < b.size();i++){
			b.pop_back();
		}
	}
	for(int i = 1;i <= m;i++)cout << ans[i] << ' ';
	return 0;
}
