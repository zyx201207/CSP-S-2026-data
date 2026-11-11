#include <iostream>
#include <vector>
#define LL long long
using namespace std;
struct dat  {
    int cnt;
    char c;
};
vector<dat> va = vector<dat>();
vector<dat> vb = vector<dat>();
vector<dat> vc = vector<dat>();
int main() {
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    int n, t;
    char c;
    LL len = 0, mid, tll = 0;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> t >> c;
        va.push_back({t, c});
        len += t;
    }
    bool is_odd = len % 2;
    mid = len / 2 + is_odd;

    bool flag = 0;
    for (dat i : va) {
        tll += i.cnt;
        if (flag) {
            vc.insert(vc.begin(), i);
        } else {
            if (tll > mid) {
                vb.push_back({(int) (mid - tll + i.cnt), i.c});
                vc.push_back({(int) (tll - mid + is_odd), i.c});
                flag = 1;
            } else if (tll == mid) {
                vb.push_back(i);
                flag = 1;
            } else vb.push_back(i);
        }
    }

    LL ans = 0;
    tll = 0;
    int vi = 0;
    int vii = -1;
    for (dat i : vb) {
        int j = tll;
        tll += i.cnt;
        while (j < tll && vi < vc.size()) {
            if (vii != -1) {
                if (vc.at(vi).c != i.c) {
                    ans += vc.at(vi).cnt - vii;
                }
                vii = -1;
                vi++;
                continue;
            }
            j += vc.at(vi).cnt;
            if (j > tll) {
                vii = j - tll;
                if (vc.at(vi).c != i.c) {
                    ans += vii;
                }
                continue;
            }
            if (vc.at(vi).c != i.c) {
                ans += vc.at(vi).cnt;
            }
            vii = -1;
            vi++;
        }
    }
    cout << ans;

    return 0;
}
