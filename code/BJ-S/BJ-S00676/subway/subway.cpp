#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MAXN = 505;
const int MAXM = 5e5 + 5;
int n,m,q;
int w[MAXM];
vector<pair<int,int> > subs[MAXM];
ll d[MAXN][MAXN];

inline void chkmin(ll &x,ll y){if (y < x)x = y;}

int main(){
    #ifndef kevin
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    #endif
    scanf("%*d%d%d%*d%d",&n,&m,&q);
    for (int i = 1;i <= m;i ++)scanf("%d",w + i);
    for (int i = 1;i <= n;i ++){
        int k;
        scanf("%d",&k);
        while (k --){
            int a,t;
            scanf("%d%d",&a,&t);
            subs[a].emplace_back(i,t);
        }
    }
    memset(d,0x3f,sizeof(d));
    for (int i = 1;i <= n;i ++)d[i][i] = 0;
    for (int i = 1;i <= m;i ++){
        for (auto j : subs[i])
            for (auto k : subs[i]){
                if (j.first == k.first)continue;
                chkmin(d[j.first][k.first],j.second + k.second);
            }
    }
    for (int k = 1;k <= n;k ++)
        for (int i = 1;i <= n;i ++)
            for (int j = 1;j <= n;j ++)
                chkmin(d[i][j],d[i][k] + d[k][j]);
    while (q --){
        int x,y;
        scanf("%d%d",&x,&y);
        ll ans = 0x3f3f3f3f3f3f3f3f;
        for (auto i : subs[x])
            for (auto j : subs[y])
                chkmin(ans,i.second + j.second + d[i.first][j.first]);
        printf("%lld\n",ans + w[x] + w[y]);
    }
    return 0;
}