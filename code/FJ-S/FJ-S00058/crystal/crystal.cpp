#include <bits/stdc++.h>
using namespace std;

long long a[500002];
long long n,m;

long long check(int x){
	long long sum=0,cnt=0;
	for (long long i=x;i>=1;i--){
		cnt++;
		sum+=abs(a[x]-a[i]);
		if (sum>m){
			cnt--;
			break;
		}
	}
	return cnt;
}

int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for (long long i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	long long l=1,r=n,ans=-1e12;
	while (l<=r){
		long long mid=(l+r)/2;
		long long now=check(mid);
		if (now>=ans){
			l=mid+1;
			ans=now;
		}
		else{
			r=mid-1;
		}
	}
	cout<<ans;
	return 0;
}

