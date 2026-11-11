#include<bits/stdc++.h>
using namespace std;
int n, m;
int a[500005];
int ans[300005];
int l[300005];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	cin >> n >> m;
	bool flag = 1;
	for (int i = 1; i <= n; i ++){
		cin >> a[i];
		if (a[i - 1] > a[i]) flag = 0;
		l[a[i]] = i;
	}
	
	
	for (int i = n; i >= 1; i --){
		int t = i;
		while (t <= n){
			t = l[a[t]];
			ans[a[t]] ++;
			t ++;
		}
	}
	
	for (int i = 1; i <= m; i ++) cout << ans[i] << " ";
	return 0;
}

