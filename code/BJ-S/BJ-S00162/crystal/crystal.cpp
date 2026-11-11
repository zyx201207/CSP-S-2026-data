#include <iostream>
#include <algorithm>
using namespace std;

const int N = 5e5 + 5;
long long a[N];

int main() {
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);

    int n;
    long long m;
    cin>>n>>m;
    for (int i=0; i<n; i++) cin>>a[i];
    sort(a, a+n);
    for (int i=0; i<n-1; i++) a[i] = a[i+1] - a[i];

    int maxn = 0;
    for (int i=0; i<=n; i++) {
        int cnt = 1;
        long long x = cnt * a[i];
        for (int j=i+1; m>x && j<n-1; j++) cnt++, x += cnt * a[j];
        maxn = max(cnt, maxn);
    }
    cout<<maxn+1<<endl;
    return 0;
}

//   g++ BJ-S00162/crystal/crystal.cpp -O2
