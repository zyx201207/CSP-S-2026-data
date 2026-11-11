#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,ans;
int a[500005],p[500005];
bool f(int x){
    for(int i=x;i<=n;i++){
        if(a[i]*(x-1)-(p[i-1]-p[i-x])<=m)return 1;
    }
    return 0;
}
signed main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];

    }
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++){
        p[i]=p[i-1]+a[i];
    }
    int l=1,r=n;
    while(l<=r){
        int mid=(l+r)/2;
        if(f(mid)){
            l=mid+1;
            ans=mid;
        }else{
            r=mid-1;
        }
    }
    cout<<ans;
    return 0;
}
