#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	long long a[n+5];
	for(long long i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	long long ans=a[n];
	for(long long i=n-1;i>=n-m;i--){
		ans=ans&a[i];
	}
	cout<<ans;
	return 0;
} 
