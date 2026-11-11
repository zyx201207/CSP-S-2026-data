#include <bits/stdc++.h>
using namespace std;
int n,m;
int a[500005];
long long ans,ans1,l,t,maxx;
int che(int k) {
	int i=k;
	ans1=ans=0;
	while(i>=1 && ans<=m) {
		ans+=a[k]-a[i];
		++ans1;
		i--;
	}
	return ans1;
}
int main() {
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1; i<=n; i++) {
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	l=1;
	while(l<=n) {
		t=che(l);
		l++;
		maxx=max(maxx,t);
	}
	cout<<maxx;
	return 0;
}