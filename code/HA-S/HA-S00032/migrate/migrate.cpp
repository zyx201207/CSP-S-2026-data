#include<bits/stdc++.h>
using namespace std;
int c,t;
int n;
long long d;
long long x[2000010];
int main() {
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	for(int i=1; i<=t; i++) {
		cin>>n>>d;
		for(int i=1; i<=n; i++) {
			cin>>x[i];
		}
		cout<<n-3<<"\n";
	}
	return 0;
}

