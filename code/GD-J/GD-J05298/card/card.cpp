#include<bits/stdc++.h>
using namespace std;

const int N = 1e6 + 10;
int ans[N];
vector<int> a;
bool vis[N];
int len = 0;
int find_idx(int x){
	for(int i = 0; i < len; i++){
		if(a[i] == x) return i;
	}
	return -1;
}
int main(){
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	
	int n, m;
	cin >> n >> m;
	for(int i = 1; i <= n; i++){
		bool flag[N];
		int x;
		cin >> x;
		if(!vis[x]){
			vis[x] = 1;
			a.push_back(x);
			len++;
		}else{
			int idx = find_idx(x);
			len = idx;
			a[idx] = x;
		}
		for(int i = 0; i < len; i++){
			ans[a[i]]++;
		}
	}
	for(int i = 1; i <= m; i++){
		cout << ans[i] << " ";
	}
	return 0;
}
