#include <bits/stdc++.h>
#define int long long
#define lovely ios::sync_with_stdio(false),cin.tie(0)
#define ly cin
#define lzy cout
using namespace std;
const int maxn=5e5+10;
int a[maxn],sum[maxn];
int n,m;
bool check(int mid){
    for(int i=1;i<=n-mid+1;i++){
        int x=a[i+mid-1];
        if(x*mid-(sum[i+mid-1]-sum[i-1])<=m)return true;
    }
    return false;
}
signed main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    lovely;
    ly>>n>>m;
    for(int i=1;i<=n;i++)ly>>a[i];
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++)sum[i]=sum[i-1]+a[i];
    int l=1,r=n,ans=0;
    while(l<=r){
        int mid=(l+r)/2;
        if(check(mid))ans=mid,l=mid+1;
        else r=mid-1;
    }
    lzy<<ans<<"\n";
    return 0;
}