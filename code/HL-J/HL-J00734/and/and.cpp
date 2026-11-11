#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n, m, maxn = 0, x;
vector <int> chosen;
int s[200005];
void dfs(int c, int p){
	if (c == m){
		int ans = chosen[0];
		for (int i = 0; i < m; i++){
			ans = ans & chosen[i];
		}
		maxn = max(ans, maxn);
		return;
	}
	
	if (n - p < m - c) return;
	
	
	for (int i = p+1; i < n; i++){
		chosen.push_back(s[i]);
		dfs(c+1, i);
		chosen.pop_back();
	}
	return;
	
}

int main()
{
	freopen("and1.in", "r", stdin);
	freopen("and.out", "w", stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	cin >> n >> m;
	
	
	for(int i = 0; i < n; i++){
		cin >> s[i];
	}
	
	//chosen.push_back(s[0]);
	dfs(0, 0);
	
	cout << maxn;
	return 0;
}