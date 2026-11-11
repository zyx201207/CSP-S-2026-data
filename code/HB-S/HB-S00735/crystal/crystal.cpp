#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],l=0,r,aas=-0x3f3f3f3f,sum[500005];
bool check(long long x){
	for(long long i=a[x];i<=a[n];i++){
		long long idx=upper_bound(a+1,a+n+1,i)-a-1;
		long long need=idx*i-sum[idx];
		if(idx>=x&&need<=m){return 1;}
	}
	return 0;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;r=n;
	for(int i=1;i<=n;i++){cin>>a[i];}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){sum[i]=sum[i-1]+a[i];}
	while(l<=r){
		long long mid=(l+r)>>1;
		if(check(mid)){l=mid+1;aas=mid;}
		else r=mid-1;
	}
	cout<<aas;
	return 0;
}
