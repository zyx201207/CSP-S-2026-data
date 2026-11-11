#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>
#include <queue>
using namespace std;

int c, n, m, d, q;
const int MAXM = 5e5 + 5;
const int MAXN = 505;
int cnt[MAXM], a[MAXN][MAXM];
int t[MAXN][MAXM], w[MAXN];

vector<int> rea[MAXN];

int cg[MAXN][MAXN];
long long stest[MAXN][MAXN];
vector<int> sta[MAXM];



// first: line  second: station

struct node{
    int pos;
    long long dis;
    bool operator>(const node &other) const{
        return dis > other.dis;
    }
};

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    cin >> c >> n >> m >> d >> q;
    for(int i = 1; i <= m; i++)
        cin>>w[i];
    for(int i = 1; i <= n; i++){
        cin>>cnt[i];
        for(int j = 1; j <= cnt[i]; j++){
            cin>>a[i][j];
            cin>>t[i][a[i][j]];
            sta[a[i][j]].push_back(i);
        }
    }

    for(int i = 1; i <= m; i++){
        if(sta[i].size() == 1)
            continue;
        for(auto j : sta[i]){
            for(auto k : sta[i]){
                if(j == k)
                    continue;
                cg[j][k] = ((!cg[j][k])? (t[j][i] + t[k][i]) : min(cg[j][k], t[j][i] + t[k][i]));
            }
        }
    }

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            if(i == j){
                stest[i][j] = 0;
            }
            else if(!cg[i][j]){
                stest[i][j] = 1e18;
            }
            else{
                stest[i][j] = cg[i][j];
            }
        }
    }

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            for(int k = 1; k <= n; k++){
                if(stest[j][i] != 1e18 && stest[i][k] != 1e18){
                    stest[j][k] = min(stest[j][i] + stest[i][k], stest[j][k]);
                }
            }
        }
    }
    
    for(int i = 1; i <= q; i++){
        int x, y;
        cin>>x>>y;
        long long ans = 1e18;
        for(auto j : sta[x]){
            for(auto k : sta[y]){
                ans = min(ans, 0ll + t[j][x] + t[k][y] + stest[j][k]);
            }
        }
        ans += w[x] + w[y];
        cout<<ans<<'\n';
    }
    return 0;
}