#include <bits/stdc++.h>
using namespace std;
const int MAXN = 2e5 + 5;

int N, M;
int arr[MAXN];
bool nok[MAXN];

int main() {
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    memset(nok, 0, sizeof(nok));
    cin >> N >> M;
    for(int i=1; i<=N; i++) {
        cin >> arr[i];
    }
    int ans = 0;
    for(int i=30; i>=0; i--) {
        int cnt = 0;
        for(int j=1; j<=N; j++) {
            if (nok[j]) continue;
            if ((arr[j] >> i) & 1) cnt++;
        }
        if (cnt >= M) {
            ans += (1 << i);
            for(int j=1; j<=N; j++) {
                if (nok[j]) continue;
                if (((arr[j] >> i) & 1) == 0) nok[j] = 1;
            }
        }
    }
    cout << ans;
    return 0;
}