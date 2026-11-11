#include<bits/stdc++.h>
using namespace std;
int a[1000000000],n,m,c,b;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n-m+1;i++){
		c=a[i];
		for(int j=1;j<=m-1;j++){
			c=(c & a[i+j]);
		}
		b=max(c,b);
	}
	cout<<b;
	return 0;
}
