#include <bits/stdc++.h>
using namespace std;

int n, m;
int a[200100];
vector<int> cnt(31), zr(31), ans(31);
deque<int> dq;

void myerase() {
    int x = a[dq.front()], t = 0;
    while (x) {
        if (x % 2 == 1)
            cnt[t]--;
        else 
            zr[t]--;
        x /= 2;
        t++;
    }
    dq.pop_front();
}

void myinsert(int x) {
    int t = 0;
    for (int i = 0; i <= 30; i++) {
        if (x % 2 == 1)
            cnt[t]++;
        else
            zr[t]++;
        x /= 2;
        t++;
    }
}

void calc() {
    vector<int> st(31);
    for (int i = 0; i <= 30; i++)
        if (zr[i] != 0)
            st[i] = 0;
        else
            st[i] = 1;
    for (int i = 30; i >= 0; i--)
        if (st[i] > ans[i]) {
            ans = st;
            return;
        } else if (ans[i] > st[i])
            return;
}

long long get() {
    long long tot = 0, bs = 1;
    for (int i = 0; i <= 30; i++)
        tot += bs * ans[i], bs *= 2;
    return tot;
}

int main() {
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
        scanf("%d", &a[i]);
    sort(a + 1, a + n + 1, [&](const int &a, const int &b) {
        return a > b;
    });
    for (int i = 1; i <= n; i++) {
        while (!dq.empty() && dq.front() < i - m + 1)
            myerase();
        myinsert(a[i]);
        dq.push_back(i);
        if ((int)dq.size() == m)
            calc();
    }
    printf("%lld\n", get());
}
