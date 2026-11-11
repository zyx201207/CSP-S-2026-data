#include <bits/stdc++.h>
using namespace std;

int n;
long long m,a[500005];

int main() {
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    long long ans=0;
    int mx=0;
    int r=1;
    for(int i=1;i<=n;i++){
        while(ans+(1ll*(r-i+1)*(a[r+1]-a[r]))<=m&&r+1<=n){
            ans+=(1ll*(r-i+1)*(a[r+1]-a[r]));
            r++;
        }
        mx=max(mx,(r-i+1));
        ans-=(a[r]-a[i]);
    }
    cout<<mx<<"\n";
    return 0;
}
