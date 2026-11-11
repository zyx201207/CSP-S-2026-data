#include<bits/stdc++.h>
using namespace std;
int a[200005];
bool cmp1(int a,int b) {
	return a>b;
}
int main() {
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1; i<=n; i++) {
		cin>>a[i];
	}
	sort(a+1,a+1+n,cmp1);
	int x=a[1];
	for(int i=1; i<=m; i++) {
		x=x&a[i];
	}
	cout<<x;
	return 0;
}
