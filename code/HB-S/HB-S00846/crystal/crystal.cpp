#include <bits/stdc++.h>

using namespace std;

const int M = 5e5 + 10;
int m, n, a[M], total, num, u;

int main()
{
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    cin >> m >> n;
    for(int i = 1; i <= m; i++) cin >> a[i];
    for(int i = 1; i <= m; i++){
        num = 0;
        for(int j = 0; j < n; j++){
            a[j] -= a[i];
            if(m + a[j] >= 0 && i != j){
                num ++;
                m += a[j];
            }
            else total = max(num, total);
        }
    }
    cout << total;
    return 0;
}
