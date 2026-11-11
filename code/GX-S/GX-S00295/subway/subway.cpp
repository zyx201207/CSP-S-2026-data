#include<bits/stdc++.h>
using namespace std;
int w[500005];
// vector<int> G[505];
int t[505][505]; // time[point][rail] to point->rail.
long long G[505][505]; // G[i] = rail i linked rails then use weight.
vector<int> G_[505]; // G[i] = rail i linked points(sorted)
//vector<int> G_2[505]; // G[i] = rail i linked points(no sort)
int a_is[505][500005];
vector<int> railfrom[500005];
int c,n,m,d,q; 
// 0<=c<=25, 1<=n<=500, 1<=m<=5*10^5, 1<=d<=20, 1<=q<=10^5

#define INF 0x3f3f3f3f3f3f3f3f

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    cin >> c >> n >> m >> d >> q;
    for(int i = 1; i <= m; i++) cin >> w[i];
    for(int i = 1; i <= n; i++){
        // i: rail
        int k;
        cin >> k;
        G_[i].reserve(k);
        for(int j = 1; j <= k; j++){
            int _a, _t;
            cin >> _a >> _t;
            G_[i].push_back(_a);
            //G_2[i].push_back(_a);
            if(railfrom[_a].size() == 0 
            || railfrom[_a][railfrom[_a].size()-1] == i){
                railfrom[_a].push_back(i);
            }
            a_is[i][_a] = j;
            t[i][j] = _t;
        }
    }
    for(int i = 1; i <= n; i++) sort(G_[i].begin(), G_[i].end());
    // tiqu G
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            G[i][j] = INF;
        }
    }
    for(int i = 1; i <= n; i++) G[i][i] = 0;

    for(int i = 1; i < n; i++){
        for(int j = i+1; j <= n; j++){
            //cout << "---\n";
            //cout << "i: " << i << " j: " << j << endl;
            auto &Gi = G_[i];
            auto &Gj = G_[j];
            /*
            cout << "Gi: ";
            for(int u:Gi){
                cout << u << ' ';
            }
            cout << endl;
            cout << "Gj: ";
            for(int u:Gj){
                cout << u << ' ';
            }
            cout << endl;
            */
            int ii=0, jj=0;
            while(ii<Gi.size()&&jj<Gj.size()){
                if(Gi[ii] == Gj[jj]){
                    //cout << i << " " << j << " Has a same point: " << Gi[ii] << endl;
                    G[i][j] = t[i][ii+1] + t[j][jj+1];
                    //cout << "add edge " << i << " -> " << j << ", w=" << t[i][ii+1] + t[j][jj+1] << endl;
                    G[j][i] = t[j][jj+1] + t[i][ii+1];
                    //cout << "add edge " << j << " -> " << i << ", w=" << t[j][jj+1] + t[i][ii+1] << endl;
                    //cout << "t[" << i << "][" << ii+1 << "] = " << t[i][ii+1] << endl;
                    //cout << "t[" << j << "][" << jj+1 << "] = " << t[j][jj+1] << endl;
                    ii++, jj++;
                }
                else if(Gi[ii] < Gj[jj]){ ii++;}
                else if(Gi[ii] > Gj[jj]){ jj++;}
            }
        }
    }
    // Floyd!
    for(int k = 1; k <= n; k++){
        for(int u = 1; u <= n; u++){
            for(int v = 1; v <= n; v++){
                G[u][v] = min(G[u][v], G[u][k] + G[k][v]);
            }
        }
    }
    while(q--){
        int x,y;
        cin >> x >> y;
        // what rails of x and y?
        long long dist = -1;
        for(int rx: railfrom[x]){
            for(int ry : railfrom[y]){
                /*
                cout << "t[" << rx << "][" << a_is[rx][x] << "]"
                << " + [" << rx << "," << ry << "]"
                << " + t[" << ry << "][" << a_is[ry][y] << "]"
                << endl;
                */
                dist = max(dist, t[rx][a_is[rx][x]] + G[rx][ry] + t[ry][a_is[ry][y]]);
            }
        }
        cout << w[x] + dist + w[y] << endl;
    }
    return 0;
}