#include<bits/stdc++.h>
using namespace std;
using LL=long long;
const LL N=200010;
LL a[N];
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    LL n,m;
    cin>>n>>m;
    for(LL i=1;i<=n;i++){cin>>a[i];}
    sort(a+1,a+n+1);
    reverse(a+1,a+n+1);
    LL ans=a[1];
    for(LL i=2;i<=m;i++){ans&=a[i];}
    cout<<ans<<'\n';
    return 0;
}
