#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a[500005];
int n;
ll m;
int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    cin >> n >> m;
    for(int i = 1; i <= n; i++) cin >> a[i];
    sort(a+1, a+n+1);
    // find a [l, r], make D[l, r] <= m and (r-l+1) maximum.
    int l=1, r=1, maxm=0;
    ll dhsum = 0;
    while(l<=n&&r<=n){
        if(dhsum <= m){
            //try to r++
            r++;
            // update dhsum
            dhsum += (a[r] - a[r-1]) * (r-l);
            maxm = max(maxm, r-l);
        }else{
            // too large, smalling r
            l++;
            dhsum -= a[r] - a[l];
            maxm = max(maxm, r-l);
        }
    }
    cout << maxm;
    return 0;
}