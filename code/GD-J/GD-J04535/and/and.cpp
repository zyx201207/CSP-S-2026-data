#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	
	long long n,m;
	cin>>n>>m;
	long long a[200005]={};
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	long long ans=a[n];
	for(int i=n-1;i>=n-m+1;i--) {
		int r=a[i];
		ans=ans&r;
	}
	cout<<ans;
	return 0;}

