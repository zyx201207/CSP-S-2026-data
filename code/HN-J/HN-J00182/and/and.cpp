#include<bits/stdc++.h>
using namespace std;
int main(){
	int n,m;
	cin>>n>>m;
	int a[200005]={};
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	cout<<a[n-m+1];
	return 0;
}
