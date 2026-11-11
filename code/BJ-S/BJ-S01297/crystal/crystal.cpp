#include<bits/stdc++.h>
#define int long long
using namespace std;
int a[500009];
int pre[500009];
int n,m;
bool check(int x){
    bool ok=0;
    for(int i=x;i<=n;++i){
        if(a[i]*x<=pre[i]-pre[i-x]+m){
            ok=1;
        }
    }
    return ok;
}
signed main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;++i){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    for(int i=1;i<=n;++i){
        pre[i]=pre[i-1]+a[i];
    }
    int l=1,r=n,ans=1;
    while(l<=r){
        int mid=(l+r)/2;
        if(check(mid)){
            l=mid+1;
            ans=mid;
        }else{
            r=mid-1;
        }
    }
    cout<<ans<<'\n';
    return 0;
}