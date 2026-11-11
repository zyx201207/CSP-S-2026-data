#include<bits/stdc++.h>
using namespace std;
long long c,t,n,d;
long long a[2000006];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	for(long long i=0;i<t;i++){
		cin>>n>>d;
		for(long long j=0;j<n;j++) cin>>a[j];
		cout<<n-3+1;
	}
	return 0;
}

