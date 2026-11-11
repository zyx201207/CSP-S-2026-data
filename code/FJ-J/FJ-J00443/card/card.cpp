#include<bits/stdc++.h>
using namespace std;
const int N = 5e5 + 10;
int n, m, a[N], ton[N];
bool vis[N];
bool flag = true;
void solve(int l, int r){
	vector<int> vec;
	memset(vis, 0, sizeof vis);
	for(int i = l; i <= r; i++){
		if(vis[a[i]]){
			while(!vec.empty()){
				if(vec.back() == a[i]){
					vec.pop_back();
					break;
				}
				vis[vec.back()] = 0;
				vec.pop_back();
			}
		}
		vec.push_back(a[i]);
		vis[a[i]] = true;
	}
	for(auto i : vec){
		ton[i]++;
		vec.pop_back();
	}
	return ;
}
int main(){
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	cin >> n >> m;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
		if(a[i] < a[i-1]) flag = false;
	}
	if(flag){
		int laast = a[1], id = 1;
		for(int i = 2; i <= n; i++){
			if(a[i] != laast){
				ton[laast] = id;
				laast = a[i];
				id = i;
			}else id++;
		}
		ton[laast] = id;
	}else{
		for(int i = 1; i <= n; i++){
			solve(i, n);
		}
	}
	for(int i = 1; i <= m; i++) cout << ton[i] << " ";
	return 0;
}
