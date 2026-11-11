#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
long long a[N],dp[N],m,sum;
int ans,n;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    scanf("%d%lld",&n,&m);
    for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
    sort(a+1,a+n+1);
    int l=1,r=1;
    for(r;r<=n;r++){
        dp[r]=dp[r-1]+(r-l)*(a[r]-a[r-1]);
        while(dp[r]>m&&l<r){
            dp[r]-=a[r]-a[l];
            l++;
        }
        ans=max(ans,r-l+1);
    }
    printf("%d",ans);
    return 0;
}
