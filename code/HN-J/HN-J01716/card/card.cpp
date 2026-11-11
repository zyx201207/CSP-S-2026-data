#include<bits/stdc++.h>

using namespace std;

const int N = 5e5 + 5;

int n, m, a[N], p[N], d[N], v[N], vis[N], ans[N];

int main(){
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	ios::sync_with_stdio(false), cin.tie(0);
	cin >> n >> m;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
	}
	for(int i = n; i >= 1; i--){
		if(!p[a[i]]){
			p[a[i]] = i;
		}
	}
	for(int i = n; i >= 1; i--){
		for(int j = i; j <= n; j++){
			if(d[j]){
				d[j]++;
				break;
			} else{
				d[j]++;
			}
			ans[a[j]]++;
			j = p[a[j]];
		}
	}
	for(int i = 1; i <= n; i++){
		if(d[i] > 1){
			for(int j = i; j <= n; j++){
				ans[a[j]] += d[i] - 1;
				j = p[a[j]];
			}
		}
	}
	for(int i = 1; i <= m; i++){
		cout << ans[i] << ' ';
	} 
	return 0;
}

