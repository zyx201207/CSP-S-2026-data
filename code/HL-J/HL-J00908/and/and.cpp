#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("and.in",r,stdin);
	freopen("and.out",w,stdout);
	int n,m,a[10010],b[10010],sum=0,i=0;
	cin>>n>>m;
	for(i=1;i<=n;i++){
		cin>>a[i];
	}sort(a,a+n);
	cout<<a[i-1] and a[i-2];
	return 0;
}