#include<bits/stdc++.h>
using namespace std;
int main() {
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m,mid;
	cin>>n>>m;
	int a[500000+10];
	for(int i=1; i<=n; i++) {
		cin>>a[i];
	}
	int cnt=0;
	sort(a+1,a+1+n);
	mid=n/2+1;
	for(int i=1; i<mid; i++) {
		if(a[i]==a[mid]) {
			cnt++;
			continue;
		}
		m-=abs(a[mid]-a[i]);
		if(m<0) break;
		a[i]=a[mid];
		if(m==0) break;
	}
	for(int i=1; i<=n; i++) {
		if(a[i]==a[mid]) cnt++;
	}
	cout<<cnt;
	return 0;
}

