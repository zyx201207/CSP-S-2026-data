#include <bits/stdc++.h>
using namespace std;
const int N = 500010;
vector<int> s2l[N];
int w[N];
int a[505][N], t[N][505];
int dpl2l[505][505];

inline int read(){
    int x=0, f=1;
    char ch = getchar();
    while (!isdigit(ch)){
        if (ch == '-') f = -1;
        ch = getchar();
    }
    while (isdigit(ch)){
        x = x*10 + (ch^48);
        ch = getchar();
    }
    return x*f;
}
int main(){
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    memset(t, 0x3f, sizeof t);
    memset(dpl2l, 0x3f, sizeof dpl2l);

    int c = read(), n = read(), m = read(), d = read(), q = read();
    for (int i = 1; i <= m; i++) w[i] = read();
    if (c == 20 || c == 21){
        for (int i = 1; i <= n; i++){
            int k = read();
            for (int j = 1; j <= k; j++){
                a[i][j] = read();
                t[a[i][j]][i] = read();
                for (int l = 0; l < s2l[a[i][j]].size(); l++){
                    dpl2l[i][s2l[a[i][j]][l]] = min(dpl2l[i][s2l[a[i][j]][l]], t[a[i][j]][s2l[a[i][j]][l]]+t[a[i][j]][i]);
                }
                s2l[a[i][j]].push_back(i);
            }
        }
        for (int i = 1; i <= q; i++){
            int x = read(), y = read();
            int ans = 2147483647;
            for (int j = 0; j < s2l[x].size(); j++){
                for (int k = 0; k < s2l[y].size(); k++){
                    if (s2l[x][j] == s2l[y][k]) ans = min(t[x][s2l[x][j]] + t[y][s2l[y][k]], ans);
                    else ans = min(ans, dpl2l[s2l[y][k]][s2l[x][j]]);
                }
            }
            cout << ans+w[x]+w[y] << "\n";
        }
        return 0;
    }



    for (int i = 1; i <= n; i++){
        int k = read();
        for (int j = 1; j <= k; j++){
            a[i][j] = read();
            t[a[i][j]][i] = read();
            for (int l = 0; l < s2l[a[i][j]].size(); l++){
                if (i < s2l[a[i][j]][l]) dpl2l[i][s2l[a[i][j]][l]] = min(dpl2l[i][s2l[a[i][j]][l]], t[a[i][j]][s2l[a[i][j]][l]]+t[a[i][j]][i]);
                else dpl2l[s2l[a[i][j]][l]][i] = min(dpl2l[s2l[a[i][j]][l]][i], t[a[i][j]][s2l[a[i][j]][l]]+t[a[i][j]][i]);
            }
            s2l[a[i][j]].push_back(i);
        }
    }


    for (int i = 1; i <= n; i++){
        for (int j = i+1; j <= n; j++){
            for (int k = 1; k <= n; k++){
                if (k == i || k == j) continue;
                if (k < i) dpl2l[i][j] = min(dpl2l[i][j], dpl2l[k][i]+dpl2l[k][j]);
                else if (i < k < j) dpl2l[i][j] = min(dpl2l[i][j], dpl2l[i][k]+dpl2l[k][j]);
                else dpl2l[i][j] = min(dpl2l[i][j], dpl2l[i][k]+dpl2l[j][k]);
            }
        }
    }
    for (int i = 1; i <= q; i++){
        int x = read(), y = read();
        int ans = 2147483647;
        for (int j = 0; j < s2l[x].size(); j++){
            for (int k = 0; k < s2l[y].size(); k++){
                if (s2l[x][j] <= s2l[y][k]) ans = min(ans, dpl2l[s2l[x][j]][s2l[y][k]]);
                else ans = min(ans, dpl2l[s2l[y][k]][s2l[x][j]]);
            }
        }
        cout << ans+w[x]+w[y] << "\n";
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
