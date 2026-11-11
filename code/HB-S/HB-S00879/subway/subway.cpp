#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=500005;
ll C=0,n=0,m=0,d=0,q=0;
ll k=0;
struct transfer{
    ll line;
    ll walk;
};
vector<transfer> station[N];
ll graph[1000][1000];
ll w[500005];

ll work(){
    memset(graph,0x3f,sizeof(graph));
    for(ll i=1;i<=n;i++){
        graph[i][i]=0;
    }
    for(ll i=1;i<=m;i++){
        for(ll j=0;j<station[i].size();j++){
            for(ll k=0;k<j;k++){
                graph[station[i][j].line][station[i][k].line]=station[i][j].walk+station[i][k].walk;
                graph[station[i][k].line][station[i][j].line]=station[i][j].walk+station[i][k].walk;
            }
        }
    }
    for(ll k=1;k<=n;k++){
        for(ll i=1;i<=n;i++){
            for(ll j=1;j<=n;j++){
                graph[i][j]=min(graph[i][j],graph[i][k]+graph[k][j]);
            }
        }
    }
}

ll plan(ll x,ll y){
    ll min_time=6767676767676767;
    transfer xx;
    transfer yy;
    for(ll i=0;i<station[x].size();i++){
        for(ll j=0;j<station[y].size();j++){
            xx=station[x][i];
            yy=station[y][j];
            min_time=min(min_time,xx.walk+yy.walk+graph[xx.line][yy.line]);
        }
    }
    return w[x]+w[y]+min_time;
}


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>C>>n>>m>>d>>q; // n - line count | m - station count | q - question count
    for(ll i=1;i<=m;i++){
        cin>>w[i]; // time to get to lobby
    }
    ll stn=0;
    transfer o;
    for(ll i=1;i<=n;i++){
        cin>>k;
        stn=0;
        o.line=i;
        for(ll j=0;j<k;j++){
            cin>>stn>>o.walk;
            station[stn].push_back(o);
        }
    }
    work();
    ll x,y;
    for(ll i=0;i<q;i++){
        cin>>x>>y;
        cout << plan(x,y) << "\n";
    }
    return 0;
}
