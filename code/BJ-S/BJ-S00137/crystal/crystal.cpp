#include <bits/stdc++.h>
#define ll long long
using namespace std;
int n;
ll m,a[500005],pre[500005],maxn;
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    freopen("crystal4.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        pre[i]=pre[i-1]+a[i];
    }
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++){
        int l=i,r=n;
        ll ans=1;
        while(l<=r){
            ll mid=l+(r-l)/2;
            //cout<<i<<'~'<<mid<<' '<<a[mid]*(mid-i+1)<<' '<<pre[mid]-pre[i-1]<<'\n';
            if(a[mid]*(mid-i+1)-(pre[mid]-pre[i-1])<=m){
                l=mid+1;
                ans=max(ans,mid-i+1);
            }
            else r=mid-1;
        }
        maxn=max(maxn,ans);
    }
    cout<<maxn;
    return 0;
}
