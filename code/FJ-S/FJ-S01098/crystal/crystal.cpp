#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long a[500005];
long long d[500005],sum[500005];
const long long INF=1e9;

long long get_d(int l,int r){
	return a[r]*(r-l)-(sum[r-1]-sum[l-1]);
}

int main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		sum[i]=sum[i-1LL]+a[i];
	}
	long long ans=-INF;
	if(n<=5000){
		for(int i=1;i<n;i++){
			for(int j=i+1;j<=n;j++){
				if(get_d(i,j)<=m){
					ans=max(ans,j-i+1LL);
				}
			}
		}
	}else{
		int dd=a[2]-a[1];
		for(int i=1;i<=n;i++){
			d[i]=d[i-1]+dd*(i-1);
		}
		ans=upper_bound(d+1,d+1+n,m)-d-1;
	}
	cout<<ans;
	return 0;
}
