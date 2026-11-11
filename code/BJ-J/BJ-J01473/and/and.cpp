#include<bits/stdc++.h>
using namespace std;

int n,m,a[2005],ans = 0;

void dfs(int now,int num[2005]) {
    if (now == m + 1) {
        int tot = a[num[1]];
        for (int i = 2; i <= m; i++) tot &= a[num[i]];
        ans = max(tot,ans);
        return ;
    }
    for (int i = num[now - 1] + 1; i <= n - m + now; i++) {
        num[now] = i;
        dfs(now + 1,num);
    }
    return ;
}

bool cmp(int u,int v) {
    return u > v;
}

int main() {
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin >> n >> m;
    bool flag = true;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        if (a[i] >= 4) flag = false;
    }
    if (n == 1) {
        cout << 0;
        return 0;
    }
    if (m == 1) {
        cout << 0;
        return 0;
    }
    if (n <= 2004 || m == n - 1) {
        int num[2005] = {0};
        dfs(1,num);
        cout << ans;
        return 0;
    }
    else {
        if (flag == true) {
            bool flag1 = false,flag2 = false,flag3 = false;
            for (int i = 1; i <= n; i++) {
                if (a[i] == 1) flag1 = true;
                else if (a[i] == 2) flag2 = true;
                else if (a[i] == 3) flag3 = true;
            }
            if (flag1 == true && flag2 == true && flag3 == true)
                cout << 3;
            else if (flag1 == false && flag2 == true && flag3 == true)
                cout << 2;
            else if (flag1 == true && flag2 == false && flag3 == true)
                cout << 1;
            else cout << 0;
            return 0;
        }
        sort(a + 1,a + n + 1,cmp);
        if (n == 1) {
            cout << 0;
            return 0;
        }
        ans = a[1];
        for (int i = 2; i <= n; i++)
            ans = ans & a[i];
        cout << ans;
    }
    return 0;
}
