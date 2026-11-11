#include <bits/stdc++.h>
using namespace std;
#define int long long
int a[500010];
signed main(){
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, m;
	cin >> n >> m;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
	}
	sort(a+1, a+n+1);
	deque<int> q;
	int ans=0, num=0, val=0;
	for(int i = 1; i <= n; i++){
		int add=0;
		if(!q.empty()) add=a[i]-q.back();
		num+=add*q.size();
		q.push_back(a[i]);
		val=a[i];
		while(!q.empty()&&num>m){
			num-=(val-q.front());
			q.pop_front();
		}
		ans=max(ans, (long long)q.size());
	} 
	cout << ans << "\n";
	return 0;
}
