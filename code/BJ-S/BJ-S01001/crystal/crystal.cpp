#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

long long n,m,a[500010],ans=1;
__int128 d[500010],s[500010],sd[500010];

bool f(long long x,long long i){
    if(sd[x]-sd[i]-(s[x]-s[i])*(i-1)<=m){
        return 1;
    }
    return 0;
}

int main(){
    ios::sync_with_stdio(false);
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(long long i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    for(long long i=2;i<=n;i++){
        d[i]=a[i]-a[i-1];
        s[i]=d[i]+s[i-1];
        d[i]*=(i-1);
        sd[i]=d[i]+sd[i-1];
    }
    for(long long i=1;i<=n;i++){
        long long l=i,r=n;
        while(l<=r){
            long long mid=(l+r)/2;
            if(f(mid,i)){
                l=mid+1;
                ans=max(ans,mid-i+1);
            }else{
                r=mid-1;
            }
        }
    }
    cout<<ans;
    return 0;
}
