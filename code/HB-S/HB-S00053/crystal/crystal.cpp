#include<bits/stdc++.h>
#define int long long
using namespace std;

const int N = 5e5 + 20;
int A[N];
int S[N];

int calc(int l, int r){
    int len = r - l + 1;
    return A[r] * len - (S[r] - S[l - 1]);
}
signed main(){
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    int n, m; cin >> n >> m;
    for(int i = 1; i <= n; ++i) cin >> A[i];
    sort(A + 1, A + n + 1);
    for(int i = 1; i <= n; ++i)
        S[i] = S[i - 1] + A[i];

    int r = 1, ans = 0;
    for(int l = 1; l <= n; ++l){
        r = max(r, l);
        while(true){
            if(r + 1 <= n && calc(l, r + 1) <= m) ++r;
            else break;
        }
        ans = max(ans, r - l + 1);
    }
    cout << ans << endl;
    return 0;
}
