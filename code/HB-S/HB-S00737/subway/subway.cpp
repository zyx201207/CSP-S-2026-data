#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define INF 0x3f3f3f3f3f3f3f3f

int c;
int n,m,d,q;
ll entertostation[500005];
struct node{
    ll line,value;
};
vector<node> G1[500005];
ll G2[505][505]={0};
//bool linepass[501][500005];
struct Q{
    int s,t;
}query[100005];

void floyd(){
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(G2[i][k]!=INF&&G2[k][j]!=INF){
                    if(G2[i][j]>G2[i][k]+G2[k][j])G2[i][j]=G2[i][k]+G2[k][j];
                }
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++){
        cin>>entertostation[i];
    }
    for(int i=1;i<=n;i++){
        int t;
        cin>>t;
        ll a,w;
        for(int j=1;j<=t;j++){
            cin>>a>>w;
            G1[a].push_back({i,w});
        }
    }
    int u,v;
    for(int i=1;i<=q;i++){
        cin>>u>>v;
        query[i]={u,v};
    }

    memset(G2,0x3f,sizeof(G2));
    for(int i=1;i<=n;i++){
        G2[i][i]=0;
    }
    for(int k=1;k<=m;k++){
        for(int i=0;i<G1[k].size();i++){
            for(int j=0;j<G1[k].size();j++){
                G2[G1[k][i].line][G1[k][j].line]=min(G2[G1[k][i].line][G1[k][j].line],G1[k][i].value+G1[k][j].value);
            }
        }
    }
    floyd();

    for(int k=1;k<=q;k++){
        u=query[k].s;
        v=query[k].t;
        if(u==v){
            cout<<0<<"\n";
        }
        ll ans=INF;
        for(auto i:G1[u]){
            for(auto j:G1[v]){
                ans=min(ans,G2[i.line][j.line]+i.value+j.value);
            }
        }
        cout<<ans+entertostation[u]+entertostation[v]<<"\n";
    }
}
