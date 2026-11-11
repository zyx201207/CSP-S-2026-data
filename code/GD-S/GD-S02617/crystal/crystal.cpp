#include<bits/stdc++.h>
using namespace std;
long long a[100001];
struct node {
	int id;
	int hh;
} b[100001];
bool cmp(node x,node y) {
	if(x.hh==y.hh) {
		return x.id<y.id;
	}
	return x.hh<y.hh;
}
int main() {
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m;
	int ans=0;
	cin>>n>>m;
	for(int i=1; i<=n; i++) {
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1; i<=n; i++) {
		b[i].hh=a[i+1]-a[i];
		b[i].id=i;
	}
	sort(b+1,b+n+1,cmp);
	for(int i=0; i<n; i++) {
		if(m>=b[i].hh) {
			b[i].hh=0;
			m=m-b[i].hh;
		}
	}
	for(int i=1; i<=n; i++) {
		if(b[i].hh==0) {
			ans++;
		}
	}
	cout<<ans-1;
	return 0;
}
