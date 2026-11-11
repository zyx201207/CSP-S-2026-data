#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N=5e5+5;
ll a[N],m;
int n;
int main() {
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);

    ios::sync_with_stdio(0); cin.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;++i) {
        cin>>a[i];
    }
    sort(a+1,a+1+n);
    int ans=0;
    ll S=0;
    int j=1;
    for(int i=1;i<=n;++i) {
        S+=(i-j)*(a[i]-a[i-1]);
        while(S>m) S-=a[i]-a[j],++j;
        ans=max(ans,i-j+1);
    }
    cout<<ans<<'\n';
}