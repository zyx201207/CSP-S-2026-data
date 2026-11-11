#include <iostream>
#include <algorithm>
using namespace std;

const int N = 2e5 + 5;

int n, m;
long long a[N];

long long maxn;

void f(int ind, int cnt, long long val) {
    if (cnt == m - 1) {
        maxn = max(maxn, val);
        return;
    }
    for (int i=ind+1; i<n; i++) f(i, cnt+1, val & a[i]);
}

bool cmp(long long a, long long b) {
    return a > b;
}

int main() {
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);

    cin>>n>>m;
    for (int i=0; i<n; i++) cin>>a[i];
    sort(a, a+n, cmp);
    for (int i=0; i<n; i++) f(0, 0, a[i]);

    cout<<maxn<<endl;
    return 0;
}

//   BJ-J00178/and/and.cpp
