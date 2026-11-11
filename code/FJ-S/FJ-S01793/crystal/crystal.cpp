#include <cstdio>
#include <algorithm>
#define int long long
using namespace std;
int n,m,a[500005],mx,sum[500005];
inline int query(int l,int r){return sum[r]-sum[l-1];}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++)scanf("%lld",a+i);
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++)sum[i]=sum[i-1]+a[i];
	for(int i=1;i<=n;i++){
		int l=1,r=i,ans=-1;
		while(l<=r){
			int mid=l+r>>1;
			if(a[i]*(i-mid+1)-query(mid,i)<=m)ans=mid,r=mid-1;
			else l=mid+1;
		}
		mx=max(mx,i-ans+1);
	}
	printf("%lld",mx);
}
