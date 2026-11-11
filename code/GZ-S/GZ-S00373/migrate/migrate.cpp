//GZ-S00373 贵阳市华师一学校 蒋金珂
#include<bits/stdc++.h>
using namespace std;
long long n,a[501];
int main() {
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,T;
	cin>>c>>T;
	while(T--) {
		long long m=0;
		cin>>n>>m;
		for(int i=1; i<=n; i++) {
			cin>>a[i];
		}
		if(a[n]-a[1]<=m){
			cout<<n*(n+1)/2<<endl;
		}else{
			cout<<0<<endl;
		}
	}
}

