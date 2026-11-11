#include<bits/stdc++.h>
using namespace std;
int n,ans;
long long m,a[514114],h[514114];
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    scanf("%d%lld",&n,&m);
    for(int i=1;i<=n;i++) scanf("%lld",a+i);
    sort(a+1,a+n+1);
    for(int i=2;i<=n;i++) h[i]=(i-1)*(a[i]-a[i-1])+h[i-1];
    for(int i=n;i>1;i--){
        int l=1,r=i;
        while(1){
            int mid=(l+r)>>1;
            int t=h[i]-h[mid]-(mid-1)*(a[i]-a[mid]);
            if(t>m) l=mid+1;
            else if(l==r){
                ans=max(ans,i-mid);
                break;
            }
            else if(t<=m) r=mid;
        }
    }
    printf("%d",ans+1);
    return 0;
}
