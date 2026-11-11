#include <bits/stdc++.h>
using namespace std;
int n,m,a[200003];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
	 	cin>>a[i];
	}
	sort(a,a+n);
	int x=a[n-1];
	for(int i=n-1;i>=n-i;i--){
		x=(x&a[i]);
	}
	cout<<x;
	return 0;
}
