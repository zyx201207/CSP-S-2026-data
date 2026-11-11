#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll inf = 0x3f3f3f3f3f3f3f3f;
int c,n,m,D,Q,w[500005];
ll d[505][505],dis[505][505],ans;
vector<pair<int,int> > v[500005];
vector<int> v2[505];
priority_queue<pair<ll,int>,vector<pair<ll,int> >,greater<pair<ll,int> > > q;
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin >> c >> n >> m >> D >> Q;
    for(int i = 1;i <= m;i++) cin >> w[i];
    memset(d,0x3f,sizeof(d));
    memset(dis,0x3f,sizeof(dis));
    for(int i = 1;i <= n;i++){
        int kk,aa,tt;
        cin >> kk;
        for(int j = 1;j <= kk;j++){
            cin >> aa >> tt;
            v[aa].push_back({i,tt});
        }
    }
    for(int i = 1;i <= m;i++)
        for(int j = 1;j < v[i].size();j++){
            int t = v[i][j].first,ww = v[i][j].second;
            for(int k = 0;k < j;k++){
                int t2 = v[i][k].first,ww2 = v[i][k].second;
                d[t][t2] = d[t2][t] = min(d[t][t2],(ll)ww + ww2);
            }
        }
    for(int i = 1;i <= n;i++) for(int j = 1;j <= n;j++) if(d[i][j] != inf) v2[i].push_back(j);//,cerr <<i <<'-' <<j << ' ';
    for(int i = 1;i <= n;i++){
        dis[i][i] = 0;
        q.push({0,i});
        while(!q.empty()){
            pair<ll,int> p = q.top();
            q.pop();
            if(p.first != dis[i][p.second]) continue;
            for(int j:v2[p.second])
                if(dis[i][j] > p.first + d[p.second][j]){
                    dis[i][j] = p.first + d[p.second][j];
                    q.push({dis[i][j],j});
                }
        }
        //for(int j = 1;j <= n;j++) cerr <<i << '*' <<j <<'*' <<dis[i][j] << ' ';
    }
    while(Q--){
        int xx,yy;
        cin >> xx >> yy;
        ll ans = inf;
        for(pair<int,int> i:v[xx])
            for(pair<int,int> j:v[yy])
                ans = min(ans,dis[i.first][j.first] + i.second + j.second);
        ans += w[xx] + w[yy];
        cout << ans << '\n';
    }
    return 0;
}
