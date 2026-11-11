#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,m,a[600000];
bool check(int x){
    int now=0;
    for(int i=1;i<=x;i++){
        now+=a[i];
    }
    for(int i=x;i<=n;i++){
        if(x*a[i]-now<=m) return 1;
        now-=a[i-x+1];
        now+=a[i+1];
    }
    return 0;
}
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+n+1);
    int l=1,r=n;
    while(l<r){
        int mid=(l+r+1)>>1;
        if(check(mid)) l=mid;
        else r=mid-1;
    }
    cout<<l<<endl;
    return 0;
}

