#include<bits/stdc++.h>
using namespace std;
long long n,m,a[200005];
int main(){
	freopen("and.in","t",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(long long i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+1+n);
	long long t=a[n];
	for(long long i=2;i<=m;i++){
		t&=a[n-i+1];
	}
	cout<<t;
	return 0;
}
