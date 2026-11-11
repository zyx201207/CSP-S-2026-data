#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define P pair<int,int>
#define F first
#define S second
const int N=5e5+10,M=510;
const ll inf=1e18;

bool flag1;
int n,m,q;
int w[N];
ll dis[M][M];
bitset<M>fl[N];
int mi[N];
vector<P>v[N],e[N];
bool flag2;
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    int c,d;
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++){
        cin>>w[i];
    }
    for(int i=1,k,a,t;i<=n;i++){
        cin>>k;
        while(k--){
            cin>>a>>t;
            fl[a][i]=1;
            e[i].push_back({a,t});
            v[a].push_back({i,t});
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            for(auto x:e[j]){
                mi[x.F]=x.S;
            }
            dis[i][j]=inf;
            for(auto x:e[i]){
                if(!fl[x.F][j])continue;
                dis[i][j]=min(dis[i][j],1ll*mi[x.F]+x.S);
            }
            dis[j][i]=dis[i][j];
        }
    }
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
            }
        }
    }
    int x,y;
    ll ans;
    while(q--){
        cin>>x>>y;
        ans=inf;
        for(auto a:v[x]){
            for(auto b:v[y]){
                ans=min(ans,dis[a.F][b.F]+a.S+b.S);
            }
        }
        cout<<ans+w[x]+w[y]<<'\n';
    }
    return 0;
}
/*
0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3
*/
