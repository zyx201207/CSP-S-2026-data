#include <bits/stdc++.h>
using namespace std;
//g++ crystal.cpp -o crystal -std=c++14 -Wall -O2

typedef long long ll;
const int N = 5e5 + 5;
int n;
ll m;
ll a[N], d[N], sum[N], cost[N];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    // freopen("crystal4.in", "r", stdin);
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    cin>>n>>m;
    for(int i=1; i<=n; i++){
        cin>>a[i];
    }
    sort(a+1, a+1+n);
    for(int i=1; i<=n; i++){
        d[i] = a[i] - a[i-1];
        sum[i] = sum[i-1] + a[i];
        cost[i] = cost[i-1] + (ll)(i-1) * d[i];
        // cout<<cost[i]<<' ';
    }
    // cout<<'\n';
    //cost l~r = cost[r] - (((l-1)-1+1)*a[r] - sum[l-1])
    int ans = 0;
    for(int l=1, r=1; l<=n; l++){
        ll res = cost[r] - ((ll)(l-1)*a[r] - sum[l-1]);
        if(res > m) continue;
        while(r <= n && res <= m){
            ans = max(ans, r-l+1);
            r++;
            res = cost[r] - ((ll)(l-1)*a[r] - sum[l-1]);
        }
    }
    cout<<ans;
    return 0;
}