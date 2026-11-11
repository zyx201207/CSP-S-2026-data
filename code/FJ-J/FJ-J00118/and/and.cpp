#include <bits/stdc++.h>
using namespace std;

int main(int argc, char** argv) {
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m,mx=0,f;
	cin>>n>>m;
	int a[n+5];
	for(int i=0;i<n;i++)
		cin>>a[n];	
	for(int i=0;i<n;i++){
		for(int j=i;j<n;j++){
			f=(a[i] & a[j]);
			mx=max(f,mx);
	}
	}
	cout<<mx;
	return 0;
}
