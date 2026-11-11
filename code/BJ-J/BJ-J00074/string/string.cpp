#include<bits/stdc++.h>

using namespace std;

unsigned long long cnt[10010], ans, n, maxn;

int main(){
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    cin >> n;

    for(int i = 1; i <= n; i++){
            int x;
            char c;
            cin >> x >> c;
            cnt[c - 'a'] += x;
            maxn = max(maxn, cnt[c - 'a']);
            ans += x;
    }

    cout << ans - maxn << endl;

    return 0;
}