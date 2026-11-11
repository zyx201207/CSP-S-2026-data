//bi-solve
#include <bits/stdc++.h>
using namespace std;
const int LEN=5e5+5;
typedef long long int ll;
ll n,m,a[LEN],sum[LEN];
int ans = 0,pos;//ans:
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    for (int i=1;i<=n;i++)
        cin>>a[i];
    sort(a+1,a+n+1);
    for (int i=1;i<=n;i++)
        sum[i] = sum[i-1]+a[i];
    int l=1,r=1,l0,r0;
    ll c = 0;
    //We had recognized that the answer must be contributed by a segment in a row;
    //cal [l,r] to get sum,compare it with m,if it's bigger,adjust:
    // let l++ and adjust sum;
    while (r <= n){
        ++r;
        c = a[r] * (r-l+1) - sum[r] + sum[l-1];
        while(c > m && l <= r){
            ++l;
            c = a[r] * (r-l+1) - sum[r] + sum[l-1];
        }
        if (r-l+1 > ans)
            ans = r-l+1;
        //cout<<c<<" "<<m<<"\n";
    }
    cout<<ans;
    return 0;
}
