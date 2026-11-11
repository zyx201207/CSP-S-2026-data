#include <iostream>
// #include <stdlib>
using namespace std;

#ifdef DEBUG
#define dbg(x) cout << "\033[33m" x << "\033[0m"
#else
#define dbg(x)
#endif

int n, m;
long long a[500005];
// long long kth[500005];
// int amount[500005], last = 0;

// int func(const void *a, const void *b) { return *(long long*)a < *(long long*)b ? 1 : -1; }
void sort(long long a[], int l, int r) {
    if(l+1 >= r) { return; }
    int m = (l+r)>>1;
    sort(a, l, m);
    sort(a, m, r);
    int i = l, j = m;
    int *b = new int[r-l], pos=0;
    while(i<m && j<r) {
        if(a[i] > a[j]) {
            b[pos] = a[j];
            j++;
        } else {
            b[pos] = a[i];
            i++;
        }
        pos++;
    }
    if(i < m) {
        while(pos < r-l) {
            b[pos] = a[i];
            i++; pos++;
        }
    }
    if(j < r) {
        while(pos < r-l) {
            b[pos] = a[j];
            j++; pos++;
        }
    }
    // dbg( << "[" << l << ", " << r << "), m=" << m << "    b: ");
    for(int i=0; i<r-l; i++) {
        // dbg( << )
        a[l+i] = b[i];
        // dbg( << b[i] << " ");
    }
    // for(int i=r-l; i<n; i++) dbg( << "  ");
    // dbg( << "    new-a: ");
    // for(i=0; i<n; i++) { dbg( << a[i] << "  "); } dbg( << "\n");
    delete b;
}

int main() {
    #ifndef DEBUG
        if(
            nullptr == freopen("crystal.in" , "r", stdin ) ||
            nullptr == freopen("crystal.out", "w", stdout)
        ) { return 1; }
        cin.tie(nullptr);
        cout.tie(nullptr);
    #endif

    cin >> n >> m;
    for(int i=0; i<n; i++) {
        cin >> a[i];
    }
    // qsort(a, 0, n, func);
    // for(int i=0; i<n; i++) { dbg( << a[i] << "    "); } dbg( << "\n");
    sort(a, 0, n);
    for(int i=0; i<n; i++) { dbg( << a[i] << "    "); } dbg( << "\n");

    // kth[0] = a[0]; amount[0] = 1;
    // for(int i=1; i<n; i++) {
    //     if(a[i] == kth[last]) {
    //         amount[last]++;
    //     } else {
    //         last++;
    //         kth[last] = a[i];
    //         amount[last] = 1;
    //     }
    // }
    // for(int i=0; i<=last; i++) { dbg( << kth[i] << " * " << amount[i] << "\n"); }

    // int l = n, r = n, cost = 0, ans = 0;
    // (l, r] 都合并需要 cost 次操作
    // while(0 <= l) {
    //     int want = a[r];
    //     int need = want - a[l];
    //     dbg( << "(" << l << ", " << r << "]    want " << want << "    need " << need << "    cost " << cost << " yet    ");
    //     if(need + cost > m) {
    //         dbg( << "failed\n");
    //         r = r-1;
    //         cost = 0;
    //     } else {
    //         dbg( << "added\n");
    //         l--;
    //         cost += need;
    //         if(ans < r-l) {
    //             ans = r-l;
    //         }
    //     }
    // }
    // cout << ans;

    int ans=0;
    // (l, r] 都合并需要 cost 次操作
    for(int l=n-1, r=n-1, cost=0; r>=0; r--) {
        int want = a[r];
        dbg( << "r = " << r << "    l = " << l << "    want " << want << "    ");
        while(cost < m && l>=0) {
            int need = want - a[l];
            if(need + cost <= m) {
                dbg( << "buy a[" << l << "] -" << need << "    ");
                l--;
                cost += need;
            } else break;
        }
        dbg( << l << "    ");
        dbg( << "\n");
        if(r-l > ans) ans = r-l;
        if(l<0) break;
        cost -= (r-l)*(a[r]-a[r-1]);
    }
    cout << ans;

    #ifndef DEBUG
        cout << flush;
        fclose(stdin);
        fclose(stdout);
    #endif
    return 0;
}