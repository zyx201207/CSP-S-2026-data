#include<bits/stdc++.h>
using namespace std;
#define ll long long

int c,T,n;
ll d,x[5005],ans;

void dfs(ll num[],int now,int len,int l,int r) {
    if (now - 1 == len - 2) {
        bool flag = true;
        num[r] = r;
        for (int i = 2; i <= r; i++) {
            if (x[num[i]] - x[num[i - 1]] > d) flag = false;
        }
        if (flag == true) ans++;
        return ;
    }
    for (int i = num[now - 1] + 1; i <= r - (len - 2 - now); i++) {
        num[now] = i;
        dfs(num,now + 1,len,l,r);
    }
    return ;
}

bool check(int l,int r) {
    ll num = 0;
    int tot = 0,now[5005],lst = l;
    now[0] = l;
    for (int i = l + 1; i <= r; i++) {
        if (x[i] - x[lst] <= d) {
            num += (x[i] - x[i - 1]);
            if (i == r) now[++tot] = i;
        }
        else {
            num = x[i] - x[i - 1];
            now[++tot] = i - 1;
            lst = i - 1;
        }
    }
    tot++;
    ll tmp[5005] = {0,l};
    ans = 0;
    dfs(tmp,2,r - l - 1,l,r);
    if (ans == 2) return true;
    return false;
}

int main() {
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> c >> T;
    while (T--) {
        cin >> n >> d;
        bool flag = false;
        for (int i = 1; i <= n; i++) {
            cin >> x[i];
            if (i != 1) {
                if (x[i] - x[i - 1] > d)
                    flag = true;
            }
        }
        if (flag == true) {
            cout << 0 << endl;
            continue;
        }
        ll ans = 0;
        for (int i = 1; i <= n; i++) {
            for (int j = i + 1; j <= n; j++) {
                if (check(i,j)) {
                    ans++;
                    cout << i <<" " << j << endl;
                }
            }
        }
        cout << ans << endl;
    }
    return 0;
}
