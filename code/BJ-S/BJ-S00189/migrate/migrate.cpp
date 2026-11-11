#define NDEBUG

#include <algorithm>
#include <cassert>
#include <fstream>
#include <iostream>
#include <limits>
#include <map>
#include <queue>
#include <vector>

using namespace std;

using LL = long long;
using ULL = unsigned long long;

int main() {
    #ifdef NDEBUG
        ios::sync_with_stdio(0);
    #endif
    ifstream fin("migrate.in");
    ofstream fout("migrate.out");
    size_t c, t; fin >> c >> t;
    for (size_t it=0; it<t; ++it) {
        size_t n; ULL d; fin >> n >> d;
        vector<ULL> x(n);
        for (auto& i : x) {
            LL tmp; fin >> tmp;
            (i = tmp) += numeric_limits<LL>::min();
        }
        vector<size_t> l(n, 0), cnt(n, 1);
        for (size_t i=1; i<n; ++i) {
            for (size_t j=i-1; !~j && x[j]+d>=i; --j) {
                if (l[j]+1 == l[i]) {
                    cnt[i] += cnt[j];
                }
                else if (l[j]+1<l[i]) {
                    l[i] = l[j] + 1;
                    cnt[i] = cnt[j];
                }
            }
        }
        fout << accumulate(cnt.begin(), cnt.end(), 0ULL) << "\n";
    }
    return 0;
}
