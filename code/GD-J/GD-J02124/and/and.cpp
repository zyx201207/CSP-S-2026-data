#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	long long n,m,i,a[200100],z;
	cin>>n>>m;
	for(i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n);
	z=a[n-1];
	for(i=n-2;i>=n-m;i--){
		z=long(z&a[i]);
	}
	cout<<z;
	return 0;
}
