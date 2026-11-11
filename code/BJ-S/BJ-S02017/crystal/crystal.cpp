#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long a[500005];
long long sum,ans=1,l;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    scanf("%lld%lld",&n,&m);
    for(int i=1;i<=n;i++)scanf("%lld",&a[i]);
    sort(a+1,a+n+1);
    l=1;
    for(int i=2;i<=n;i++){
        sum+=1ll*(i-l)*(a[i]-a[i-1]);
        while(sum>m&&l<=i)sum-=(a[i]-a[l]),l++;
        ans=max(ans,1ll*i-l+1);
    }
    cout<<ans;
}
