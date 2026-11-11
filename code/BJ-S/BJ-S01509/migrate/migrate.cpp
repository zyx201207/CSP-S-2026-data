#include <bits/stdc++.h>
#define ll long long

using namespace std;

ll n, d, a[2000005];

void solve(){
    cin>>n>>d;
    for(int i=1; i<=n; i++){
        cin>>a[i];
    }
    cout<<max(0ll, n-d*2+1)<<"\n";
}

int main(){
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    int c, t;
    cin>>c>>t;
    while(t--) solve();
    return 0;
}
