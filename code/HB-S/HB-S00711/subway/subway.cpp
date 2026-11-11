#include<bits/stdc++.h>
using namespace std;
#define int long long
struct station{
    int togo;
    int tim;
};
int floyd[510][510];
vector<station> state[500010];
int c,n,m,d,q;
int w[500010];
signed main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    memset(floyd,0x3f3f3f3f,sizeof(floyd));
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++){
        cin>>w[i];
    }
    for(int i=1;i<=n;i++){
        int k;
        cin>>k;
        for(int j=1;j<=k;j++){
            int st,tt;
            cin>>st>>tt;
            state[st].push_back({i,tt});
        }
    }
    for(int i=1;i<=m;i++){
        for(int j=0;j<state[i].size();j++){
            for(int s=0;s<state[i].size();s++){
                if(j!=s){
                    floyd[state[i][j].togo][state[i][s].togo] = min(floyd[state[i][j].togo][state[i][s].togo],state[i][j].tim+state[i][s].tim);
                    floyd[state[i][s].togo][state[i][j].togo] = min(floyd[state[i][s].togo][state[i][j].togo],state[i][j].tim+state[i][s].tim);
                }
            }
        }
    }
    for(int i=1;i<=n;i++) floyd[i][i] = 0;
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                floyd[i][j] = min(floyd[i][j],floyd[i][k]+floyd[k][j]);
            }
        }
    }
    for(int i=1;i<=q;i++){
        int u,v;
        cin>>u>>v;
        int minn = 1e18;
        for(int j=0;j<state[u].size();j++){
            for(int s=0;s<state[v].size();s++){
                minn = min(minn,floyd[state[v][s].togo][state[u][j].togo]+w[u]+w[v]+state[v][s].tim+state[u][j].tim);
            }
        }
        cout<<minn<<"\n";
    }
    return 0;
}
//16:01 ok 7 substack