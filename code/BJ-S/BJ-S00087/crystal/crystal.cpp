#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,s[500010],sum[500010];
signed main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    scanf("%lld %lld",&n,&m);
    for(int i=1;i<=n;i++){
        scanf("%lld",&s[i]);
    }
    sort(s+1,s+n+1);
    for(int i=1;i<=n;i++){
        sum[i]=sum[i-1]+s[i];
    }
    int ans=0;
    for(int i=1;i<=n;i++){
        //printf("i %lld\n",i);
        int l=1,r=i;
        while(l<r){
            //printf("l %lld r %lld\n",l,r);
            int mid=(l+r)>>1;
            if(sum[i]-sum[mid-1]+m>=s[i]*(i-mid+1)){
                r=mid;
            }
            else{
                l=mid+1;
            }
        }
        ans=max(ans,i-l+1);
    }
    printf("%lld\n",ans);
    return 0;
}
