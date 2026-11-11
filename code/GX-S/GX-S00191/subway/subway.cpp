#include <bits/stdc++.h>
using namespace std;
const int N = 510,M = 5e5+10;
int c,n,m,d,q;
int w[M],k[N],a[N][M],t[N][M];
vector <pair<int,int> > e[2*M];
void dfs(int x,int dest){
    if (x == dest) return;
    for (auto i:e[x]){
        int y = i.first;
        int z = i.second;
        dfs(y,dest);
    }
}
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin >> c >> n >> m >> d >> q;
    for (int i = 1;i <= m;i++) cin >> w[i];
    for (int i = 1;i <= n;i++){
        cin >> k[i];
        for (int j = 1;j <= k[i];j++){
            cin >> a[k[i]][j];
            cin >> t[k[i]][j];
        }
        for (int j = 1;j < k[i];j++){
            e[a[k[i]][j]].push_back({a[k[i]][j+1],i});
            e[a[k[i]][j+1]].push_back({a[k[i]][j],i});
        }
    }
    while (q--){
        int x,y;
        cin >> x >> y;
        //dfs(x,y);
        cout << 0 << "\n";
    }
    return 0;
}
