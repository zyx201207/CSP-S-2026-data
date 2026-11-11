#include<bits/stdc++.h>

using namespace std;
using ll = long long;

const int N = 5e5 + 5;
int a[N];
int n, m;
int nxt[N];
int ans[N];
int cnt[N];

int main() {
	freopen("card.in", "r", stdin);
    freopen("card.out", "w", stdout);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) nxt[i] = i;
    int j = 2;
    for (int i = 1; i <= n; i++) {
//        cout << "423402: " << nxt[2] << endl;
        while(j <= n && a[i] != a[j]) {
  //          cout << j << " " << a[j] << " " << cnt[a[j]] << endl;
            if (cnt[a[j]]) {
                nxt[cnt[a[j]]] = j;
    //            cout << "ture: " << j << " " << a[j] << " " << cnt[a[j]] << " " << nxt[cnt[a[j]]] << endl;
                cnt[a[j]] = 0;
            }
            cnt[a[j]] = j;
            j++;
        }
        if (j <= n) {
      //          cout << "false: " << j << " " << a[j] << " " << cnt[a[j]] << " " << nxt[cnt[a[j]]] << endl;
            nxt[cnt[a[j]]] = j, cnt[a[j]] = 0;
        }
    }
    //cout << "2: " << nxt[2];
    //for (int i = 1; i <= n; i++) cout << nxt[i] << " ";
    //cout << endl;
    for (int i = 1; i <= n; i++) {
        int j = i;
        while (j <= n) {
            if (j == nxt[j]) ans[a[j]]++, j++;
            else j = nxt[j];
        }
    }
    for (int i = 1; i <= m; i++) cout << ans[i] << " ";
    return 0;
}