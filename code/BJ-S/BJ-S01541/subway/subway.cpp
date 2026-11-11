#include<iostream>
#include<cstring>
#include<vector>
using namespace std;
constexpr int N=505,M=5e5+5,D=25;
int c,n,m,d,q;
using ll=long long;
ll w[M],f[N][N];
vector<pair<int,int>> v[M];
constexpr ll inf=0x3f3f3f3f3f3f3f3f;
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin.tie(nullptr)->sync_with_stdio(false);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++) cin>>w[i];
    for(int i=1,k,a,t;i<=n;i++){
        cin>>k;
        for(int j=0;j<k;j++){
            cin>>a>>t;
            v[a].emplace_back(i,t);
        }
    }
    memset(f,0x3f,sizeof(f));
    for(int i=1;i<=n;i++) f[i][i]=0;
    for(int i=1;i<=m;i++){
        if(v[i].size()>=2){
            for(int j=1;j<v[i].size();j++){
                for(int k=0;k<j;k++){
                    f[v[i][j].first][v[i][k].first]=min(f[v[i][j].first][v[i][k].first],(ll)v[i][j].second+(ll)v[i][k].second);
                    f[v[i][k].first][v[i][j].first]=min(f[v[i][k].first][v[i][j].first],(ll)v[i][j].second+(ll)v[i][k].second);
                }
            }
        }
    }
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
            }
        }
    }
    // for(int i=1;i<=n;i++){
    //     for(int j=1;j<=n;j++){
    //         cout<<f[i][j]<<' ';
    //     }
    //     cout<<'\n';
    // }
    while(q--){
        int x,y;
        cin>>x>>y;
        ll ans=inf;
        for(int i=0;i<v[x].size();i++){
            for(int j=0;j<v[y].size();j++){
                ans=min(ans,w[x]+w[y]+v[x][i].second+v[y][j].second+f[v[x][i].first][v[y][j].first]);
            }
        }
        cout<<ans<<'\n';
    }
    return 0;
}