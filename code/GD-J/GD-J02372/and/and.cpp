#include <bits/stdc++.h>
using namespace std;

int main(){
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	int n, m; cin >> n >> m;
	vector<long long> a;
	for (int i=1;i<=n;i++){
		int v;
		cin >> v;
		a.push_back(v);
	}
	sort(a.rbegin(),a.rend());
	int ans;
	for (int k=1;k<=n;k++){
		ans=a[k-1];
		for (int i=k;i<m+k-1;i++){
			ans &= a[i];
		}
		if (ans!=0)break;
	}
	cout << ans;
	return 0; 
} 
