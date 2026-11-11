#include<bits/stdc++.h>
#define LL long long
using namespace std;
const LL MAXN=5e5+100;
LL n,m,ans=1,a[MAXN];
LL pre[MAXN];
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;++i){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    pre[0]=0;
    pre[1]=a[1];
    for(int i=2;i<=n;++i){
        pre[i]=pre[i-1]+a[i];
    }

    for(LL i=2,r,l,mid;i<=n;++i){
        r=i,l=1;
        while(l<=r){
            mid=(l+r)>>1;
            if(((i-mid)*a[i]-(pre[i-1]-pre[mid-1]))<=m){
                r=mid-1;
                ans=max(ans,i-mid+1);
            }
            else{
                l=mid+1;
            }
        }
    }

    cout<<ans;
    return 0;
}
