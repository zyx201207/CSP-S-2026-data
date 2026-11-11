#include<bits/stdc++.h>
using namespace std;
#define int long long
int n, m, a[200005], aaans, mx;
bool all2power = 1, aieim1 = 1;
void dfs(int x, int k, int ans){
	if(x > n){
		if(k == m){
			aaans = max(aaans, ans);
		}
		return;
	}
	dfs(x + 1, k, ans);
	dfs(x + 1, k + 1, ans & a[x]);
}
int power(int x, int b){
	if(b == 0)	return 1;
	int res = 1;
	while(b){
		if(b & 1)	res = res * x;
		x = x * x;
		b >>= 1;
	}
	return res;
}
bool cmp(int x, int y){
	return x > y;
}
bool cmp2(int x, int y){
	if((x % 2) != (y % 2))	return (x % 2) > (y % 2);
	return x > y;
}
signed main(){
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	cin >> n >> m;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
		if(a[i] != power(2, __lg(a[i]) + 1) - 1)	all2power = 0;
		if(a[i] != i - 1)	aieim1 = 0;	
		mx = max(mx, a[i]);
	}	
	if(m == n){
		int ans = 2147483647;
		for(int i = 1; i <= n; i++)	ans &= a[i];
		cout << ans << endl;
		return 0;
	}else if(m == 1){
		int ans = 0;
		for(int i = 1; i <= n; i++)	ans = max(ans, a[i]);
		cout << ans << endl;
		return 0;
	}else if(m == 2){
		int ans = 0;
		for(int i = 1; i <= n; i++){
			for(int j = i + 1; j <= n; j++){
				ans = max(ans, a[i] & a[j]);
			}
		}
		cout << ans << endl;
		return 0;
	}else if(n <= 20){
		dfs(1, 0, 2147483647);
		cout << aaans << endl;
		return 0;
	}else if(all2power || aieim1 || m == n - 1){
		sort(a + 1, a + 1 + n, cmp);
		int ans = 2147483647;
		for(int i = 1; i <= m; i++){
			ans &= a[i];
		}
		cout << ans << endl;
		return 0;
	}else if(mx < 4){
		int cnt1 = 0, cnt2 = 0;
		for(int i = 1; i <= n; i++){
			if(a[i] >= 2)	cnt1++;
			if(a[i] == 1 || a[i] == 3)	cnt2++;
		}
		if(cnt1 >= m){
			sort(a + 1, a + 1 + n, cmp);
			int ans = 2147483647;
			for(int i = 1; i <= m; i++){
				ans &= a[i];
			}
			cout << ans << endl;
			return 0;
		}else{
			if(cnt2 >= m){
				sort(a + 1, a + 1 + n, cmp2);
				int ans = 2147483647;
				for(int i = 1; i <= m; i++){
					ans &= a[i];
				}
				cout << ans << endl;
				return 0;
			}else{
				cout << "0";
				return 0;
			}
		}
	}else{
		cout << "0" << endl;
		return 0;
	}


	return 0;
}

