#include<bits/stdc++.h>
#define N 500010
using namespace std;
typedef long long ll;
ll n,m,a[N],pre[N],ans;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;++i) scanf("%lld",&a[i]);
	sort(a+1,a+1+n);
	for(int i=1;i<=n;++i) pre[i]=pre[i-1]+a[i];
	for(int i=1;i<=n;++i){
		int l=1,r=i,mid;
		while(l<r){
			mid=l+r>>1;
			if(a[i]*(i-mid+1)-(pre[i]-pre[mid-1])<=m) r=mid;
			else l=mid+1;
		}
		ans=max(ans,(ll)i-l+1);
	}
	printf("%lld\n",ans);
	return 0;
}
