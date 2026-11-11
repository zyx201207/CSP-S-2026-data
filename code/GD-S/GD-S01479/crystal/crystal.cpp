#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e5+10;
ll a[N],sum[N],m;
int n;
bool check(int x){
	for(int i=x;i<=n;i++){
		if(a[i]*x-(sum[i]-sum[i-x])<=m)return 1;
	}
	return 0;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%d%lld",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)sum[i]=sum[i-1]+a[i];
	int l=1,r=n,ret=1;
	while(l<=r){
		int mid=l+r>>1;
		if(check(mid))ret=mid,l=mid+1;
		else r=mid-1;
	}
	printf("%d",ret);
	return 0;
}
