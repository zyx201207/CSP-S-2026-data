#include<bits/stdc++.h>

using namespace std;

int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,a[100000],b,k;
	cin>>n>>b;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n);
	k=a[n];
	for(int i=n-1;i>=n-b+1;i--){
		k=(k & a[i]);
	}
	cout<<k;
	return 0;
}
