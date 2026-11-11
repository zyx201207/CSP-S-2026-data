#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],b[500005];
int main(){
	freopen( "crystal.in","r",stdin );
	freopen( "crystal.out","w",stdout );
	cin>>n>>m;
	for( long long i=1; i <= n; i++){
		cin>>a[i];
	}
	sort( a+1,a+n+1 );
	for( long long i=1; i <= n; i++){
		b[i]=a[i]+b[i-1];
		cout<<b[i]<<endl;
	}
	long long f=m+1;
	for( ; f > m; n--){
		long long x=n;
		long long s=a[x]*(x-1);
		f=s-b[x];
	}
	n++;
	cout<<n;
	return 0;
}


