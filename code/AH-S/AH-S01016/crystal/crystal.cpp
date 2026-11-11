#include <bits/stdc++.h>

using namespace std;
const int MAXN = 5e5 + 5;
long long n, m;
long long a[MAXN];
unsigned long long b[MAXN];
unsigned long long get_cha_sum(int l, int r) {
    //a[l]~a[r] suo you bian wei a[r + 1] suo xu ci shu
    return a[r + 1] * (r - l + 1) - (b[r] - b[l - 1]);
}
template<class F>
int my_bs(int left, int right, F check) {
    int mid = 0;
    while (abs(left - right) > 1) {
        mid = (left + right) >> 1;
        //cerr << "#my_bs: mid = " << mid << ", check(mid) = " << check(mid) << '\n';
        if (check(mid)) left = mid;
        else right = mid;
    }
    return left;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    cin >> n >> m;
    for (int i = 1; i <= n; i ++) {
        cin >> a[i];
    }
    sort(a + 1, a + 1 + n);
    for (int i = 1; i <= n; i ++) b[i] = a[i];
    for (int i = 2; i <= n; i ++) {
        b[i] += b[i - 1];
    }
    //cerr << "get_cha_sum(1, 2): " << get_cha_sum(1, 2) << '\n';
    int ans = -1;
    int j = 0;
    for (int i = 2; i <= n; i ++) {
        auto my_check = [&](int mid) {
            //cerr << "#For mid = " << mid << ", ";
            //cerr << ((get_cha_sum(mid, i - 1) > m) ? "Yes, " : "No, ");
            //cerr << "get_cha_sum(mid, i - 1) = " << get_cha_sum(mid, i - 1) << '\n';
            return get_cha_sum(mid, i - 1) > m;
        };
        j = my_bs(1, i - 1, my_check);
        //cerr << "#final my_bs: " << j << '\n';
        //j = 1;
        //unsigned long long tmp = 0;
        //for (; j <= i; j ++) {
            //cerr << j << '\n';
            //tmp = get_cha_sum(j, i - 1);
            //if (tmp > m) {
                //j --;
                //break;
            //}
        //}
        //if (j == i + 1) j = 1;
        //if (j <= 0) j = 1;
        if (get_cha_sum(j, i - 1) > m) j ++;
        int now_len = i - j + 1;
        //cerr << "#i: " << i << ", j: " << j;
        //if (j > 0 && j < i) {
        ans = max(now_len, ans);
        //}
        //cerr << ", ans: " << ans << '\n';
    }
    cout << ans << '\n';
    return 0;
}
/*
5 6
1 100 101 102 103

4


99 1   1   1   0


5 5
1 2 4 8 9

3


1 2 4 1 0
*/
/*
gen1 cha1 you3 guan1 xi4
*/
