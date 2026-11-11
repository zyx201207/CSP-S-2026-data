#include<bits/stdc++.h>
#define int long long
#define f1 first
#define s2 second
using namespace std;
int n,m,d,q;
int wl[500005];
typedef pair<int,int> pii;
vector<pii> sub[505];
int fl[505][505];
int st[500005][3];

void sv1(){
    memset(fl,0x3f,sizeof(fl));
    for(int i=1;i<=n;i++){
        for(int ui=1;ui<sub[i].size();ui++){
            int u=sub[i][ui].f1;
            for(int vi=ui+1;vi<sub[i].size();vi++){
                int v=sub[i][vi].f1;
                fl[u][v] = fl[v][u] = min(fl[v][u],sub[i][ui].s2+sub[i][vi].s2);
            }
        }
    }
    for(int k=1;k<=m;k++){
        for(int u=1;u<=m;u++){
            for(int v=1;v<=m;v++){
                fl[u][v] = min(fl[u][v],fl[u][k]+fl[k][v]);
            }
        }
    }
    while(q--){
        int u,v;
        cin>>u>>v;
        cout<<fl[u][v]+wl[u]+wl[v]<<endl;
    }
}

void sv2(){
    int gg=0;
    for(int i=1;i<=2;i++){
        for(int j=1;j<=sub[i].size();j++){
            st[sub[i][j].f1][i] = sub[i][j].s2;
        }
    }
    for(int i=1;i<=m;i++){
        if(st[i][1]&&st[i][2]){
            if(!gg)
                gg = st[i][1]+st[i][2];
            else if(st[i][1]+st[i][2] < gg){
                gg = st[i][1]+st[i][2];
            }
        }
    }
    while(q--){
        int u,v,ans=0;
        cin>>u>>v;
        if(st[u][1]&&st[v][1]){
            ans = st[u][1]+st[v][1];
        }
        if(st[u][2]&&st[v][2]){
            if(!ans) ans=st[u][2]+st[v][2];
            else ans = max(ans,st[u][2]+st[v][2]);
        }
        if(st[u][1]&&st[v][2]){
            if(!ans) ans=st[u][1]+st[v][2]+gg;
            else ans = max(ans,st[u][1]+st[v][2]+gg);
        }
        if(st[u][2]&&st[v][1]){
            if(!ans) ans=st[u][2]+st[v][1]+gg;
            else ans = max(ans,st[u][2]+st[v][1]+gg);
        }
        cout<<ans<<endl;
    }
}
signed main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    int C;
    int lth,v,w;
    cin>>C>>n>>m>>d>>q;
    for(int i=1;i<=m;i++)
        cin>>wl[i];
    for(int i=1;i<=n;i++){
        cin>>lth;
        sub[i].push_back({lth,0});
        for(int j=1;j<=lth;j++){
            cin>>v>>w;
            sub[i].push_back({v,w});
        }
    }
    if(C<=11) sv1();
    if(C==21 || C==20) sv2();
    return 0;
}
