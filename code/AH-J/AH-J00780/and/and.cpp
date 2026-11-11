#include <bits/stdc++.h>
using namespace std;
long long n,m,a[400000];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	long long xl=a[n];
	for(long long i=n-1;i>=n-m+1;i--){
		xl&=a[i];
	}
	cout<<xl;
	return 0;
}
