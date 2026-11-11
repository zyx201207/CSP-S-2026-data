#include <bits/stdc++.h>
using namespace std;

// #define local
#define int long long
/*
void solve() {
    int n; scanf("%lld", &n);
    vector<int> a(n + 1), sa(n + 1, 0);
    vector<char> b(n + 1);
     // unordered_map<int, int> rnk;

    int tot = 0;
    for(int i = 1; i <= n; i++) {
        scanf("%lld %1c", &a[i], &b[i]);
        tot += a[i];

        sa[i + 1] = sa[i] + a[i];
        // rnk[sa[i]] = i;
        // cout << sa[i] << ' ';
    }

    for(int i = 1; i <= n; i++) sa[i]++;

    int mid = (tot >> 1) + (tot & 1);
    // cout << mid << endl;
    // int pmid = lower_bound(sa.begin(), sa.end(), mid + 1) - sa.begin();
    // if(sa[pmid] > mid + 1) pmid--;

    // cout << pmid << endl;

    for(int i = 1; i <= n; i++) {
        int opp =
    }
}*/

void solve() {
    int n; scanf("%lld", &n);
    vector<int> a(n + 1);
    vector<char> b(n + 1);
    vector<int> sti(n + 2, 0), ste(n + 1, 0);
    int tot = 0;
    for(int i = 1; i <= n; i++) {
        scanf("%lld %1c", &a[i], &b[i]);
        sti[i + 1] = sti[i] + a[i];
        ste[i] = ste[i - 1] + a[i];
        tot += a[i];
    }

    for(int i = 1; i <= n; i++) sti[i]++;
    // for(int i = 1; i <= n; i++) cout << sti[i] << ' '; cout << endl;
    // for(int i = 1; i <= n; i++) cout << ste[i] << ' '; cout << endl;
    vector<int> ranges(n + 1);
    for(int i = 1; i <= n; i++) {
        if(ste[i] <= tot && ste[i] > 0)ranges.push_back(ste[i]);

        int opp = tot - sti[i] + 1;
        if(opp <= tot && opp > 0) ranges.push_back(opp);
    }

    sort(ranges.begin(), ranges.end());
    ranges.push_back(tot);
    ranges.erase(unique(ranges.begin(), ranges.end()), ranges.end());

    int ans = 0;
    int pl = 0, pr = 0;
    int mid = (tot >> 1) + (tot & 1);
    for(int i = 1; i < ranges.size(); i++) {
        pl = pr + 1;
        pr = ranges[i];

        if(pr >= mid + (tot % 2 == 0)) break;

        int pca = lower_bound(ste.begin() + 1, ste.end(), pl) - ste.begin();
        // if(ste[pca] > pl) pca--;
        char ca = b[pca];

        int opp = tot   - pr + 1;
        int pcb = lower_bound(ste.begin() + 1, ste.end(), opp) - ste.begin();
        // if(ste[pcb] > opp) pcb--;
        char cb = b[pcb];
        // cout << pl << ' ' << opp << ' ' << pca << ' ' << pcb << endl;

        ans += (ca != cb) * (pr - pl + 1);
    }

    printf("%lld\n", ans);
}

#undef int

int main(
    #ifdef local
	int argc,
	char* argv[]
    #endif
) {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	solve();
}
