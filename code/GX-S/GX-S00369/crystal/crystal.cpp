#include<bits/stdc++.h>
using namespace std;
long long n,m,s,e,ans,tot,a[500001];
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    scanf("%lld%lld",&n,&m);
    for(int i=1;i<=n;i++)
        scanf("%lld",a+i);
    sort(a+1,a+n+1);
    s=e=1;
    while(e<n){
        if(tot+e*(a[e+1]-a[e])<=m){
            tot+=e*(a[e+1]-a[e]);
            e++;
        }
        else
            break;
    }
    if(e==n){
        printf("%lld",n);
        return 0;
    }
    ans=e;
    while(++e<=n){
        tot+=(e-s+1)*(a[e]-a[e-1]);
        while(tot>m){
            tot-=a[e]-a[s];
            s++;
        }
        ans=max(ans,e-s+1);
    }
    printf("%lld",ans);
    return 0;
}
