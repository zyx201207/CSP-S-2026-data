#include <bits/stdc++.h>
#define int long long
using namespace std;
int n,m,mx=INT_MIN,mid1,mid2,a[500005],pre[500005];
bool check(int d){
    for(int i=d;i<=n;++i){
        if((a[i]*d)-(pre[i]-pre[i-d])<=m){
            return 1;
        }
    }
    return 0;
}
signed main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;++i) cin>>a[i];
    sort(a+1,a+n+1);
    for(int i=1;i<=n;++i) pre[i]=pre[i-1]+a[i];
    int l=1,r=n;
    while(l<r){
        int mid=(l+r+1)>>1;
        if(check(mid)) l=mid;
        else r=mid-1;
    }
    cout<<l;
    cout.flush();
    return 0;
}