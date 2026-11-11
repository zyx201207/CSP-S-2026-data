#include<bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5, L = 31;

int n, m, ans;
int vis[N];
vector<int> v[L][2];

int main(){
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> n >> m;
	for(int i = 1, x; i <= n; i++){
		cin >> x;
		vis[i] = 1;
		for(int j = 0; j < L; j++){
			v[j][x >> j & 1].push_back(i);
		}
	}
	for(int i = L - 1; i >= 0; i--){
		int sum = 0;
		for(int j = 0; j < v[i][1].size(); j++){
			int x = v[i][1][j];
			sum += vis[x];
		}
		if(sum < m) continue;
		for(int j = 0; j < v[i][0].size(); j++){
			int x = v[i][0][j];
			vis[x] = 0;
		}
		ans |= 1 << i; 
	}
	cout << ans;
	return 0;
}
/*

*/
