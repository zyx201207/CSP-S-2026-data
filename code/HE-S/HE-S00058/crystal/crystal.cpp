#include<bits/stdc++.h>
#include<iostream>
using namespace std;
int n,ans=1;
long long m,a[500005],b[500000];
int cmp(int x1,int y1) {
	return x1>y1;
}
int an(int x,long long y1) {
	for(int i=x; i<=n; i++) b[i]=a[x]-a[i];
	for(int i=x; i<=n; i++) {
		if(y1>=b[i]) y1-=b[i];
		else return i-x;
	}
	return n-x+1;
}
int main() {
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1; i<=n; i++) cin>>a[i];
	sort(a+1,a+n+1,cmp);
	for(int i=1; i<n; i++) {
		int anc=an(i,m);
		if(ans<anc) ans=anc;
	}
	cout<<ans;
	return 0;
}
