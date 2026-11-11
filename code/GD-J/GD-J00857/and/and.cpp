#include<bits/stdc++.h>
using namespace std;
int n,m,a[200005],b[200005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n);
	for(int i=0;i<n-1;i++){
		b[i]=a[i]&a[i+1];
	}
	sort(b,b+n);
	cout<<b[n-1];
	return 0; 
}
