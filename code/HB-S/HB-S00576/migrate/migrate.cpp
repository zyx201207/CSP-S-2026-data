#include <bits/stdc++.h>
using namespace std;
#define ll long long

const int N = 2000005;
int cid,n;
ll d;
ll xt[N];

void solveA(){
    ll k = d / (xt[2] - xt[1]);
    //printf("%d %lld %lld %lld \n", n, d, k, xt[2] -xt[1]);
    if (k <= 1){
        cout << "0\n";
    }
    else{
        cout << max(- 2*k + n + 1, 0ll) << '\n';
    }
}

void solve(){
    cin >> n >> d;
    for (int i = 1; i <= n; i++){
        cin >> xt[i];
    }
    if (11 <= cid && cid <= 12){
        solveA(); return 0;
    }
    ll ans = 0;
}

int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t; cin >> cid >> t;
    while (t--) solve();
    return 0;
}