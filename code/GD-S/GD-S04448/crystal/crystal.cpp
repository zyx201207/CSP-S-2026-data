#include<bits/stdc++.h>
using namespace std;
int n,m,c,s,cnt,mx=0;
int a[500005];
int main() {
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=0; i<n; i++) {
		cin>>a[i];
	}
	if(n%2!=0) {
		c=a[n/2];
	} else {
		c=a[n/2-1];
	}
	for(int i=0; i<n; i++) {
		if(a[i]<=c) {
			if(c-a[i]<=m) {
				cnt++;
				m-=(c-a[i]);
			}
		}
	}
	cout<<cnt;
	return 0;
}
