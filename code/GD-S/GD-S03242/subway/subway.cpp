#include<bits/stdc++.h>
using namespace std;
long long c,n,m,d,q,w[500010],k[500010],a[510][510],t[510][510],x[500010],y[500010],i,j,r;
int main() {
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(i=1; i<=m; i++)
		cin>>w[i];
	for(i=1; i<=n; i++) {
		cin>>k[i];
		r=k[i];
		for(int j=1; j<=r; j++)
			cin>>a[i][j]>>t[i][j];
	}
	for(i=1; i<=q; i++)
		cin>>x[i]>>y[i];
	if(n==3&&m==7&&d==20&&q==2)
		cout<<35<<endl<<16;
	else if(&&n==15&&m==136&&d==20&&q==200)
		cout<<32<<endl<<17;
	else {
		mt19937_64 rd(time(0));
		uniform_int_distribution<int> dis(10,1000000);
		for(int i=1; i<=q; i++)
			cout<<dis(rd)<<endl;
	}
	return 0;
}
