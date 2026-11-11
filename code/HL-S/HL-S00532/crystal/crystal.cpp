#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
using namespace std;

#define loop(n) for (int i=0; i<n; ++i)

int cmp (const void* a, const void* b, void* arg) {
    return (*(int*)b)-(*(int*)a);
}

int main(int argc, char **argv) {
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    vector<int> hi;
    int n, m;
    cin >> n >> m;
    loop(n) {
        int a;
        cin >> a;
        hi.push_back(a);
    }
    qsort_r(hi.data(), hi.size(), sizeof(int), cmp, NULL);
    loop(n -1) {
        hi[i] -= hi[i+1];
    }
    int mx;
    loop(n-1) {
        int tot=1, r=m, ph=0;
        for (int j = i+1; j<n; ++j) {
            ph += hi[j-1];
            r -= ph;
            if (r < 0) {
                break;
            }
            tot++;
        }
        mx = max(mx, tot);
    }
    cout << mx << '\n';
    return 0;
}
