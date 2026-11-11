#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
ll m,a[500005];
int b[500005];
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    scanf("%d %lld",&n,&m);
    for(int i=1;i<=n;i++){
        scanf("%lld",&a[i]);
    }
    sort(a+1,a+1+n);
    int ans=0;
    ll old_sum=0;
    for(int i=1;i<=n;++i){
        old_sum+=(a[i]-a[i-1])*b[i-1];
        if(old_sum<=m){
            b[i]=b[i-1]+1;
            ans=max(ans,b[i]);
            continue;
        }
        b[i]=b[i-1];
        for(int j=i-b[i-1]-1;j<=i;++j){
            old_sum-=a[i]-a[j];
            if(old_sum<=m) break;
            --b[i];
        }
        ans=max(ans,b[i]);
    }
    printf("%d",ans);
    return 0;
}
