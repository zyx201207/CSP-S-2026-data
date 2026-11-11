#include<bits/stdc++.h>
using namespace std;
const int N = 1e5;
const int M = 500;
int out[N], line[M], zhiy[M], ans[M];
struct b{
    int nxt;
    int v;
};
vector <vector<b>> po;
void xz(int s, int t, int k){
    if(s==t) ans[t] = k;
    for(int i = 0; i<po[s].size(); i++){
        if(k+po[s][i].v<ans[po[s][i].nxt]||ans[po[s][i].nxt]==0){
            ans[po[s][i].nxt] = k+po[s][i].v;
            xz(po[s][i].nxt, t, k+po[s][i].v);
            ans[po[s][i].nxt] = 0;
        }
    }
    return;
}
int main(){
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    int c;
    int n, m, d, q;
    cin >> c >> n >> m >> d >> q;
    for(int i = 1; i<=m; i++) cin >> out[i];
    for(int i = 1; i<=n; i++){
        int nli;
        cin >> nli;
        for(int j = 1; j<=nli; j++){
            int rer, ere;
            cin >> rer;
            cin >> ere;
            for(int k = j-1; k>0; k--){
                po[line[k]].push_back({rer, zhiy[k]+ere});
                po[rer].push_back({line[k], zhiy[k]+ere});
            }
            line[j] = rer;
            zhiy[j] = ere;
        }
    }
    int qd, zd;
    for(int i = 1; i<=q; i++){
        cin >> qd >> zd;
        memset(ans, 0, sizeof(ans));
        xz(qd, zd, 0);
        cout << ans[zd]+out[qd]+out[zd] << endl;
    }
    return 0;
}
