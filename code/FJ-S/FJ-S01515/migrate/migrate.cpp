#include<bits/stdc++.h>
using namespace std;
long long c,t,n,d,sum=0,num=0;
int main() {
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	vector<long long>x(n+10);
	cin>>c>>t;
	for(long long i=1; i<=t; i++) {
		cin>>n>>d;
		for(long long j=1; j<=n; j++) {
			cin>>x[j];
		}
	}
	for(long long i=1; i<=n; i++) {
		long long q=x[i]-x[i-1];
		long long w=x[i]-x[i-1];
		if(abs(q)<d) {
			sum++;
		}
		if(w==w) {
			num++;
		}
	}
	cout<<sum<<" "<<num;
	return 0;
}
