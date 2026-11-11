#include<bits/stdc++.h>
using namespace std;
long long a[1000000+10];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	m=n-m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	long long cnt=a[n];
	for(int i=m+1;i<=n;i++) cnt&=a[i];
	cout<<cnt;
	return 0;
}
