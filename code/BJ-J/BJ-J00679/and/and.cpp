#include <bits/stdc++.h>
using namespace std;
int main() {
    ifstream fin; fin.open("and.in");
    ofstream fout; fout.open("and.out");
    int n, m;
    int a[200002] = {};
    fin >> n >> m;
    for (int i = 1; i <= n; i++) fin >> a[i];
    int dp[200003] = {};
    dp[0] = 2147483647;
    for (int i = 1; i <= n; i++) {
        for (int j = min(i, m); j >= 1; j--) {
            dp[j] = max(dp[j], dp[j - 1] & a[i]);
            //debugger fout << i << ' ' << j << " : " << dp[j] << '\n';
        }
        dp[0] = 2147483647;
    }
    fout << dp[m];
    fin.close(); fout.close(); return 0;
}
