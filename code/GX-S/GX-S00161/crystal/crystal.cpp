#include<bits/stdc++.h>
using namespace std;
long long n,m,ans,cnt,maxx=1;
long long a[514514];
int main() {
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(long long i=0;i<n;i++) {
		scanf("%lld",&a[i]);
	}
	sort(a,a+n);
	for(int i=1;i<n;i++) {
		if(i>1&&a[i]==a[i-1]) {
			continue;
		}
		ans=m;
		cnt=0;
		for(int j=0;j<n;j++) {
			if(a[j]<=a[i]&&ans>=a[i]-a[j]) {
				ans-=a[i]-a[j];
				cnt++;
			} else {
				break;
			}
		}
		if(cnt>maxx) {
			maxx=cnt;
		}
	}
	printf("%lld",maxx);
	return 0;
}
