#include <bits/stdc++.h>
using namespace std;

const int N = 5e5 + 5;
int a[N], ne[N], ans[N];
vector<int> pos[N];

int main(){
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);

	int n, m;
	cin >> n >> m;
	
	for(int i = 1; i <= n; i++){
		cin >> a[i];
		if(!pos[a[i]].empty()){
			ne[pos[a[i]].back()] = i;
		}
		pos[a[i]].push_back(i);
	}
	
	for(int k = 1; k <= n; k++){
		for(int i = k; i <= n; i++){
			while(ne[i]) i = ne[i];
			ans[a[i]]++;
		}
	}
	
	for(int i = 1; i <= m; i++){
		cout << ans[i] << ' ';
	}
}


/*
4 3
1 2 1 3

10 3
3 1 2 1 3 2 3 1 2 1
*/
