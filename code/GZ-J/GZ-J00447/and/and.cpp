#include<bits/stdc++.h>
using namespace std;
long long n,m,x,a[10005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
	}
	x=a[1];
	for(long long i=2;i<=n;i++){
		if(a[i]<x) x=a[i];
	}
	cout<<x;
	return 0;
}
