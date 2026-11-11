#include<bits/stdc++.h>
using namespace std;
const int N = 5e5+5;
const int M = 3e5+5;
int n, m, a[N], cnt[M], pos[M], ans[M];
unordered_map<int, int> mp[M];
signed main(){
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
		cnt[a[i]]++; 
	}
	int sum = 1;
	pos[a[n]] = n;
	mp[a[n]][a[n]]++;
	for(int i = n-1; i >= 1; i--){
		if(pos[a[i]] == 0){
			sum++;
			mp[a[i]] = mp[a[i+1]];
			mp[a[i]][a[i]] = 1;
		}
		if(sum == m) break;
		pos[a[i]] = i;
	}
	for(int i = 1; i <= m; i++){
		for(auto j:mp[i]){
			int x = j.first;
			ans[x] += cnt[i]; 
		}
	} 
	for(int i = 1; i <= m; i++) cout << ans[i] << " ";
	return 0;
} 
