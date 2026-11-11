#include <bits/stdc++.h>
using namespace std;

#define int long long

int n,m,ans,a[200001],pw[31];

inline void dfs(const int &x,const int &y,const int &choosed){
	if (choosed == m){
		ans = max(ans,y);
		return ;
	}
	if (choosed > m || x > n || (ans > y && y != -1) || choosed + n - x + 1 < m){
		return ;
	}
	if (y == -1){
		dfs(x + 1,a[x],choosed + 1);
		dfs(x + 1,-1,choosed + 1);
		return ;
	}
	dfs(x + 1,y & a[x],choosed + 1);
	dfs(x + 1,y,choosed);
} 

signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0); 
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	
	pw[0] = 1;
	for (int i = 1;i <= 30;i++){
		pw[i] = pw[i - 1] * 2;
	}
	
	cin >> n >> m;
	bool isA = 1,isB = 1;
	for (int i = 1;i <= n;i++){
		cin >> a[i];
		bool A = 0,B = 0;
		for (int j = 0;j <= 20;j++){
			if (a[i] == pw[j] - 1){
				A = 1;
				break;
			}
			if (a[i] == pw[j]){
				B = 1;
				break;
			}
		}
		if (!A){
			isA = 0;
		}
		if (!B){
			isB = 0;
		}
	}
	if (m == n){
		ans = a[1];
		for (int i = 2;i <= n;i++){
			ans &= a[i];
		} 
		cout << ans;
		return 0;
	}
	if (m == 1){
		for (int i = 1;i <= n;i++){
			ans = max(ans,a[i]);
		}
		cout << ans;
		return 0;
	}
	if (m == 2 && n <= 2000){
		for (int i = 1;i < n;i++){
			for (int j = i + 1;j <= n;j++){
				ans = max(ans,a[i] & a[j]);
			}
		}
		cout << ans;
		return 0;
	}
	if (isA){
		sort(a + 1,a + n + 1,greater<int>());
		cout << a[m];
		return 0;
	} 
	if (isB){
		//特殊性质B该干啥啊qwq 
	}
//	dfs(1,-1,0);
	while (1){
		sort(a + 1,a + n + 1,greater<int>());
		int p = 30;
		while (p >= 0 && pw[p] > a[1]){
			p--;
		}
		if  (a[m] < pw[p]){
			for (int i = 1;i <= n && a[i] >= pw[p];i++){
				a[i] -= pw[p];
			}
		}
		else {
			break;
		}
	}
	ans = a[1];
	for (int i = 2;i <= m;i++){
		ans &= a[i];
	}
	cout << ans;
	return 0;
} 
/*
5 3
31 3 1 15 7

*/
//O(n logn logn)（应该吧），希望能过，这样t4骗点分也能有 J1 
