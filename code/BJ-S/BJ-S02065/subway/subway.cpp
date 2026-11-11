#include<bits/stdc++.h>
using namespace std;

int c, n, m, d, q;
int w[500010];
struct subway{
    bool flag;
    int t;
}line[505][500005];

int dfs(int z, int h, int time){
    if(z == h){
        return time;
    }

    for(int i=1; i<=n; i++){
        if(line[i][z].flag == true){
            time += line[i][z].t;
            for(int j=1; j<=m; j++){
                if(line[i][j].flag == true){
                    dfs(j, h, time);
                }
            }
        }
    }
}

int main(){
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> c >> n >> m >> d >> q;

    for(int i=1; i<=m; i++){
        cin >> w[i];
    }
    for(int i=1; i<=n; i++){
        int k = 0;
        cin >> k;
        for(int j=1; j<=k; j++){
            int x;
            cin >> x;
            line[i][x].flag = true;
            cin >> line[i][x].t;
        }
    }

    while(q--){
        int z, h;
        cin >> z >> h;
        cout << dfs(z, h, w[z]+w[h]) << endl;
    }
    return 0;
}
