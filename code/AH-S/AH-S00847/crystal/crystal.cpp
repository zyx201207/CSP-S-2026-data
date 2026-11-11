#include <bits/stdc++.h>
using namespace std;
long long a[500010];
long long maxn;
int main (){
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    int n;
    long long m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    sort (a+1, a+n+1);
    for (int i = 1; i <= n; i++){
        long long x = m, cnt = 0;
        int j = i;
        while (j >= 1 && x >= 0){
            cnt++;
            x -= (a[i]-a[j]);
            j--;
            if (x < 0)
                cnt--;
        }
        maxn = max(maxn, cnt);
    }
    cout << maxn;
    return 0;
}
