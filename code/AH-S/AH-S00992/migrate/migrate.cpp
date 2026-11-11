#include <iostream>
using namespace std;
const int N = 2e6 + 5;
int c,T,n;
long long d,x[N];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>T;
	while (T--) {
		cin>>n>>d;
		for (int i=1; i<=n; i++) cin>>x[i];
		if (n<4) {
			cout<<"0\n";
			continue;
		}
		if (c==11 || c==12) {
			if (x[2]-x[1]==d) cout<<"0\n";
			else if (2*(x[2]-x[1])<=d) cout<<n-3<<endl;
			continue;
		}
		else if (c==13 || c==14) {
			cout<<n-3<<endl;
			continue;
		}
	}
	return 0;
}
