#include <bits/stdc++.h>
#define int long long
using namespace std;
int n , m;
int maxn = 0;
int a[200005];
bool flag1 = true;
bool flag = true;
int num[5];
void dfs(int now , int sum , int cnt){
	if(cnt == m){
		maxn = max(maxn , sum);
		return ;
	}
	if(sum < maxn) return ;
	if(now > n) return;
	for(int i = now + 1 ; i <= n ; i ++){
		dfs(i , sum & a[i] , cnt + 1);
		dfs(i , sum , cnt);
	}
}
bool cmp(int x , int y){
	return x > y;
}
bool check(int n){
	int sum = 0;
	while(n != 0){
		sum = sum + n % 2;
		n /= 2;
	}
	return sum == 1;
}
signed main(){
	freopen("and.in" , "r" , stdin);
	freopen("and.out" , "w" , stdout);
	ios::sync_with_stdio(0) , cin.tie(0) , cout.tie(0);
	cin >> n >> m;
	for(int i = 1 ; i <= n ; i ++){
		cin >> a[i];
		if(a[i] != i - 1) flag = false;
		if(a[i] > 4) flag1 = false;
		if(a[i] <= 4) num[a[i]] ++;
	}
	if(m == 2 && n <= 2000){
		for(int i = 1 ; i <= n ; i ++){
			for(int j = i + 1 ; j <= n ; j ++){
				maxn = max(maxn , a[i] & a[j]);
			}
		}
		cout << maxn << "\n";
		return 0;
	}
	else if(m == 1 && n <= 2000){
		for(int i = 1 ; i <= n ; i ++){
			maxn = max(maxn , a[i]);
		}
		cout << maxn << "\n";
		return 0;
	}
	else if(flag == true){
		if(check(n)){
			sort(a + 1 , a + 1 + n , cmp);
			int ans = a[1];
			for(int i = 2 ; i <= m ; i ++){
				ans &= a[i];
			}
			cout << ans << "\n";
			return 0;
		}
	}
	else if(flag1 == true){
		sort(a + 1 , a + 1 + n , cmp);
		int ans = 0 , cnt = 0;
		if(a[1] == 4){
			if(num[4] >= m) cout << 4 << "\n";
			else cout << 0 << "\n";
			return 0;
		}
		else if(a[1] == 3){
			if(num[3] >= m) cout << 3 << "\n";
			else if((num[3] + num[2] >= m) || (num[2] >= m)) cout << 2 << "\n";
			else if((num[1] >= m) || (num[1] + num[3] >= m)) cout << 1 << "\n";
			else cout << 0 << "\n";
			return 0;
		}
		else if(a[1] == 2){
			if(num[2] >= m) cout << 2 << "\n";
			else if(num[1] >= m) cout << 1 << "\n";
			else cout << 0 << "\n";
			return 0;
		}
		else if(a[1]  == 1){
			if(num[1] >= m) cout << 1 << "\n";
			else cout << 0 << "\n";
			return 0;
		}
		else{
			cout << 0 << "\n";
			return 0;
		}
	}
	else if(m == n){
		int ans = a[1];
		for(int i = 2 ; i <= n ; i ++) ans &= a[i];
		cout << ans << "\n";
		return 0;
	}
	for(int i = 1 ; i <= n ; i ++){
		dfs(i , a[i] , 1);
	}
	cout << maxn << "\n";
	return 0;
}
