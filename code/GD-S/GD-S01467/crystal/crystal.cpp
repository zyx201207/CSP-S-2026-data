#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e5+10;
int a[N],sum[N],n,m;
bool check(int x){
	for(int i=1;i+x-1<=n;i++){
		int st=sum[i+x-1]-sum[i-1],ed=a[i+x-1]*x;
		if(ed-st<=m)return 1;
	}
	return 0;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	sum[0]=0;
	for(int i=1;i<=n;i++)scanf("%lld",&a[i]);
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)sum[i]=sum[i-1]+a[i]; 
	int l=1,r=n;
	while(l<r){
		int mid=(l+r)/2;
		if(check(mid))l=mid+1;
		else r=mid;
	}
	printf("%lld\n",l-1);
	return 0;
}
