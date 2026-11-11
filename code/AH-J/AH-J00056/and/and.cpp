#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e5+5;
int n,m;
int a[N];
int b[N];

bool cmp(int x, int y) {
    return x > y;
}

int maxn = 0;

void dfs(int u, int sum, int cnt) {
    if(u==0) {
        if(cnt==m) {
            maxn = max(maxn, sum);
        }
        return ;
    }
    dfs(u-1, sum&a[u], cnt+1);
    dfs(u-1, sum, cnt);
}

signed main() {
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);
    cin >> n >> m;
    for(int i=1; i<=n; i++) {
        cin >> b[i];
        a[i] = b[i];
    }
    if(n<=20) {
        dfs(n,(1<<20)-1,0);
        cout << maxn;
    } else {
        sort(b+1, b+1+n, cmp);
        int sum = b[1];
        for(int i=1; i<=m; i++) {
            sum &= b[i];
        }
        cout << sum;
    }
    fclose(stdin);
    fclose(stdout);
}
/*
4 2
3 15 12 12
*/
