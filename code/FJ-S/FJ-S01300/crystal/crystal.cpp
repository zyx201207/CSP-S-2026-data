#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],b[500005],ans[500005];
int main() {
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1; i<=n; i++) {
		scanf("%lld",&a[i]);
	}
	sort(a+1,a+n+1);
	for(int i=1; i<=n; i++)b[i]=b[i-1]+a[i];
	for(int i=1; i<=n; i++) {
		if(i*a[i]-b[i]<=m) {
			ans[i]=i;
		} else {
			int l=1,r=i;
			int mid=(l+r)/2;
			while(1) {
				if((i-mid)*a[i]-(b[i]-b[mid])<=m&&(i-mid+1)*a[i]-(b[i]-b[mid-1])>m) {
					break;
				} else if((i-mid)*a[i]-(b[i]-b[mid])<m) {
					r=mid;
					mid=(l+r)/2;
				} else if((i-mid)*a[i]-(b[i]-b[mid])>=m) {
					l=mid;
					mid=(l+r+1)/2;
				}
			}
			ans[i]=i-mid;
		}
	}
	long long s=0;
	for(int i=1;i<=n;i++)s=max(s,ans[i]);
	cout<<s;
	return 0;
}

