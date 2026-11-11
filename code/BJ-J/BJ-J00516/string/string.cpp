#include <bits/stdc++.h>
using namespace std;
vector<pair<long long, char>> v;
int main() {
    freopen ("string.in", r, stdin);
    freopen ("string.out", w, stdout);
    long long n, cnt = 0;
    cin >> n;
    for (int k = 1; k <= n; k++) {
        long long a;
        char c;
        cin >> a >> c;
        v.push_back(make_pair(a, c));
    }
    long long i = 0, j = v[v.size() - 1].first + 1;
    long long start = 0, finish = v.size() - 1;
    while (1) {
        i++; j--;
        if (v[start].second != v[finish].second) cnt++;
        if (i == v[start].first) {
            i = 0;
            start++;
        }
        if (j == 0) {
            j == v[finish - 1].first;
            finish--;
        }
        if (start == finish && i >= j) break;
    }
    cout << cnt;
    return 0;
}
