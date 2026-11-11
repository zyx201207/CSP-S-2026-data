#include <bits/stdc++.h>

using namespace std;

const int N = 5e5 + 5;
int n , m , tp;
int a[N] , f[N] , v[N] , book[N] , st[N];

int main () {
    freopen("card.in" , "r" , stdin);
    freopen("card.out" , "w" , stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    cin >> n >> m;
    for (int i = 1; i <= n; i ++)
        cin >> a[i];
    for (int i = 1; i <= n; i ++) {
        tp = 0;
        memset(book , 0 , sizeof book);
        for (int j = i; j <= n; j ++) {
            if (book[a[j]])
                tp = book[a[j]];
            else {
                st[++ tp] = a[j];
                book[a[j]] = tp;
            }
        }
        for (int j = 1; j <= tp; j ++)
            f[st[j]] ++;
    }
    for (int i = 1; i <= m; i ++)
        cout << f[i] << ' ';
    return 0;
}
/*

4 3
1 2 1 3
* 
10 3
3 1 2 1 3 2 3 1 2 1

*/
