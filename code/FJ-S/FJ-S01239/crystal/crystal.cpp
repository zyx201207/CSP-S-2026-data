#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
long long n,m,a[N],sub[N],sum[N],maxn=1,cnt=1;
int main() {
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<n;i++) {
		sub[i]=a[i+1]-a[i];
		sum[i]=sum[i-1]+sub[i]*i;
	}
	for(int i=1;i<n;i++) {
		if(sum[i]<=m) maxn=max(maxn,++cnt);
		else {
			long long l=1,r=i;
			while(l<=r) {
				long long mid=(l+r)/2;
				if(sum[i]-(mid-1)*(a[i+1]-a[mid])-sum[mid-1]<=m) r=mid-1;
				else l=mid+1;
			}
			maxn=max(maxn,(long long)(i-r+1));
		}
	}
	cout<<maxn;
	return 0;
} 
