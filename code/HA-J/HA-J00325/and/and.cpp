#include<bits/stdc++.h>
using namespace std;
long long n,m,maxn,a[200005];
bool cmp(long long x,long long y) {
	return x>y;//½µÐò
}
int main() {
	freopen("travel.in","r",stdin);
	freopen("travel.out","r",stdout);
	for(int i=1; i<=n; i++) {
		cin>>a[i];
	}
	sort(a+1,a+n+1,cmp);
	for(int i=1; i<=m; i++) {
		if(i==1) maxn=a[i];
		else maxn=maxn&a[i];
	}
	cout<<maxn;
	return 0;
}
