#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m;
int a[300001];
void solve1(){
	int ans = 0;
	for(int mask = 0;mask < (1 << n);mask++){
		int cnt = 0,tmp = -1;
		for(int i = 0;i<n;i++){
			if((mask >> i) & 1){
				cnt++;
				if(tmp == -1) tmp = a[i+1];
				else tmp&=a[i+1];
			}
		}
		if(cnt != m) continue;
		ans = max(ans,tmp); 
	}
	cout << ans;
}
int poww[101];
void solve2(){
	int ans = 0;
	poww[0] = 1;
	for(int i = 1;i<=31;i++){
		poww[i] = poww[i-1]*2;
	}
	priority_queue<int> q;
	for(int i = 1;i<=n;i++){
		int tmp = 0;
		for(int j = 31;j>=0;j--){
			if(a[i] > poww[j]){
				tmp = j;
				break;
			}
		}
		q.push(tmp);
	}
	m--;
	while(!q.empty() && m){
		m--;
		q.pop();
	}
	if(q.empty()) cout << 0 << endl;
	else cout << poww[q.top()];
}
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);/
	cin >> n >> m;
	for(int i = 1;i<=n;i++){
		cin >> a[i];
	}
	if(n <= 20){
		solve1(); 
	}else if(m == 1){
		int ans = 0;
		for(int i = 1;i<=n;i++){
			ans = max(ans,a[i]);
		} 
		cout << ans;
		return 0;
	}else if(m == n){
		int ans = a[1];
		for(int i = 2;i<=n;i++){
			ans &= a[i];
		}
		cout << ans;
		return 0;
	}else{
		solve2();
	}
	return 0;
}
