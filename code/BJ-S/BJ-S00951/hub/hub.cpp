#include <bits/stdc++.h>
using namespace std;
#define ll long long

int C, c, T, t, n, k;

int BFS(int st, int en, int li, int sum) {
    if (st == en) return sum;
    if (sum >= ans) return sum;
    for (int i = 0; i < m;++i) {
        if(lj[st][i] != 0 && i != li) {
            return BFS(i, en, st, sum) + lj[];
        }
    }
}

int main() {
    freopen("hub.in", "r", stdin);
    freopen("hub.out", "w", stdout);

    cin >> c >> t; C = c; T = t; while(T--) {
        int n,k; cin >> n >> k; bool lj[n][n] = {false};
        for (int i = 1; i < n; i++) {
            int tmp, temp; cin >> tmp >> temp;
            lj[tmp][temp] = true;
        }
    }


    return 0;
}