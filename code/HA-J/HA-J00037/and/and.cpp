#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
	ios::sync_with_stdio (false);
	cin.tie (0);

	freopen ("and.in","r",stdin);
	freopen ("and.out","w",stdout);
	 
	int n,m;
	cin >> n >> m;
	////cerr << n << m << "\n";
	
	vector<int> a(n);
	for(int i = 0;i < n;i++){
		cin >>a[i];
		////cerr << a[i] << ' ';
	}
	////cerr << "\n";
	
	auto cmp = [&](int a,int b){
		return a > b;
	};
	
	sort(a.begin(),a.end(),cmp);
	
	for(int i = 0;i < n;i++){
		////cerr << a[i] << ' ';
	}
	////cerr << "\n";
	
	int ans = a[0];
	////cerr<< ans << "\n";
	for(int i = 1;i < m;i++){
		ans  = ans&a[i];
		////cerr<< ans << "\n";
	}
	
	cout << ans << "\n";
	
	return 0;
}

//cwdtxdsydf