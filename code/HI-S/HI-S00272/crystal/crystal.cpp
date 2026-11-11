#include<bits/stdc++.h>
using namespace std;
long long a[500005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m;cin>>n>>m;
	for(long long i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	int ans=0;
	long long l=1,r=n,mid=(l+r)/2;
	while(l<r){
		long long sum=0;
		for(long long j=mid-1;j>=1;j--){
			sum=a[mid]-a[j]+sum;
			if (sum>m){
				if (mid-j>ans)ans=mid-j;
				r=mid-1;
				mid=(l+r)/2;
				break;
			}
			if (j==1){
				if (mid>ans)ans=mid;
				l=mid+1;
				mid=(l+r)/2;
			}
		}
	}
	cout<<ans;
	return 0;
}
