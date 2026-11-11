#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],l,r,ans=1,mid,sum[500055];
int check(long long k){
	long long mn=1e18,ol;
	for(int i=1,j;i+k-1<=n;i++){
		j=i+k-1;
		ol=sum[j]-sum[i-1];
		mn=min(mn,k*a[j]-ol);
	}
	return mn<=m;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		sum[i]=sum[i-1]+a[i];
	}
	l=1;r=n;
	while(l<=r){
		mid=(l+r)>>1;
		if(check(mid)){
			l=mid+1;ans=mid;
		}else r=mid-1;
	}
	cout<<ans<<"\n";
	return 0;
}
