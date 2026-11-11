#include <bits\stdc++.h>
using namespace std;
int main(){
	freopen("and.in","r",stdin) ;
	freopen("and.out","w",stdout) ;
	long long n,m,a[200005];
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n);
	long long max=a[n-1];
	for(int i=1;i<m;i++){
		max=max and a[n-i-1];
	}
	cout<<max;
	return 0;
}
