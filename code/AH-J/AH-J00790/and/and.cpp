#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m;
int a[200005],dp[200005];
signed main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    int mx=-1e9+7;
    for(int i=1;i<=n+m;i++){
        for(int j=1;j<=i;j++){
            mx=max(a[j]&a[j+1],mx);
       }
    }
    cout<<mx;
    return 0;
}
