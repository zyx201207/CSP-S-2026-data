#include<bits/stdc++.h>
#define N 500010
#define ll long long
using namespace std;
int n,ans=0;
ll m,a[N],s[N];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%d%lld",&n,&m);
	for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
	sort(a+1,a+1+n);
	s[0]=0;
	for(int i=1;i<=n;i++) s[i]=s[i-1]+a[i];
	int l,r,mid;
	ll x;
	for(int i=1;i<=n;i++){
		l=1;
		r=i;
		while(l<r){
			mid=(l+r)/2;
			x=(i-mid+1)*a[i]-(s[i]-s[mid-1]);
			if(x<=m) r=mid;
			else l=mid+1;
		}
		ans=max(ans,i-l+1);
	}
	printf("%d",ans);
	return 0;
}
