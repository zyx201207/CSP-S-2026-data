#include<bits/stdc++.h>
#define int long long
using namespace std;
const int MAXN=5e5+5;
int n,m,a[MAXN],ans=1,dp[MAXN];
int l=1;
signed main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    scanf("%lld%lld",&n,&m);
    for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
    sort(a+1,a+n+1);
    dp[1]=1;
    for(int i=2,s=m;i<=n;i++){
        int sub=a[i]-a[i-1],num=dp[i-1];
        while(s<sub*num){
            s+=a[i-1]-a[l];
            num--;
            l++;
        }
        s-=sub*num;
        dp[i]=num+1;
        ans=max(ans,dp[i]);
    }
    printf("%lld",ans);
    return 0;
}