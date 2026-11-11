#include <bits/stdc++.h>
#define int long long
using namespace std;
int n,m;
int a[500005];
int b[500005];
int p[500005];
int ans=1;
bool check(int x){
    if(x==1) return true;
    for(int i=x;i<=n;i++){
        p[i]=0;
    }
    for(int i=2;i<=x;i++){
        p[x]+=(b[i]*(i-1));
    }
    for(int i=x+1;i<=n;i++){
        p[i]=p[i-1]+(x-1)*b[i]-(a[i-1]-a[i-x]);
    }
    for(int i=x;i<=n;i++){
        if(p[i]<=m) return true;
    }
    return false;
}
signed main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+n+1);
    if(m==0){
        cout<<1;
        return 0;
    }
    for(int i=2;i<=n;i++){
        b[i]=a[i]-a[i-1];
    }
    int l=1;
    int r=n;
    while(l<=r){
        int mid=(l+r)/2;
        if(check(mid)){
            ans=mid;
            l=mid+1;
        }else{
            r=mid-1;
        }
    }
    cout<<ans;
    return 0;
}
