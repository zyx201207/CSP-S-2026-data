#include<bits/stdc++.h>
using namespace std;

long long n, m;
long long a[500005];
map<long long, long long> mp;
int mx;
int ans = 1;
void dfs(int x, int y, int z){
	if(z <= 0) return;
//	cout << "z = "<< z << '\n';
	z = z - a[y] + a[x];
	ans++; 
//	cout << "z = "<< z << '\n';
//	cout << "ans=" << ans << '\n';
	dfs(x + 1, y, z);
}
int main(){
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	
	cin >> n >> m;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
		mp[a[i]]++;
	}
	
	sort(a + 1, a + n + 1);
	
	int mid = n / 2 + 1;
	while(mid < 0){
		mid++;
	}
	for(int i = mid; i <= n; i++){
//		cout << "a[i]=" << a[i] << '\n';
		ans = 1; 
		dfs(1, i, m);
		mx = max(mx, ans);
		if(mp[a[i]] > 1 && a[i] != a[i - 1]) mx += mp[a[i]] - 1;
//		cout << "mx=" << mx << '\n';
	}
	
	cout << mx;
	return 0;
} 
