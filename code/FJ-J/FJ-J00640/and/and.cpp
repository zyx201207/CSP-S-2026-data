#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[200005];
int ans;
int main(){
	freopen("and.in","r",strin)
	freopen("and.out","w",strout)
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	cout<<a[n-m+1];
	return 0;
}
