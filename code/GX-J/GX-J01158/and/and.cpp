#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	long long n,m,jg,bzh;
	long long a[200005];
	bzh=0;
	cin>>n>>m;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	jg=a[n];
	for(long long j=m;j>=1;j--){
		jg=jg&a[n-bzh];
		bzh++;
	}
	cout<<jg;
	return 0;
}
