#include<bits/stdc++.h>
#define ll long long
#define PB push_back
using namespace std;
const int N=5e5+10;
ll a[N],d[N],n,m,l=1,r=2,sum=0,ans=1;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++) scanf("%lld",a+i);
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++) d[i]=a[i]-a[i-1];
	while(l<=r){
		for(;sum+d[r]*(r-l)<=m&&r<=n;r++) sum+=d[r]*(r-l);
		ans=max(ans,r-l);
		sum-=(a[r-1]-a[l]),l++;
//		printf("l=%lld r=%lld sum=%lld\n",l,r,sum); 
	}
	printf("%lld\n",ans);
 	return 0;
}
