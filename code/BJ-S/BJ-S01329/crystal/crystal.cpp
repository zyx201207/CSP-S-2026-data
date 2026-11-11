#include <bits/stdc++.h>
using namespace std;

const long long N=500010;

long long n,m,ans;
long long a[N],sum[N],dp[N],cost[N],tot,c2[N]; //sum:和，dp:水晶数量,cost:代价

int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin >> n >> m;
    for (long long i=1;i<=n;i++){
        cin >> a[i];
    }
    sort(a+1,a+n+1);
    tot=1; //指针
    for (long long i=1;i<=n;i++){
        sum[i]=a[i]+sum[i-1];
        c2[i]=c2[i-1]+(a[i]-a[i-1])*(i-1);
    }
    for (long long i=1;i<=n;i++){
        // long long o=cost[i-1]+(a[i]-a[i-1])*(i-tot);
        long long o=c2[i]-c2[tot]-(tot-1)*(a[i]-a[tot]);
        if (o<=m){
            dp[i]=i-tot+1;
            //cost[i]=o;
        }
        else{
            long long l=tot,r=i,mid;
            while(l<r){
                mid=(l+r)>>1;
                if (c2[i]-c2[mid]-(mid-1)*(a[i]-a[mid])>m) l=mid+1;
                else r=mid;
            }
            //cost[i]=o-cost[l]-(l-tot)*(sum[i]-sum[l]);
            tot=l;
            dp[i]=i-tot+1;
            //cost[tot]=0;
            //dp[tot]=1;
        }
        ans=max(ans,dp[i]);
    }
    cout << ans;
}
