#define fastio ios::sync_with_stdio(0);cin.tie(0);
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll inf=1e18;
const int maxn=508,maxm=5e5+35;

int c,n,m,d,q;
ll inouttime[maxm];
struct Line{
    int stacnt;
    vector<int> sta;
    vector<ll> tim;
}line[maxn];
vector<int> passline[maxm];
vector<ll> passlinetotime[maxm];
void input(){
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;++i){
        cin>>inouttime[i];
    }
    for(int i=1;i<=n;++i){
        int k;
        cin>>k;
        line[i].stacnt=k;
        for(int j=1;j<=k;++j){
            int a;
            ll t;
            cin>>a>>t;
            line[i].sta.push_back(a);
            line[i].tim.push_back(t);
            passline[a].push_back(i);
            passlinetotime[a].push_back(t);
        }
    }
}


ll trans[maxn][maxn];
void calc_transfertime(){//?
    memset(trans,0x3f,sizeof(trans));
    for(int i=1;i<=n;++i){
        trans[i][i]=0;
    }
    for(int s=1;s<=m;++s){
        for(int i=0;i<passline[s].size();++i){
            for(int j=0;j<passline[s].size();++j){
                int x=passline[s][i],y=passline[s][j];
                // cout<<x<<" "<<y<<endl;
                ll tox=passlinetotime[s][i],toy=passlinetotime[s][j];
                trans[x][y]=trans[y][x]=min(trans[x][y],tox+toy);
            }
        }
    }
}

ll dis[maxn][maxn];
void solve(){
    memset(dis,0x3f,sizeof(dis));
    for(int i=1;i<=n;++i){
        dis[i][i]=0;
        for(int j=1;j<=n;++j){
            dis[i][j]=trans[i][j];
        }
    }
    for(int k=1;k<=n;++k){
        for(int i=1;i<=n;++i){
            for(int j=1;j<=n;++j){
                if(dis[i][j]>dis[i][k]+dis[k][j]){
                    dis[i][j]=dis[i][k]+dis[k][j];
                }
            }
        }
    }
    // for(int i=1;i<=n;++i){
    //     for(int j=1;j<=n;++j){
    //         // cout<<dis[i][j]<<" ";
    //     }
    //     // cout<<endl;
    // }
}


void answ(){
    for(int i=1;i<=q;++i){
        int u,v;
        cin>>u>>v;
        ll ans=inf;
        for(int i=0;i<passline[u].size();++i){
            int lu=passline[u][i];
            for(int j=0;j<passline[v].size();++j){
                int lv=passline[v][j];
                ans=min(ans,dis[lu][lv]+inouttime[u]+inouttime[v]+passlinetotime[u][i]+passlinetotime[v][j]);
            }
        }
        printf("%lld\n",ans);
    }
}

int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    fastio;
    input();
    calc_transfertime();
    solve();
    answ();
    return 0;
}
