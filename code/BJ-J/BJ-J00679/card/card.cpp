#include <bits/stdc++.h>
using namespace std;
int main() {
    ifstream fin; fin.open("card.in");
    ofstream fout; fout.open("card.out");
    int n, m;
    int a[500002] = {}, cnt[500002] = {};
    bool vis[500002] = {};
    fin >> n >> m;
    for (int i = 1; i <= n; i++) fin >> a[i];
    for (int i = 1; i <= n; i++) {
        stack<int> stk;
        for (int j = i; j <= n; j++) {
            if (vis[a[j]]) {
                while (stk.top() != a[j]) {
                    vis[stk.top()] = false;
                    stk.pop();
                }
            }
            else {
                stk.push(a[j]);
                vis[a[j]] = true;
            }
        }
        for (int j = 1; j <= m; j++) {
            if (vis[j]) cnt[j]++;
            vis[j] = false;
        }
    }
    for (int i = 1; i <= m; i++) fout << cnt[i] << ' ';
    fin.close(); fout.close(); return 0;
}
