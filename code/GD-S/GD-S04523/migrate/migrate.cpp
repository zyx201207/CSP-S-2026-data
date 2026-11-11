#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int N=1e6+5;
ll c,t,n,d;
ll shu;
int x[N];
int b[N];
int main() {
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>c>>t;
	for(int i=1; i<=t; i++) {
		cin>>n>>d;
		for(int j=1; j<=n; i++) {
			cin>>x[i];
		}
		ll zd=n;
		for(int k=1; k<=n; k++) {
			ll zj=x[zd]-x[k];
			if(zj>d) {
				for(int l=1; l<=zj; l++) {
					cout<<x[l];
				}
			}
		}
	}
	return 0;
}
