#include<bits/stdc++.h>
using namespace std;

const int N = 2e6 + 10;

map<int,int> mp;
int n,d;
vector<int> a(N);
void dfs(int nown,int val){
	if(val > d || nown == n){
		return ;
	}else{
		mp[val] ++ ;
		for(int i = 1;i <= n;i ++ ){
			dfs(nown + 1,val + a[i]);
		}
	}
}
void solve1(){
	cin >> n >> d;
	a.clear();
	for(int i = 1;i <= n;i ++ ){
		cin >> a[i];
	}
	dfs(0,0);
	int ans = 0;
	for(auto m : mp){
		if(m.second == 2){
			ans ++ ;
		}
	}
	cout << ans << '\n';
}
void solve2(){
	cin >> n >> d;
	if(n > d){
		cout << n - 2 * d + 1 <<'\n'; 
	}else{
		if(n % 2 == 0){
			cout << d/(d / n * 2) <<'\n';
		}else{
			cout << d/(d / n * 2) << '\n';
		}
	}
}
int main (){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int c,t;
	cin >> c >> t;
	if(c == 1 || c == 2){
		solve1();
	}else if(c == 11 || c == 12){
		solve2();
	}else{
		solve1();
	}
	return 0;
} 
