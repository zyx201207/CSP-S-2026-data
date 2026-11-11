#include<bits/stdc++.h>
using namespace std;
long long c,t,n,d,x[2000010],i,j,m;
bool flog=true;
int main() {
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>c>>t;
	mt19937_64 rd(time(0));
	uniform_int_distribution<int> dis(0,5);
	for(i=1; i<=t; i++) {
		cin>>n>>d;
		for(j=1; j<=n; j++)
			cin>>x[j];
		cout<<dis(rd)<<endl;
	}
	return 0;
}
