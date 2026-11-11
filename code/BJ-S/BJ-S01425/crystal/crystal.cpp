#include <bits/stdc++.h>
using namespace std;
int a[500005];
long long sm[500005],n,m;
inline bool check(int l,int r){
    if(1ll*(r-l+1)*a[r]-sm[r]+sm[l-1]<=m){
        return 1;
    }
    return 0;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++){
        sm[i]=sm[i-1]+a[i];
    }
    int l,r,mid;
    int ans=0;
    for(int i=1;i<=n;i++){
        l=1,r=i;
        while(l<r){
            mid=(l+r-1)>>1;
            if(check(mid,i)){
                r=mid;
            }
            else{
                l=mid+1;
            }
        }
        ans=max(ans,i-l+1);
    }
    cout<<ans;
    return 0;
}