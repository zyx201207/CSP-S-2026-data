#include<bits/stdc++.h>

using namespace std;
using ll = long long;

const int MAXN = 2e5 + 25;

int n, m;
int a[MAXN];

vector<int>choice;

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);
    cin >> n >> m;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        choice.push_back(i);
    }
    int ans = 0;
    for(int lg = 30; ~lg; lg--) {
        int cnt = 0;
        for(int id : choice) {
            cnt += a[id] >> lg & 1;
        }
        if(cnt >= m) {
            ans |= 1 << lg;
            vector<int>nxt;
            for(int id : choice) {
                if(a[id] >> lg & 1) {
                    nxt.push_back(id);
                }
            }
            choice.swap(nxt);
        }
    }
    cout << ans;
    return 0;
}
