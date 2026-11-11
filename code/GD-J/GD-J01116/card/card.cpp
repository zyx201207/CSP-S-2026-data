#include <bits/stdc++.h>
using namespace std;
const int N = 5e5+5;
int a[N];
int ans[N], in[N];
int main(){
	freopen("card.in", "r", stdin);
	freopen("card.out","w",stdout);
	
	int n, m;
	cin >> n >> m;
	
	for(int i = 1;i <= n;i++) cin >> a[i];
	
	vector<int> now;
	for(int rd = 1;rd <= n;rd++){
		now.clear();
		for(int i = 1;i <= m;i++) in[i] = false;
		for(int i = rd;i <= n;i++){
			if(in[a[i]]){
				while(now[now.size()-1] != a[i]){
					in[now[now.size()-1]] = false;
					now.pop_back();
				}
			} else {
				now.push_back(a[i]);
				in[a[i]] = true;
			}
		}
		for(int i : now){
			ans[i]++;
		}
	}
	
	for(int i = 1;i <= m;i++) cout << ans[i] << ' ';
}
