#include<iostream>
#include<algorithm>
using namespace std;
long long n,m,a[500005],sum[500005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;++i)cin>>a[i];
	stable_sort(a+1,a+n+1);
	for(int i=1;i<=n;++i)sum[i]=sum[i-1]+a[i];
	int l=1,r=n;
	while(l<r){
		int mid=(r+l+1>>1);
		for(int i=mid;i<=n;++i)
			if(a[i]*mid-(sum[i]-sum[i-mid])<=m)l=mid;
		if(l<mid)r=mid-1;
	}
	cout<<l;
	return 0;
}