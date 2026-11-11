#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
long long n,m,a[N],sum;
bool check(int x) {
    sum=0;
    for(int i=1;i<=x;i++) sum+=(a[x]-a[i]);
    if(sum>m) return false;
    else return true;
}
int main() {
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    long long ans=0;
    sort(a+1,a+1+n);
    long long l=1,r=n;
    while(l<=r) {
        long long mid=(l+r)/2;
        if(check(mid)) l=mid;
        else r=mid;
        if(sum<=m) ans=sum;
    }
    cout<<ans;
    return 0;
}
