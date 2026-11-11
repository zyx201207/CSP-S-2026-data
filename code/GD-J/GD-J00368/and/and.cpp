#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<int> a;
int ans = 0;

void dfs(int index, int num, int count_num){
	if (count_num == m){
		ans = max(ans, num);
		return;
	}
	for (int i = index;i <= n;i++){
		if (count_num == 0){
			num = a[i];
		}
		dfs(i + 1, num & a[i], count_num + 1);
	}
}

int main(){
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>n>>m;
	a.resize(n + 5);
	int current_max = 0;
	for (int i = 1;i <= n;i++){
		cin>>a[i];
		current_max = max(current_max, a[i]);
	}
	
	if (m == 1){
		cout<<current_max;
		return 0;
	}
	
	dfs(1, 1, 0);
	
	cout<<ans;
	
	return 0;
}
