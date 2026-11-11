#include<bits/stdc++.h>
using namespace std;
int n,m,a[200001];
int an[40000000][11],c[11];
bool b[11];
int len = 0;
inline void dfs(int i){
	if(i == m + 1){
		++len;
		for(int j = 1;j <= m;j++){
			an[len][j] = c[j];
		}
	}
	for(int j = 1;j <= n;j++){
		if(!b[j]){
			c[i] = j;
			dfs(i + 1);
		}
	}
}
inline void dfs2(int i){
	if(i == n - m + 1){
		++len;
		for(int j = 1;j <= n - m;j++){
			an[len][j] = c[j];
		}
	}
	for(int j = 1;j <= n;j++){
		if(!b[j]){
			c[i] = j;
			dfs(i + 1);
		}
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >> n >> m;
	for(int i = 1;i <= n;i++){
		cin >> a[i];
	}
	if(n <= 20){
		int ans = -1;
		int cnt = 1;
		if(m <= 10){
			dfs(1);
			for(int i = 1;i <= len;i++){
				for(int j = 1;j <= m;j++){
					cnt &= a[an[i][j]];
				}
				ans = max(ans,cnt);
			}
		}else{
			dfs2(1);
			for(int i = 1;i <= len;i++){
				for(int k = 1;k <= n;k++){
					bool ok = true;
					for(int j = 1;j <= m;j++){
						if(k == an[i][j]){
							ok = false;
						}
					}
					if(ok){
						cnt &= a[k]; 
					}
				}
				ans = max(ans,cnt);
			}
		}
		cout << ans;
	}
	if(n >= 20 && n <= 2000){
		if(m == 1){
			sort(a + 1,a + n + 1);
			cout << a[n];
		}
		if(m == 2){
			int ans = -1;
			for(int i = 1;i <= n;i++){
				for(int j = i + 1;j <= n;j++){
					int cnt = a[i] & a[j];
					ans = max(ans,cnt);
				}
			}
			cout << ans;
		}
		if(m == n){
			int ans = 1;
			for(int i = 1;i <= n;i++){
				ans &= a[i];
			}
			cout << ans;
		}
	}
	if(n <= 200000 && n >= 2000){
		sort(a + 1,a + n + 1);
		cout << a[n - m + 1];
	}
}
