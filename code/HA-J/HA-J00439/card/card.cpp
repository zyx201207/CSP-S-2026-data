#include<iostream>
#include<string>
#include<vector>
using namespace std;
int n,m;
int a[500010];
int ans[300010];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin >> n >> m;
	for(int i = 1;i <= n;i++){
		cin >> a[i];
	}
	/*
	for(int i = n;i > 0;i--){
		
		f[a[i]]++;
		if(f[a[i]] == 2){
			for(;;){
				if(u.back() != a[i]){
					f[u.back()]--;
					u.pop_back();
				}else{
					f[u.back()]--;
					u.pop_back();
					break;
				}
			}
		}
		u.push_back(a[i]);
		for(int j = 0;j < u.size();j++){
			ans[u[j]]++;
			if(u[j] == 3) cout << i << ' ';
		}
		
		for(int j = i;j < n;){
			if(f[a[j]].empty()){
				j++;
				// cout << j << ' ';
				ans[a[j]]++;
				continue;
			}
			else{
				int nu = -1;
				for(int k = f[a[j]].size() - 1;k >= 0;k--){
					if(f[a[j]][k] > j) nu = f[a[j]][k];
				}
				if(nu == -1){
					j++;
					ans[a[j]]++;
					continue;
				}else{
					ans[a[j]]++;
					j = nu;
				}
			}
		}
		f[a[i]].push_back(i);
		// cout << a[i] << ' ';
	}
	*/
	for(int v = 1;v <= n;v++){
		vector <int> u;
		int f[300010];
		for(int i = v;i <= n;i++){
			f[a[i]]++;
			if(f[a[i]] == 2){
				for(;;){
					if(u.back() != a[i]){
						f[u.back()]--;
						u.pop_back();
					}else{
						f[u.back()]--;
						u.pop_back();
						break;
					}
				}
			}
			u.push_back(a[i]);
		}
		for(int k = 0;k <= 300001;k++){
			f[k] = 0;
		}
		for(int j = 0;j < u.size();j++){
			ans[u[j]]++;
			// if(u[j] == 3) cout << i << ' ';
		}
	}
		
	for(int i = 1;i <= m;i++){
		cout << ans[i] << ' ';
	}
	return 0;
}
