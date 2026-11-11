#include <bits/stdc++.h>
using namespace std;
const int MAXN = 5e5 + 5;

long long arr[MAXN];

int main() {
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N;
    long long M;
    cin >> N >> M;
    for(int i=1; i<=N; i++) {
        cin >> arr[i];
    }
    sort(arr + 1, arr + N + 1);
    int l = 1;
    long long num = 0;  // <= M
    int ans = 1;
    for(int i=2; i<=N; i++) {
        num += (i - l) * (arr[i] - arr[i - 1]);
        while (num > M) {
            num -= (arr[i] - arr[l]);
            l++;
        }
        ans = max(ans, i - l + 1);
    }
    cout << ans;
    return 0;
}