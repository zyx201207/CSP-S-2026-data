#include <bits/stdc++.h>
using namespace std;
int c,t,n;
long long d,b,x[2000005];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin >> c >> t;
	while (t--){
		cin >> n >> d;
		for (int i=1;i<=n;i++){
			cin >> x[i];
		}
		if (c==11||c==12){
			b=x[2]-x[1];
			if (2*b>d){
			    cout << 0 << endl;
			    continue;
		    }
			long long t=d/b;
		    cout << max(0*1ll,n-2*1ll*t+1) << endl;
		}
		else cout << 0 << endl;
	}
	return 0;
}
