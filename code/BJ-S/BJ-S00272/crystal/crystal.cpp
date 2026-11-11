#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int N=5e5+10;
int n;
ll m,a[N],cha[N],sum[N],pre[N],prc[N];
int ans;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    scanf("%d%lld",&n,&m);
    for(int i=1;i<=n;i++){
        scanf("%lld",&a[i]);
    }
    sort(a+1,a+n+1);
    pre[1]=a[1];
    for(int i=2;i<=n;i++){
        pre[i]=a[i]+pre[i-1];
    }
    for(int i=1;i<=n;i++){
        int l=1,r=i;
        ll x=1LL*i*a[i]-m;
        while(l<r){
            int mid=(l+r)>>1;
            ll y=x-1LL*(mid-1)*a[i];
            if(pre[i]-pre[mid-1]>=y)r=mid;
            else l=mid+1;
        }
        ans=max(ans,i-l+1);
    }
    printf("%lld\n",ans);
    return 0;
}
