#include <bits/stdc++.h>
using namespace std;
int a[500005];
int b[300005];
vector<int> l;
queue<int> q;
bool f(int x) {
    queue<int> q1(q);
    while (!q1.empty()) {
        int t = q1.front();
        q1.pop();
        if (t == x) return 1;
    }
    return 0;
}
int main () {
    freopen("card.in", "r", stdin);
    freopen("card.out", "w", stdout);
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) {
        for (int j = i; j <= n; j++) {
            if (f(a[j])) {
                queue<int> q1;
                while (q.front() != a[j]) {int t = q.front(); q.pop(); q1.push(t);}
                while (!q.empty()) q.pop();
                while (!q1.empty()) {int t = q1.front(); q1.pop(); q.push(t);}
            }
            q.push(a[j]);
        }
        while (!q.empty()) {
            int t = q.front();
            q.pop();
            l.push_back(t);
        }
        for (auto i : l) b[i]++;
        l.clear();
    }
    for (int i = 1; i <= m; i++) cout << b[i] << ' ';
    fclose(stdin);
    fclose(stdout);
    return 0;
}
/**
4 3
1 2 1 3

10 3
3 1 2 1 3 2 3 1 2 1
*/
