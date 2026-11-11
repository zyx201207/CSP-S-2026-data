#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=2e5+5;
ll a[N];
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m;cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }sort(a+1,a+n+1);
    ll ans=LONG_LONG_MAX;
    for(int i=1;i<=m;i++){
        ans=ans&a[n-i+1];
    }cout<<ans;
    return 0;
}
