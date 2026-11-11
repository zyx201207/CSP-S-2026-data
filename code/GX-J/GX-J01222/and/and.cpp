#include <cstdio>
#include <bits/stdc++.h>
	
using namespace std;

int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int m,n,a[202600];
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	int h=a[n];
	for(int i=1;i<m;i++){
		h=h&a[n-i];
	}
	cout<<h;
	return 0;
}
