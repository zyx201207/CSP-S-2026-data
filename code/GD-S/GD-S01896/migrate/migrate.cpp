#include <bits/stdc++.h>
using namespace std;
int c,n,t;
long long d,x[2000005],pl,ans;
int main () {
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>t;
	if (c==11||c==12) {
		while (t--) {
			pl=1;
			ans=0;
			cin>>n>>d;
			for (int i=1;i<=n;i++) {
				cin>>x[i];
				while ((x[i]-x[pl])>d) pl++;
				if (i>2&&pl!=2) ans=-1; 
			}
			if (ans==-1) cout<<"0\n";
			else cout<<n-3<<"\n";
		}
	}
	return 0;
}
//iwillbeback

