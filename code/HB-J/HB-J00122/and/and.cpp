#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;
int n , m , ans;
int a[N];
bool book[N];
set < int > bad;

int main () {
    freopen("and.in" , "r" , stdin);
    freopen("and.out" , "w" , stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    cin >> n >> m;
    for (int i = 1; i <= n; i ++)
        cin >> a[i];
    for (int j = 31; j >= 0; j --) {
        int cnt1 = 0;
        for (int i = 1; i <= n; i ++)
            if (a[i] & (1 << j) && bad.find(i) == bad.end())
                cnt1 ++;
        if (cnt1 >= m) {
            ans |= (1 << j);
            for (int i = 1; i <= n; i ++)
                if (!(a[i] & (1 << j)))
                    bad.insert(i);
        }
    }
    cout << ans;
    return 0;
}

/*

3 2
19 12 3

*/
