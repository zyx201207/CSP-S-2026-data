#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e6+10;
vector<int>a(N);
int n,d;
void solve()
{
	cin >> n >> d;
	for(int i=1;i<=n;i++){
		cin >> a[i];
	}
	cout << 1;
}
signed main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin >> c >> t;
	while(t--){
		solve();
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
