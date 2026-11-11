#include<bits/stdc++.h>
using namespace std;
const int maxn = 2e5;
int a[maxn];
int n, m;
int ans = INT_MIN;
void dfs(int len, int cnt, int sum){
	if(len > n){
		if(cnt == m){
			ans = max(ans,sum);
		} 
		return ;
	}
	dfs(len+1,cnt,sum);
	dfs(len+1,cnt+1,(sum == -1 ? a[len] : (sum&a[len])));
}
int main(){
//	ios::sync__stdio(0);
//	cin.tie(0), cout.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >> n >> m;
	for(int i = 1;i <= n;i++){
		cin >> a[i];
	} 
	if(n <= 20){
		dfs(1,0,-1);
		cout << ans;
	}else if(m == 1){
		int ans = INT_MIN;
		for(int i = 1;i <= n;i++){
			ans = max(ans,a[i]);
		}
		cout << ans;
	}else if(n == m){
		int ans = a[1];
		for(int i = 2;i <= n;i++){
			ans &= a[i];
		}
		cout << ans;
	}else if(m == 2){
		int ans = INT_MIN;
		for(int i = 1;i <= n;i++){
			for(int j = 1;j <= n;j++){
				if(i == j) continue;
				ans = max(ans,a[i]&a[j]);
			}
		}
		cout << ans;
	}else if(m == n-1){
		int ans = INT_MIN;
		for(int i = 1;i <= n;i++){
			int sum = -1;
			for(int j = 1;j <= n;j++){
				if(i == j) continue;
				if(sum = -1) sum = a[j];
				else sum &= a[j];
			}
			ans = max(ans,sum);
		}
		cout << ans;
	}else{
		dfs(1,0,-1);
		cout << ans;
	}
	return 0;
}
