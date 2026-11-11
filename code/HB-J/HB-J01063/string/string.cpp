#include<bits/stdc++.h>

using namespace std;

const int maxN = 2e5 + 10;
long long n, a[maxN], len = 0, ans = 0, slv = 0;
char c[maxN];

void solve(){
    int Lnote = 1, Rnote = n;

    while(slv < (len  >> 1)){
        if(a[Lnote] > a[Rnote]){
            if(c[Lnote] != c[Rnote]){
                ans += a[Rnote];
            }
            slv += a[Rnote];

            a[Lnote] -= a[Rnote];
            Rnote --;
        }else if(a[Lnote] < a[Rnote]){
            if(c[Lnote] != c[Rnote]){
                ans += a[Lnote];
            }
            slv += a[Lnote];

            a[Rnote] -= a[Lnote];
            Lnote ++;
        }else if(a[Lnote] == a[Rnote]){
            if(c[Lnote] != c[Rnote]){
                ans += a[Lnote];
            }
            slv += a[Lnote];

            Lnote ++;
            Rnote --;
        }
    }
    return;
}

int main(){
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n;

    for(int i = 1; i <= n;i ++){
        cin >> a[i] >> c[i];
        len += a[i];
    }

    solve();

    cout << ans;

    return 0;
}
