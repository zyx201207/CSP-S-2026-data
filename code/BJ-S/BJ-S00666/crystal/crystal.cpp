#include<bits/stdc++.h>
using namespace std;
const long long N=5e5+29;
long long a[N],sum[N];
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    long long n,m;
    cin>>n>>m;
    for(long long i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+n+1);
    for(long long i=1;i<=n;i++) sum[i]=sum[i-1]+a[i];
    long long maxx=0;
    for(long long i=1;i<=n;i++){
        long long ans_now=1,val=m;
        long long l=0,r=i-1;
        while(l<r){
            long long mid=(l+r+1)/2;
            if((mid*a[i]-(sum[i-1]-sum[i-mid-1]))<=m) l=mid;
            else r=mid-1;
        }
        ans_now=l+1;
        maxx=max(maxx,ans_now);
    }
    cout<<maxx;
    return 0;
}