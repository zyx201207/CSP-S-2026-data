#include<bits/stdc++.h>
using namespace std;

const int N = 500 + 9;
const int M = 1e3 + 9;
const int Q = 1e5 + 9;
int c,n,m,d,q,w[M],k[N],t[N][M];
vector<int>a[N];

void dfs(int u,int tim,int en,int la){
    if(u==en){
        tim+=w[u];
        cout<<tim<<endl;
        return;
    }
    for(int i=0;i<a[u].size();++i){
        if(a[u][i]==la){
            continue;
        }
        dfs(a[u][i],tim+t[u][a[u][i]],en,u);
    }
}

int main(){

    freopen("subway1.in","r",stdin);
    freopen("subway.out","w",stdout);

    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;++i){
        cin>>w[i];
    }
    for(int i=1;i<=n;++i){
        cin>>k[i];
        for(int j=1;j<=2*k[i];++j){
            int w;
            cin>>w>>t[i][w];
            a[i].push_back(w);
            a[w].push_back(i);
        }
    }

    for(int i=1;i<=q;++i){
        int x,y;
        cin>>x>>y;
        dfs(x,w[x]+t[x][x],y,0);
    }

    return 0;
}
