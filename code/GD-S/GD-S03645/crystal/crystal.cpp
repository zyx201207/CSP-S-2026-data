#include<bits/stdc++.h>
#define int long long
#define N 500005
using namespace std;
int n,m,a[N];
bool check(int mid){
	int sum=0;
	for(int i=1;i<mid;i++) sum+=a[i];
	for(int i=mid;i<=n;i++){
		sum+=a[i]-a[i-mid];
//		if(m>=mid*a[i]-sum) cout<<mid<<" "<<i<<" "<<sum<<endl;
		if(m>=mid*a[i]-sum) return 1;
	}
	return 0;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
	sort(a+1,a+1+n);
	int l=1,r=n,mid,res=0;
	while(l<=r){
		mid=((l+r)>>1);
		if(check(mid)) res=mid,l=mid+1;
		else r=mid-1;
	}
	printf("%lld",res);
    return 0;
}
