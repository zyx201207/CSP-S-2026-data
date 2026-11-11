#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'

struct Station{
    int to,len;
};
vector<vector<Station>> s;

int c,n,m,d,q;
vector<int> w;
vector<vector<int>> dis;

void floyd(){
    for(int k = 1;k <= n;k++){
        for(int i = 1;i <= n;i++){
            for(int j = 1;j <= n;j++){
                dis[i][j] = min(dis[i][j],dis[i][k]+dis[k][j]);
            }
        }
    }
}

signed main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> c >> n >> m >> d >> q;
    w.resize(m+1);
    for(int i = 1;i <= m;i++){
        cin >> w[i];
    }

    s.resize(m+1);
    int k;
    for(int i = 1;i <= n;i++){
        cin >> k;
        int a,t;
        for(int j = 1;j <= k;j++){
            cin >> a >> t;
            s[a].push_back({i,t});
        }
    }

    dis.resize(n+1,vector<int>(n+1,1e18));
    for(int i = 1;i <= m;i++){
        for(int j = 0;j < s[i].size();j++){
            for(int k = 0;k < s[i].size();k++){
                dis[s[i][j].to][s[i][k].to] =
                dis[s[i][k].to][s[i][j].to] = s[i][j].len+s[i][k].len;
            }
        }
    }

    for(int i = 1;i <= n;i++){
        dis[i][i] = 0;
    }

    floyd();

    int x,y;
    while(q--){
        cin >> x >>y;

        int ans = 1e18;
        for(auto a : s[x]){
            for(auto b : s[y]){
                ans = min(ans,a.len+dis[a.to][b.to]+b.len);
            }
        }
        ans += w[x]+w[y];

        cout << ans << endl;
    }

    return 0;
}
