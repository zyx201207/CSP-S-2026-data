#include <bits/stdc++.h>
using namespace std;
long long n,m,a[500001],qzh[500001],res;
pair <long long,long long> maxx;
long long check(long long x){
    long long l=1,r=x,ans=0;
    while(l<=r){
        long long mid=(l+r)/2;
        if (maxx.first*(x-mid+1)-qzh[x]+qzh[mid-1]<=m){
            ans=mid;
            r=mid-1;
        }
        else l=mid+1;
    }
    return ans;
}
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for (long long i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+1+n);
    for (long long i=1;i<=n;i++) qzh[i]=qzh[i-1]+a[i];
    maxx={a[1],1};
    for (long long i=2;i<=n;i++){
        if (a[i]>maxx.first){
            maxx={a[i],i};
            if (check(i-1)!=0) res=max(res,i-check(i-1)+1);
        }
    }
    cout<<res;
    return 0;
}
