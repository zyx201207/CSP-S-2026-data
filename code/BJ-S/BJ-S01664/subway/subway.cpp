#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 5e5+5,M = 505;
int c,n,m,d,q;
int w[N];
vector<pair<int,int> >hav[N];
int dis[M][M];
signed main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin >> c >> n >> m >> d >> q;
    for(int i = 1;i <= m;i++){
        cin >> w[i];
    }
    memset(dis,0x3f,sizeof(dis));
    for(int i = 1;i <= n;i++){
        dis[i][i] = 0;
        int k;
        cin >> k;
        for(int j = 1;j <= k;j++){
            int x,t;
            cin >> x >> t;
            for(auto y:hav[x]){
                dis[i][y.first] = min(dis[i][y.first],t+y.second);
                dis[y.first][i] = dis[i][y.first];
            }
            hav[x].push_back({i,t});
        }
    }
    for(int i = 1;i <= n;i++){
        for(int j = 1;j <= n;j++){
            for(int k = 1;k <= n;k++){
                dis[j][k] = min(dis[j][k],dis[j][i]+dis[i][k]);
            }
        }
    }
    while(q--){
        int x,y;
        int ans = 1e18;
        cin >> x >> y;
        for(auto i:hav[x]){
            for(auto j:hav[y]){
                ans = min(ans,dis[i.first][j.first]+i.second+j.second);
            }
        }
        cout << ans+w[x]+w[y] << '\n';
    }
}
/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2
*/
