#include <bits/stdc++.h>
using namespace std;
#define int long long

const int N = 310;
int c,t,n,d;
int a[N];
int q[N],head = 0,tail = -1;
int bef[N],f[N],g[N],tr[N];
int w[N][N],cnt[N][N];
/*
#define lowbit(x) (x & (-x))
void update(int x,int k){
    for (;x<=n;x+=lowbit(x)){
        tr[x] += k;
    }
}
int query(int x){
    int res = 0;
    for (;x;x-=lowbit(x)){
        res += tr[x];
    }
    return res;
}*/

void dfs(int u,int step,int rt){
    if (step > w[rt][u]){return ;}
    if (step == w[rt][u]) cnt[rt][u]++;
    for (int i=bef[u];i<=u-1;i++){
        dfs(i,step+1,rt);
    }
}


void solve(){
    cin >> n >> d;
    for (int i=1;i<=n;i++){
        cin >> a[i];
    }
    head = 0,tail = -1;
    for (int i=1;i<=n;i++){
        q[++tail] = i;
        while (head <= tail && a[q[head]] < a[i] - d) {
            head ++;
        }
        bef[i] = q[head];
    }

    memset(w,0x3f,sizeof(w));
    memset(cnt,0,sizeof(cnt));
    for (int i=1;i<=n;i++){
        for (int j=i-1;j>=bef[i];j--){
            w[i][j] = 1;
        }
    }

    for (int i=1;i<=n;i++){
        w[i][i] = 0;
        cnt[i][i] = 1;
    }
    for (int k=1;k<n;k++){
        for (int i=1;i<=n;i++){
            for (int j=1;j<=n;j++){
                if (i == j || j == k || i == k) continue;
                if (w[i][j] > w[i][k] + w[k][j]) w[i][j] = w[i][k] + w[k][j];
            }
        }
    }
    for (int i=1;i<=n;i++){
        dfs(i,0,i);
    }
    int ans = 0;
    for (int u=1;u<=n;u++){
        for (int v=1;v<u;v++){
            if (cnt[u][v] == 2) ans ++;
        }
    }
    cout << ans << '\n';
    /*
    for (int i=1;i<=n;i++){
        cout << bef[i] << ' ';
    } cout << '\n';

    for (int i=1;i<=n;i++){
        if (bef[i] == i) g[i] = 1;
        else if (bef[i] == i-1) g[i] = g[i-1] + 1;
        else {
            g[i] = i - bef[i] + 1 + (bef[bef[i]] == bef[bef[i+1]] ? 0 : (g[bef[i]] + 1 - g[bef[i+1]]));
            cout << (g[bef[i]] + 1 - g[bef[i+1]]) << ' ';
        }
    }

    for (int i=1;i<=n;i++){
        cout << g[i] << ' ';
    } cout << '\n';

    for (int i=1;i<=n;i++){
        if (bef[i] == i) f[i] = 0;
        else if (bef[i] == i-1) f[i] = f[i-1];
        else if (bef[i] == i-2) f[i] = g[i-1] - 1;
        else f[i] = bef[bef[i] + 2] - bef[bef[i] + 1];
    }

    int ans = 0;
    for (int i=1;i<=n;i++){
        ans += f[i];
    }
    cout << ans << '\n';
    */


    return ;
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    freopen ("migrate.in","r",stdin);
    freopen ("migrate.out","w",stdout);
    cin >> c >> t;
    while (t--){
        solve();
    }
    return 0;
}
