#include<bits/stdc++.h>
using namespace std;
long long c,n,m,d,q;
long long sum,num;
long long w[510];
long long a[510],t[510];
long long x[510],y[510];
long long cnt=0;
int main() {
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(long long i=1; i<=m; i++) {
		cin>>w[i];
	}
	cin>>sum;
	for(long long i=1; i<=2*sum; i++) {
		cin>>a[i];
	}
	cin>>num;
	for(long long i=1; i<=2*num; i++) {
		cin>>t[i];
	}
	for(long long i=1; i<=q; i++) {
		cin>>x[i]>>y[i];
	}
	for(long long i=1;i<=n;i++){
		cnt=min(abs(t[i]-t[i-1]),abs(t[i]-t[i-1]));
	}
	for(long long i=1;i<=q;i++){
		cout<<cnt<<endl;
	}
	return 0;
}
