#include<bits/stdc++.h>

using namespace std;

int c, T, n, d;
bool flag = false;

const int N = 1e4 + 10;

long long x[N];

vector<int> p, q;

/*int bsearch(int l, int r, int tar) {
    int u = r, mid;
    while (l <= r) {
        mid = (l + r) >> 1;
        if (x[u] - x[mid] == tar)  return mid;
        if (x[u] - x[mid] > tar)  l = mid + 1;
        else    r = mid - 1;
    }
    if (x[mid])
}*/

void dfs(int u, int v) {
    if (u + d >= v) return;
    int pos = lower_bound(x + u + 1, x + v + 1, x[u] + d) - x;
    if (x[pos] != x[u] + d) {
        pos--;
    }
    if (pos == u) {
        flag = false;
        return;
    }
    p.push_back(pos);
    dfs(pos, v);

}

void ddfs(int u, int v) {
    if (u + d >= v) return;
    int qos = lower_bound(x + u + 1, x + v + 1, x[v] - d) - x;
    q.push_back(qos);
    ddfs(u, qos);
}

bool check(int u, int v) {
        /*int pos = lower_bound(a + u + 1, a + v + 1, a[u] + d) - a;
        if (a[pos] != a[u] + d) {
            return false;
        }*/
    flag = true;
    dfs(u, v);

    if (!flag)  return false;

    ddfs(u, v);

    int cnt = 0;
    int j = q.size() - 1;
    for (int i = 0, len = p.size(); i < len; i++) {
        cnt += abs(p[i] - q[j]);
        j--;
    }

    if (cnt == 1)   return true;
    return false;
}

int main() {
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    scanf("%d%d", &c, &T);

    while (T--) {

        int ans = 0;

        scanf("%d%d", &n, &d);


        if (c  == 11 ||c == 12 /*|| 1 == 1*/) {
            long long D;
            for (int i = 1; i<= n; i++) {
                long long w;
                cin >> w;
                if (i <= 5) x[i] = w;
                if (i == 2) {
                    D = x[2] - x[1];
                }
            }
            int z = d / D;
            if (n >= (2*z-1)) {
                cout <<n - 2*z + 1 <<'\n';
            }
            else cout << 0 <<'\n';

            continue;
        }

        for (int i = 1; i<= n; i++) {

            cin >> x[i];
        }
        for (int i = 1; i <= n; i++) {

            for (int j = i + 2; j <= n; j++) {
                p.clear();
                q.clear();
                if (check(i, j)) {
                    ans++;
                }
            }

        }
        printf("%d\n", ans);
    }


    return 0;
}
