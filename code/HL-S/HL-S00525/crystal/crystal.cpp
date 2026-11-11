#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e6+5;
ll n,m,a[N],b[N],s[N],ans,d;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    scanf("%lld%lld",&n,&m);
    for(int i=1;i<=n;i++){
        scanf("%lld",&a[i]);
    }
    sort(a+1,a+1+n);
    d=a[n]-a[n-1];
    for(int i=n-1;i;i--){
        s[i]=a[n]-a[i];
        if(a[i+1]-a[i]!=d){
            d=-1;
        }
    }
    if(d!=-1){
        for(ll i=n;i;i--){
            if((i-1)*i/2*d<=m){
                ans=i;
                break;
            }
        }
        printf("%lld",ans);
        return 0;
    }
    for(int i=n-1;i;i--){
        s[i]=s[i+1]+s[i];
    }
    ans=1;
    for(int i=n-1;i>=1;i--){
        if(i!=n-1&&a[i+1]==a[i+2])
            continue;
        ll l=0;
        ll r=i;
        for(int j=1;j<=i;j++){
            s[j]-=s[i+1]*(i-j+2);\
        }
        while(l+1<r){
            ll w=(l+r)>>1;
            if(s[w]<=m)
                r=w;
            else
                l=w;
        }
        ans=max(ans,i-r+2);
    }
    printf("%lld\n",ans);
    return 0;
}
