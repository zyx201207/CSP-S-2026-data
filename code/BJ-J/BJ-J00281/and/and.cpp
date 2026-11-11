#include<bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 10;, L = 40;
int n, m, a[maxn];
bool flag[maxn][L], fnd[maxn];
int main()
{
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);
    cin >> n >> m;
    int ans = 0;
    for(int i = 1; i <= n; i ++) {
        cin >> a[i];
        int cnt = 0;
        while(a[i]) 
            flag[i][L-cnt] = a[i] % 2, a[i] /= 2, ++ cnt;
    }
    memset(fnd, true, sizeof(fnd));
    for(int i = 0; i < L; i ++) {
        int cnt = 0;
        for(int j = 1; j <= n; j ++) {
            if(!fnd[j]) 
                continue;
            cnt += flag[j][i];
        }
        ans *= 2;
        if(cnt >= m) {
            ans ++;
            for(int j = 1; j <= n; j ++) 
                if(!flag[j][i]) 
                    fnd[j] = false;
        }
    }
    cout << ans << '\n';
    return 0;
}