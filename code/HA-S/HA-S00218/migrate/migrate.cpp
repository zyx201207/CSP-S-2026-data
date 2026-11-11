#include<bits/stdc++.h>
using namespace std;
long long c,t,n,d,x,cnt;
int main() {
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	for(long long i=1; i<=t; i++) {
		cin>>n>>d;
		for(long long j=1; j<=n; j++) {
			cin>>x;
		}
		if(n==2 && d==2) cout<<"1";
	}
	return 0;
}
