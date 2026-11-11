#include <bits/stdc++.h>
using namespace std;
const long long N=5e5+5;
long long n,a[N],m;
bool check(long long x){
    long long tmp=a[x],sum=0;
    for(long long i=1;i<=x;i++)
        sum+=tmp-a[i];
    return sum<=m;
}
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(long long i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+n+1);
    long long l=1,r=n+1;
    while(l<r){
        long long mid=(l+r)>>1;
        if(check(mid)) l=mid+1;
        else r=mid;
    }
    cout<<l-1;
    return 0;
}
