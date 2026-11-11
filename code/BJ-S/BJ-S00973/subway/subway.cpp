#include <bits/stdc++.h>
using namespace std;
//test:AC AC WA -- -- -- --
const int N = 5e5+7;
const long long int M = 4e18+19;
int c,n,m,d,q,w[N],b[N],t[N],k[N],x[N],y[N];
vector<pair<int,int>> a[N];

long long int bfs(int x,int y){
    queue<pair<int,long long int>> q;//<index,value>
    long long int st[N];
    q.push({x,0});
    while(!q.empty()){
        int u = q.front().first;
        long long int l = q.front().second;
//        cout << "[bfs]" << u << endl;
        q.pop();
        vector<pair<int,int>> r = a[u];
        while(!r.empty()){
            int v = r.back().first,s = r.back().second;
            r.pop_back();
//            cout << "[bfs]" << v << " " << s << endl;
            if(st[v]==0)st[v] = M;
            if(l+s>=st[v])continue;
            st[v] = l+s;
            q.push({v,l+s});
        }
    }
    return st[y];
}

int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
    for(int i = 1;i<=m;i++){
        scanf("%d",&w[i]);
    }
    for(int i = 1;i<=n;i++){
        scanf("%d",&k[i]);
        for(int j = 1;j<=k[i];j++){
            scanf("%d%d",&b[j],&t[j]);
            for(int l = 1;l<=j;l++){
                a[b[j]].push_back({b[l],t[j]+t[l]});
                a[b[l]].push_back({b[j],t[j]+t[l]});
            }
        }
    }
    for(int i = 1;i<=q;i++){
        int x,y;
        scanf("%d%d",&x,&y);
        printf("%lld\n",bfs(x,y)+w[x]+w[y]);
    }
    return 0;
}