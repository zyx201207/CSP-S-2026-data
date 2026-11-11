#include<bits/stdc++.h>
using namespace std;
int a[200005] = {};
	bool f[33][200005] = {};
	bool t[200005] = {};
	
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int n,m;
	cin >> n >> m;
	for(int i = 1;i <= n;i++){
		t[i] = 1;
	}
	for(int i = 1;i <= n;i++){
		
		cin >> a[i];
		for(int j = 0;j<= 31;j++){
			if(a[i]>>j & 1){
				f[j][i] = 1;
			}
		}
	}
	int ans = 0;
	
	for(int i = 31;i >= 0;i--){
		
		int tot = 0;
		for(int j = 1;j <= n;j++){
			if(f[i][j] && t[j]){
				tot++;
			}
		}
		if(tot  == m){
			for(int j = 1;j <= n;j++){
				if(f[i][j] && t[j]){
					ans = ans? ans & a[j] : a[j];
					//cout << a[j] << endl;
				}
			}
			cout << ans;
			return 0;
		}
		else if(tot > m){
			for(int j = 1;j <= n;j++){
				if(!f[i][j]){
					t[j] = 0;
					
				}
				
			}
		}
		//cout << tot << endl;
	}
	for(int i = 1;i <= n;i++){
		if(t[i]){
			ans = ans? ans & a[i] : a[i];
		}
	}
	cout << ans;
	return 0;
}
