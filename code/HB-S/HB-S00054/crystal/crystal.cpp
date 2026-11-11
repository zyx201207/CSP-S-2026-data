#include <bits/stdc++.h>
using namespace std;

long long n,m,a[500005],sum,ans;

bool check(long long x)
{
	sum=0;
	for(long long j=1;j<=x;j++){
		sum+=a[x]-a[j];
		if(sum>m){
			return 0;
		}
	}
	return 1;
}

int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);                 
	long long l=1,r=n;
	while(l<=r){
		long long mid=(l+r)/2;
		int t=check(mid);
		if(t==1){
			l=mid+1;
			ans=mid;
		}
		else{
			r=mid-1;
		}
	}
	cout<<ans;
	return 0;//  =)
}                                                                    
