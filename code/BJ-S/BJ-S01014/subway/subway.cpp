#include <bits/stdc++.h>
using namespace std;
const int M = 5e5+10;
vector<pair<int,int> > e[M];
int w[M] = {};
int c,n,m,d,q,k,a[M],t[M],s,ed,dist[M];
void dij(int s) {
    priority_queue<int> q;
    memset(dist,0x3f3f3f,sizeof(dist));
    dist[s] = 0;
    q.push(s);
    while(!q.empty()) {
        int u = q.top();q.pop();
        for(int i = 0;e[u][i].first;i++) {
            int v = e[u][i].first;
            int w = e[u][i].second;
            if(w+dist[u]<dist[v]) {
                dist[v] = w+dist[u];
                q.push(v);
            }
        }
    }
}
int main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    if(c >= 20 && c <= 21) {
        int by1 = 1e9,by2 = 1e9;
        for(int i = 1;i<= m;i++) scanf("%d",&w[i]);
        for(int i = 1;i <= n;i++) {
            scanf("%d",&k);
            for(int j = 1;j <= k;j++) {
                scanf("%d%d",&a[j],&t[j]);
            }
            while(q--) {
                scanf("%d%d",&s,&ed);
                for(int j = 1;j <= k;j++) {
                    if(a[j] == s) by1 = min(by1,t[j]);
                    if(a[j] == ed) by2 = min(by2,t[j]);
                }
                printf("%d\n",by1+by2+w[s]+w[ed]);
            }
        }
        return 0;
    }
    for(int i = 1;i<= m;i++) scanf("%d",&w[i]);
    for(int i = 1;i <= n;i++) {
        scanf("%d",&k);
        for(int j = 1;j <= k;j++) {
            scanf("%d%d",&a[j],&t[j]);
        }
        for(int j = 1;j <= k;j++) {
            if(j < k) {
                e[a[j]+i*m].push_back({a[j+1]+i*m,0});
                e[a[j+1]+i*m].push_back({a[j]+i*m,0});
            }
            e[a[j]+i*m].push_back({a[j],t[j]});
            e[a[j]].push_back({a[j]+i*m,t[j]});
        }
    }
    /*for(int i = 1;i <= 15;i++) {
        e[i].push_back({0,0});
        for(int j = 0;e[i][j].first;j++) {
            cout<<i<<" "<<e[i][j].first<<' '<<e[i][j].second<<endl;
        }
    }*/
    while(q--) {
        scanf("%d%d",&s,&ed);
        dij(s);
        printf("%d\n",dist[ed]+w[s]+w[ed]);
    }
    return 0;
}
