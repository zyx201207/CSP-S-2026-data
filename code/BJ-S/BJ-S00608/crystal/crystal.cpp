#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,a[500005];
bool check(int mid){
    int cost=0;
    for(int i=1;i<=mid;i++)cost+=a[mid]-a[i];
    if(cost<=m)return 1;
    for(int i=mid+1;i<=n;i++){
        cost+=(a[i]-a[i-1])*(mid-1)-(a[i-1]-a[i-mid]);
        if(cost<=m)return 1;
    }
    return 0;
}
signed main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];
    sort(a+1,a+n+1);
    int l=1,r=n;
    while(l<r){
        int mid=(l+r+1)>>1;
        if(check(mid))l=mid;
        else r=mid-1;
    }
    cout<<l;
    return 0;
}