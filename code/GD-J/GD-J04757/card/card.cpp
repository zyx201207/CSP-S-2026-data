#include<bits/stdc++.h>
using namespace std;
int n, m, a[500003], ans[500003], r[500003];
int main(){
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	cin >> n >> m;
	bool flag = true;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
		if(a[i] > a[i - 1]) flag = false;
	}
	if(flag == true){
		for(int i = 1; i <= n; i++){
			if(a[i] != a[i + 1]){
				cout << i << " ";
			}
		}
		return 0;
	}
	for(int i = 1; i <= n; i++){
		map<int, int> mp;
		for(int j = 1; j <= n; j++) ans[j] = 0;
		for(int j = i; j <= n; j++){
			if(mp[a[j]]){
				ans[mp[a[j]]]--, ans[j]++;
				for(int k = 1; k <= m; k++){
					if(mp[k] >= mp[a[j]] && mp[k] < j){
						mp[k] = 0;
					}
				}
			}
			mp[a[j]] = j;
		}
		for(int j = i + 1; j <= n; j++) ans[j] += ans[j - 1];
		for(int j = i; j <= n; j++){
			if(ans[j] >= 0) r[a[j]]++;
		}
	}
	for(int i = 1; i <= m; i++){
		cout << r[i] << " ";
	}
	return 0;
}

