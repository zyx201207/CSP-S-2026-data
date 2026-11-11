#include <bits/stdc++.h>
using namespace std;
long long a[277813];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	long long c,t;
	cin>>c>>t;
	for(long long i=0;i<t;i++){
		long long n,m;
		cin>>n>>m;
		for(int j=0;j<n;j++){
			cin>>a[i];
		}
		long long rain=n%4;
		long long black=n/4;
		long long rose=rain+black;
		cout<<rose<<"\n";
	}
	return 0;
}
