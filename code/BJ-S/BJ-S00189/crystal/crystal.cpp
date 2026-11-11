#define NDEBUG

#include <algorithm>
#include <fstream>
#include <iostream>
#include <vector>

using namespace std;

using LL = long long;
using ULL = unsigned long long;

bool ok(const vector<LL>& a, ULL m, size_t len) {
    ULL sum=0;
    for (size_t i=0; i<a.size(); ++i){
        if (i<len) {
            if (!i) {
                continue;
            }
            sum += ULL(i) * (a[i] - a[i-1]);
            continue;
        }
        if (sum <= m) {
            return 1;
        }
        sum += ULL(len-1) * (a[i]-a[i-1]) - a[i-1] + a[i-len];
    }
    return sum <= m;
}

size_t solve(const vector<LL>& a, ULL m) {
    size_t res=0;
    for (size_t stp=1U<<20; stp; stp>>=1){
        if (ok(a, m, res+stp)) {
            res += stp;
        }
    }
    return res;
}

int main() {
    #ifdef NDEBUG
        ios::sync_with_stdio(0);
    #endif
    ifstream fin("crystal.in");
    ofstream fout("crystal.out");
    size_t n; ULL m; fin >> n >> m;
    vector<LL> a(n);
    for (auto& i : a){
        fin >> i;
    }
    sort(a.begin(), a.end());
    fout << solve(a, m) << "\n";
    return 0;
}
