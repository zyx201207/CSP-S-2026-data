#include<bits/stdc++.h>
using namespace std;
long long c,n,m,d,qq;
long long w[500010];
long long hd[510],sz[510];
long long a[500010],t[500010];
long long st[100010],ed[100010];
long long trs[510][510];
long long f[500010];
vector<pair<int,long long> > v[510];
long long dis[510][510];
int vis[510][510];
priority_queue<pair<long long,int>,vector<pair<long long,int> >,greater<pair<long long,int> > > q;
pair<long long,long long> p[500010][25];
long long cntp[500010];
void dj(int s) {
    for (int i=1;i<=n;i++) {
        dis[s][i] = 1e18;
    }
    dis[s][s] = 0ll;
    q.push({0ll,s});
    while (q.size()) {
        int p = q.top().second;
        q.pop();
        if (vis[s][p]) {
            continue;
        }
        vis[s][p] = 1;
        for (int i=0;i<v[p].size();i++) {
            int x = v[p][i].first,ad = v[p][i].second;
            if (dis[s][x] > dis[s][p]+ad) {
                dis[s][x] = dis[s][p]+ad;
                q.push({dis[s][x],x});
            }
        }
    }
}
int main() {
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    scanf("%lld%lld%lld%lld%lld",&c,&n,&m,&d,&qq);
    for (int i=1;i<=m;i++) {
        scanf("%lld",&w[i]);
        f[i] = -1;
    }
    long long cnt = 0;
    for (int i=1;i<=n;i++) {
        scanf("%lld",&sz[i]);
        hd[i] = cnt+1;
        for (int j=1;j<=sz[i];j++) {
            cnt++;
            scanf("%lld%lld",&a[cnt],&t[cnt]);
            cntp[a[cnt]]++;
            p[a[cnt]][cntp[a[cnt]]].first = i;
            p[a[cnt]][cntp[a[cnt]]].second = t[cnt];
        }
    }
    for (int i=1;i<=qq;i++) {
        scanf("%lld%lld",&st[i],&ed[i]);
    }
    for (int i=1;i<=n;i++) {
        for (int j=1;j<=n;j++) {
            trs[i][j] = 1e18;
        }
        for (int j=i+1;j<=n;j++) {
            for (int k=hd[j];k<=hd[j]+sz[j]-1;k++) {
                f[a[k]] = t[k];
            }
            for (int k=hd[i];k<=hd[i]+sz[i]-1;k++) {
                if (f[a[k]] != -1) {
                    trs[i][j] = min(trs[i][j],t[k]+f[a[k]]);
                }
            }
            for (int k=hd[j];k<=hd[j]+sz[j]-1;k++) {
                f[a[k]] = -1;
            }
            if (trs[i][j] != 1e18) {
                v[i].push_back({j,trs[i][j]});
                v[j].push_back({i,trs[i][j]});
            }
        }
    }
    for (int i=1;i<=n;i++) {
        dj(i);
    }
    for (int i=1;i<=qq;i++) {
        long long ans = 1e18;
        for (int j=1;j<=cntp[st[i]];j++) {
            for (int k=1;k<=cntp[ed[i]];k++) {
                ans = min(ans,p[st[i]][j].second+dis[p[st[i]][j].first][p[ed[i]][k].first]+p[ed[i]][k].second);
            }
        }
        ans += w[st[i]]+w[ed[i]];
        printf("%lld\n",ans);
    }
    return 0;
}