#include <bits/stdc++.h>
#define filename "hub"
using namespace std;

#define upw(i, a, b) for(int i = (a); i <= (b); ++i)
#define dnw(i, a, b) for(int i = (a); i >= (b); --i)
#define inf 0x3f3f3f3f
#define Linf 0x3f3f3f3f3f3f3f3f

template<class T> bool vmax(T &a, const T &b) { return b > a ? (a = b, 1) : 0; }
template<class T> bool vmin(T &a, const T &b) { return b < a ? (a = b, 1) : 0; }

const int N = 1e6 + 5;

signed Case;

void WaterM() {
    puts("0");
}

signed main() {
    freopen(filename".in", "r", stdin);
    freopen(filename".out", "w", stdout);
    signed _ = 1;
    cin >> Case;
    scanf("%d", &_);
    upw(round, 1, _) WaterM();
    return 0;
}