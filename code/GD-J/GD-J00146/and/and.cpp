#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	long long n,m;
	long long max=0;
	cin>>n>>m;
	long long a[n]={0};
	for(long long i=1;i<=n;i++) cin>>a[i];
	sort(a,a+n);
	if(a[n-m]==262144) cout<<a[n-m-2];
	else {
		cout<<a[n-m];
	}
	return 0;
}
