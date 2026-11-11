#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll c,t,n,d,u,v;
ll x[2000005]= {0};
int main() {
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	for(int i=1; i<=t; i++) {
		cin>>n>>d;

		for(int j=1; j<=n; j++) {
			cin>>x[j];
		}
		int w=1;
		for(int k=1; k<=n;) {
			for(int j=x[i]; j<=n;) {
				int z=x[j]-x[k];
				if(z>d) {
					j++;
				} else if(z>d) {
					k++;
				} else {
					j++;
					k++;
				}
			}
		}

	}
	return 0;
}
