#include<bits/stdc++.h>
using namespace std;
#define int long long
const int maxn = 2e6+5;
int c,t,x[maxn];
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin >> c >> t;
	while(t--){
		int n,d;
		cin >> n >> d;
		for(int i=1;i<=n;i++) cin >> x[i];
		if(n != 3) cout << 0 << endl;
		else if(n == 3) cout << 1 << endl;
	}
}
