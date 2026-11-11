#include<bits/stdc++.h>
using namespace std;
long long a[510000];
long long sum[510000],ans[510000];
int main () {
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	for(long long i=1; i<=n; i++) {
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	ans[2]=a[2]-a[1];
	for(long long i=3; i<=n; i++) {
		ans[i]=(i-1)*(a[i]-a[i-1])+ans[i-1];
	}
	long long l=1,r=2;
	long long maxn=1;
	while(r<=n) {
		if((ans[r]-ans[l])<=m) {
			maxn=max(maxn,r-l+1);
			r++;
		} else {
			l++;
		}
	}
	cout<<maxn<<endl;
	return 0;
}
