#include<bits/stdc++.h>
using namespace std;
#define fr(i,a,b) for(int i=(a);i<=(b);++i)
#define rp(i,a,b) for(int i=(a);i>=(b);--i)
#define int long long
const int N=5e5+5;
int n,m,a[N],s[N],ans;
signed main() {
  freopen("crystal.in","r",stdin);
  freopen("crystal.out","w",stdout);
  scanf("%lld%lld",&n,&m);
  fr(i,1,n) scanf("%lld",a+i);
  sort(a+1,a+1+n);
  fr(i,1,n) s[i]=s[i-1]+a[i];
  fr(i,1,n) {
    int l=1,r=n;
    while(l<=r) {
      int mid=(l+r)>>1;
      int nd=a[i]*(i-mid+1)-(s[i]-s[mid-1]);
      if(nd<=m) r=mid-1;
      else l=mid+1;
    }
    ans=max(ans,i-r);
  }
  printf("%lld\n",ans);
	return 0;
}