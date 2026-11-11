#include <bits/stdc++.h>
using namespace std;
int n;
long long m,a[500005],s[500005];
int main(){freopen("crystal.in","r",stdin);freopen("crystal.out","w",stdout);
    scanf("%d%lld",&n,&m);
    for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++) s[i]=s[i-1]+a[i];int ans=0;
    for(int i=1;i<=n;i++){
        int l=1,r=i,mid;
        while(l<=r){
            mid=(l+r)/2;
            if((i-mid+1)*a[i]-(s[i]-s[mid-1])<=m) r=mid-1;
            else l=mid+1;
        }
        ans=max(ans,i-l+1);
    }printf("%d",ans);
    return 0;
}
