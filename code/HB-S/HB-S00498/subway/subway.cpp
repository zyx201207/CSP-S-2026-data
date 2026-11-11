#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define ull unsigned long long
#define eb emplace_back
#define umap unordered_map
#define ll long long
#define Fast1 ios::sync_with_stdio(0)
#define Fast2 cin.tie(0),cout.tie(0)
#define int long long
#define pii pair<int,int>
#define F first
#define S second
#define mp make_pair
const int N=505;
const int D=25;
const int M=5e5+5;
const int inf=1e18;
int n,m,d,q,K[N],f_[N][N],w[M];
int f[N][N];
vector<pii>v[M];
void s_(){
    cin>>n>>m>>d>>q;
    for(int i=1;i<=m;i++)cin>>w[i];
    for(int i=1;i<=n;i++){
        cin>>K[i];
        for(int j=1;j<=K[i];j++){
            int x,y;cin>>x>>y;
            v[x].pb({i,y});
        }
    }
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            f[i][j]=f_[i][j]=inf;
    for(int i=1;i<=n;i++)f[i][i]=f_[i][i]=0;
    for(int i=1;i<=m;i++){
        for(int k_=0;k_<v[i].size();k_++)
            for(int k=0;k<v[i].size();k++)
                f_[v[i][k_].F][v[i][k].F]=
                min(f_[v[i][k_].F][v[i][k].F],
                    v[i][k_].S+v[i][k].S);
    }
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            f[i][j]=f_[i][j];
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            for(int k=1;k<=n;k++)
                f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
        }
    }
    for(int i=1;i<=q;i++){
        int x,y;cin>>x>>y;int ans=inf;
        for(int j=0;j<v[x].size();j++)
            for(int k=0;k<v[y].size();k++){
                ans=min(ans,v[x][j].S+v[y][k].S+f[v[x][j].F][v[y][k].F]);
            }
        cout<<ans+w[x]+w[y]<<"\n";
    }
}
signed main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    Fast1;Fast2;
    int c,t=1;
    cin>>c;while(t--)s_();
}
