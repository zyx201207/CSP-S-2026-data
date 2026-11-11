#include<bits/stdc++.h>
#define ll long long 
#define MAXN 500005
using namespace std;
ll a[MAXN];
ll b[MAXN];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n;ll m;
	scanf("%d %lld",&n,&m);
	for(int i=1;i<=n;i++)scanf("%lld",&a[i]);
	sort(a+1,a+n+1);
	for(int i=1;i<n;i++)b[i]=a[i+1]-a[i];
	int l=1,r=1;
	ll cnt=0;
	int ans=0;

	while(r<=n){
		if(cnt+(r-l+1)*b[r]<=m)cnt+=(r-l+1)*b[r],r++;
		else cnt-=a[r]-a[l],l++;
		if(r<=n)ans=max(ans,r-l+1);
		//printf("%lld %lld %lld\n",l,r,cnt);
	}
	printf("%d",ans);
	return 0;
}
