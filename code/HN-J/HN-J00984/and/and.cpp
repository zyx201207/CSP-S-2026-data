#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int a[200005],n,s,r;
	cin>>n>>s;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n+1);
	r=a[n-1]
	for(int i=n-2;i>=n-s-1;i++){
		r=r|a[i];
	}
	cout<<r;
	return 0;
} 
