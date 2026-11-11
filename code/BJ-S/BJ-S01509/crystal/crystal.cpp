#include <bits/stdc++.h>
#define ll long long

using namespace std;

const int N = 5e5+5;
ll n, m, lt = 1, a[N], pre[N];

int main(){
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin>>n>>m;
    for(int i=1; i<=n; i++){
        cin>>a[i];
    }
    sort(a+1, a+1+n);

    pre[1] = 0;
    for(int i=2; i<=n; i++){
        pre[i] = pre[i-1]+1ll*(i-1)*(a[i]-a[i-1]);
        ll l = 1, r = i-1, mid;
        while(l<=r){
            mid = (l+r)>>1;
            ll t = mid-1;
            if(pre[i]-1ll*(a[i]-a[t])*t-pre[t]>m) l = mid+1;
            else r = t;
        }
        lt = max(lt, i-l+1);
    }
    cout<<lt;
    return 0;
}
