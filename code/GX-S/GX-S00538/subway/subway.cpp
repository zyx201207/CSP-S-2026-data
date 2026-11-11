#include<bits/stdc++.h>
using namespace std;
#define int long long
struct Info {
    long long x,y;
    Info (long long _x,long long _y){
        x = _x,y = _y;
    }
};
vector<Info> e[500010];
int c,n,m,d,t,w[500010],k,Z[500010],O[500010],dist[500010],h[500010];
map<pair<int,int>,int> mp;
set<pair<int,int>> q;
inline void dij(int x,int y){
    q.clear();
    for (int i = 1;i <= m;i++) dist[i] = LONG_LONG_MAX,h[x] = 0;
    dist[x] = 0;
    h[x] = -1;
    for (int i = 1;i <= m;i++) q.insert(make_pair(dist[i],i));
    while (!q.empty()){
        int X = q.begin()->second;
        q.erase(q.begin());
        for (auto Y : e[X]){
            int cnt = 0;
            if (h[X] != Y.x && h[x] != -1){
                cnt = mp[make_pair(h[x],X)];
            }
            h[Y.y] = Y.x;
            if (dist[Y.y] > dist[X] + mp[make_pair(Y.x,X)] + cnt){
                q.erase(make_pair(dist[Y.y],Y.x));
                dist[Y.y] = dist[X] + mp[make_pair(Y.x,X)] + cnt;
                q.insert(make_pair(dist[Y.y],Y.x));
            }
        }
    }
    printf("%lld\n",dist[y] + w[x] + w[y] + mp[make_pair(h[y],y)]);
}
signed main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    scanf("%lld%lld%lld%lld%lld",&c,&n,&m,&d,&t);
    for (int i = 1;i <= m;i++) scanf("%lld",&w[i]);
    for (int i = 1;i <= n;i++){
        scanf("%lld",&k);
        for (int j = 1;j <= k;j++){
            scanf("%lld%lld",&Z[j],&O[j]);
            mp[make_pair(i,Z[j])] = O[j];
        }
        for (int j = 1;j < k;j++){
            e[Z[j]].push_back(Info(i,Z[j + 1]));
            e[Z[j + 1]].push_back(Info(i,Z[j]));
        }
    }
    while (t--){
        int x,y;
        scanf("%lld%lld",&x,&y);
        dij(x,y);
    }
}
