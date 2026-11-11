#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,m,a[500010],pre[500010],mx=0;
bool check(){
    for(int i=2;i<=n;i++){
        if(a[i]<a[i-1]) return false;
    }
    return true;
}
signed main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    if(!check()) sort(a+1,a+n+1);
    for(int i=1;i<=n;i++) pre[i]=pre[i-1]+a[i];
    for(int i=1;i<=n;i++){
        int l=1,r=i,mid,ans;
        while(l<=r){
            mid=l+(r-l)/2;
            if(a[i]*(i-mid+1)-(pre[i]-pre[mid-1])<=m){
                ans=mid;
                r=mid-1;
            }
            else l=mid+1;
        }
        mx=max(mx,i-ans+1);
    }
    cout<<mx;
    return 0;
}
