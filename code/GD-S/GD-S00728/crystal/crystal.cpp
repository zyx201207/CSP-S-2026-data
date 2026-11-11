#include <bits/stdc++.h>
#define LL long long
using namespace std;
constexpr int N = 5e5 + 10;
int n;
LL m;
int a[N];
LL sum;
LL ans;
bool special_A = true;
bool special_B = true;
LL special_B_sum; 

//bool cmp(c_num x, c_num y){
//	return x.a < y.a;
//} 

void dfs(int id, LL sum, LL m,int anid){
	if(id == n + 1 || a[anid] - a[id] < 0 || a[anid] - a[id] > m){
		ans = max(sum, ans);
		return;
	}
	dfs(id + 1, sum + 1, m - (a[anid] - a[id]), anid);
	dfs(id + 1, sum, m, anid);
	return;
}

 

int main(){
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	
	cin >> n >> m;
	for(int i = 1;i <= n;i++){
		cin >> a[i]; 
		if(i == 2) special_B_sum = a[i] - a[i-1];
		if(a[i] != i) special_A = false;
		if(!( (a[i] - a[i-1]) == special_B_sum ) && i >= 3) special_B = false;
	}
	
	// special A : 1 2 3 4 5 6 .....
	if(special_A){
		int all_sum = n * (n - 1) / 2;
		if(all_sum <= m){
			cout << n;
			return 0;
		}
//		cout << (LL)( (LL)sqrt(8 * m + 1) - 1 ) / 2 + 1;
		for(int i = 1;i < n;i++){
			if(m < 1 * i) break;
			m -= 1 * i;
			ans++;
		}
		cout << ans + 1;
		return 0;
	}
	
	// special B
	if(special_B){
		if(m >= special_B_sum * n * (n - 1) / 2){
			cout << n;
			return 0;
		}
		for(int i = 1;i < n;i++){
			if(m < special_B_sum * i) break;
			m -= special_B_sum * i;
			ans++;
		}
		cout << ans + 1;
		return 0;
	}
	
	// others
	sort(a + 1, a + 1 + n);
	for(int i = 1;i <= n;i++){
		int back = ans;
		dfs(1,0,m,i);
		if(back == ans) break;
	}
	cout << ans;
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
