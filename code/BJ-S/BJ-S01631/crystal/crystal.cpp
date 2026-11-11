#include<bits/stdc++.h>
using namespace std;
#define int long
int n,m,a[500005];
int qzh[500005];
int l,r,ans=1;
signed main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    scanf("%lld%lld",&n,&m);
    for(int i=1;i<=n;i++)scanf("%lld",&a[i]);
    sort(a+1,a+1+n);
    for(int i=1;i<=n;i++){
        qzh[i]=qzh[i-1]+a[i];
    }
    for(int i=n;i>=1;i--){
        if(i<=ans)break;
        l=0,r=i-1;
        while(l<=r){
            int mid=(l+r)>>1;
            int need=qzh[i-1]-qzh[i-mid-1];
            need=mid*a[i]-need;
            if(need<=m){
                ans=max(ans,mid+1);
                l=mid+1;
            }else {
                r=mid-1;
            }
        }
    }
    printf("%lld\n",ans);
    return 0;
}
/*
5 5
1 2 4 8 9
*/
