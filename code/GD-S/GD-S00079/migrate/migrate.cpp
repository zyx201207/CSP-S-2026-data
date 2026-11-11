#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int c,t;
	cin>>c>>t;
	while(t--) {
		int n,d;
		long long x;
		cin>>n>>d;
		for(int i=1;i<=n;i++)cin>>x;
		cout<<(n-1)/d<<'\n';
	}
	return 0;
}
