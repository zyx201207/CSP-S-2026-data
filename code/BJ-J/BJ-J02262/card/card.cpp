#include<bits/stdc++.h>

using namespace std;

const int N = 5e5 + 10, M = 3e5 + 10;

int n, m;
int a[N], ans[M];
vector<int> v[M];

int bsearch(vector<int> p, int x) {
    int res = -1;
    if (x == p[p.size() - 1]) {
        return -1;
    }

    int l = 0, r = p.size() - 1;
    while (l <= r) {
        int mid = (l + r) >> 1;
        if (p[mid] == x) {
            res = mid;
            return mid;
        }
        if (p[mid] < x) l = mid + 1;
        else    r = mid - 1;
    }
    return -1;
}

int main() {

    freopen("card.in", "r", stdin);
    freopen("card.out", "w", stdout);
    scanf("%d%d", &n, &m);

    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
        v[a[i]].push_back(i);
    }

    for (int k = 1; k <= n; k++) {
        bool flag[M];
        for (int i = k; i <= n; i++) {
            int t = bsearch(v[a[i]], i);
            if (t == -1) {
                //if (flag[a[i]] == false)
                ans[a[i]]++;
               // flag[a[i]] = true;
                continue;
            }
            i = v[a[i]][t + 1] - 1;
        }

    }

    for (int i = 1; i <= m; i++) {
        printf("%d ", ans[i]);
    }
    return 0;
}
