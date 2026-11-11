#include<bits/stdc++.h>
#define ll long long
using namespace std;

const int N = 2e5 + 1;

int n, m, a[N], vis[N], ans[N];

vector<int> v;

int main(){
	ios::sync_with_stdio(0), cin.tie(0);
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	cin >> n >> m;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
	}
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			vis[j] = 0;
		}
		v.clear();
		for(int j = i; j <= n; j++){
			if(vis[a[j]] == 1){
				for(auto x : v){
					vis[x] = 0;
				}
				v.clear();
				//cout << 1 << '\n';
			}
			v.push_back(a[j]);
		}
		for(auto x : v){
			ans[x]++;
			//cout << x << ' ';
		}
		//cout << '\n';
	}
	for(int i = 1; i <= m; i++){
		cout << ans[i] << ' ';
	}
	return 0;
} 
