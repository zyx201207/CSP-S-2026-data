#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,m;
int a[200005];
//int s[200005];
bool used[200005];
int ans = -1;
void dfs(int depth,int use){
	if (use > m){
		return ;
	}
	if (depth == n+1 && use == m){
		int s = -1;
		for (int i = 1;i <= n;i++){
			if (used[i]){
//				cout << s << ' ';
				if (s == -1){
					s = a[i];
				}
				else{
					s &= a[i];
				}
			}
		}
//		cout << endl;
		ans = max(ans,s);
		return ;
	}
	if (depth == n+1){
		return ;
	}
	used[depth] = 1;
	dfs(depth+1,use+1);
	used[depth] = 0;
	dfs(depth+1,use);
}
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >> n >> m;
	for (int i = 1;i <= n;i++){
		cin >> a[i];
	}
	if (n <= 20){
		dfs(1,0);
		cout << ans;
		return 0;
	}
	else if (m == 1){
		int mx = -1;
		for (int i = 1;i <= n;i++){
			mx = max(mx,a[i]);
		}
		cout << mx;
		return 0;
	}
	else if (m == n){
		int s = a[1];
		for (int i = 2;i <= n;i++){
			s &= a[i];
		}
		cout << s;
		return 0;
	}
	else if (m == 2){
		int ans = -1;
		for (int i = 1;i <= n;i++){
			for (int j = i+1;j <= n;j++){
				ans = max(ans,a[i]&a[j]);
			}
		}
		cout << ans;
	}
	else if (m == n-1){
		int s = a[1];
		int ans = -1;
		for (int i = 2;i <= n;i++){
			s &= a[i];
		}
		for (int i = 1;i <= n;i++){
			ans = max(ans,s|a[i]);
		}
		cout << ans;
	}
	else{
		sort(a+1,a+1+n);
		int s = a[n];
		for (int i = n-m+1;i >= 1;i--){
			s &= a[i];
		}
		cout << s;
	}
	return 0;
} 
/*
4 2
3 15 12 12
*/
