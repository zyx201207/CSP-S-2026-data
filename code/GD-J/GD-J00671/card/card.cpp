#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);

	int n, m;
	cin >> n >> m;
	vector<int> a(n + 1), ans(m + 1, 0);
	for(int i = 1; i <= n; i++) cin >> a[i];
	for(int i = 1; i <= n; i++){
		vector<int> vis(n + 1, 0);
		stack<int> s;
		for(int j = i; j <= n; j++){
			if(vis[a[j]] == 1){
				while(s.top() != a[j]){
					vis[s.top()] = 0;
					s.pop();
				}
			}else{
				s.push(a[j]);
				vis[a[j]] = 1;
			}
		}
		while(!s.empty()){
			ans[s.top()]++;
			s.pop();
		}
	}
	for(int i = 1; i <= m; i++) cout << ans[i] << ' ';
	return 0;
}
