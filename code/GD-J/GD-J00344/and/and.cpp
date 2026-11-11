#include<bits/stdc++.h>
using namespace std;
int ans = 0;
int n,m,a[200010],mx,sum = 1;
void dfs(int u,int m,int sum){
	if(u == n + 1){
		if(m == 0){
			ans = max(ans,sum);
		}
		return ;
	}
	dfs(u + 1,m,sum);
	dfs(u + 1,m - 1,sum & a[u]);
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >> n >> m;
	bool flag = 1;
	for(int i = 1;i <= n;i++){
		cin >> a[i];
		sum &= a[i];
		if(a[i] > 4)flag = 0;
	}
	sort(a + 1,a + n + 1);
	if(n <= 20){
		dfs(0,m,pow(2,30) - 1);
		cout << ans;
	}else if(m == 1){
		cout << a[n];
	}else if(m == 2){
		ans = 0;
		for(int i = 1;i <= n;i ++){
			for(int j = i + 1;j <= n;j++){
				ans = max(ans,a[i] & a[j]);
			}
		}
	}else if(m == n){
		cout << sum;
	}else if(m == n - 1){
		sum = 0;
		for(int i = 2;i <= n;i++){
			sum &= a[i];
		}
		cout << sum;
	}else if(flag){
		cout << 0;
	}else cout << m;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
