# include <bits/stdc++.h>
using namespace std;
# define int long long
const int N = 2e6+5, NN = 5e3+5;;
int c, a[N], b[NN], d[NN], n, D;
vector <int> g[NN];
queue <int> q;

int bfs(int s){
    q.push(s);
    memset(b, 0x3f, sizeof b);
    memset(d, 0, sizeof d);
    b[s] = 0;
    d[s] = 1;
    while (!q.empty()){
        int u = q.front(); q.pop();

        for (int v : g[u]){
            if (b[v] == 0x3f3f3f3f3f3f3f3f){
                b[v] = b[u] + 1;
                q.push(v);
                d[v] += d[u];
            }
            else if (b[v] == b[u] + 1){
                d[v] += d[u];
            }
        }
    }
//    for (int i=1;i<=n;i++){
//        cout << b[i] << " " << d[i] << endl;
//    }
//    cout << endl;
    int cnt = 0;
    for (int i=s+1;i<=n;i++){
        if (d[i] == 2){
            cnt++;
        }
    }
    return cnt;
}

void go(){
    cin >> n >> D;
    for (int i=1;i<=n;i++){
        cin >> a[i];
        g[i].clear();
    }
    for (int i=1;i<=n;i++){
        for (int j=1;j<=n;j++){
            if (abs(a[i] - a[j]) <= D){
                g[i].push_back(j);
            }
        }
    }
    int tot = 0;
    for (int i=1;i<=n;i++){
//        cout << "this is bfs(" << i << ")\n";
        tot += bfs(i);
    }
    cout << tot << endl;
}

void Main(){
    if (c <= 10){
        go();
        return ;
    }

    cin >> n >> D;
    for (int i=1;i<=n;i++){
        cin >> a[i];
    }
    int t = a[2] - a[1], chu = D / t, ned = ceil(1.0 * (n - 1) / chu);
    if (t == 1){
        cout << 0 << endl;
    }
    else if (t == 2){
        cout << 2 - (n % 2) << endl;
    }
    else{
        cout << 0 << endl;
    }

}

signed main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t;
    cin >> c >> t;
    while (t--){
        Main();
    }
    return 0;
}
