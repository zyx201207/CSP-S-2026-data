#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int c,t;
	
	cin >> c >> t;
	while(t--){
		int n,d;
	
		cin >> n >> d;
		vector<int> a(n);
		
		for(int i=0;i<n;i++) cin >> a[i];
		
		cout << ((d-1)<=(a[1]-a[0]))*(n-3) << '\n';
	}
	
	return 0;
}
