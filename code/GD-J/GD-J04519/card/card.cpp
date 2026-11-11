#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 5;
const int M = 3e5 + 5;
int n, m;
int a[N], cnt[M];
bool memo[M];
stack <int> s;
int main(){
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int i = 1; i <= n; i++){
		memset(memo, false, sizeof(memo));
		for (int j = i; j <= n; j++){
			if (memo[a[j]]){
				while (s.top() != a[j]) s.pop();
			}else{
				s.push(a[j]);
			}
			memo[a[j]] = true;
		}
		while (!s.empty()){
			cnt[s.top()]++;
			s.pop();
		}
	}
	for (int i = 1; i <= m; i++) cout << cnt[i] << " ";
	return 0;
} 
