#include<iostream>
#include<vector>
#include<cstring>
using namespace std;
#define int long long
const int N=5e5+5;
const int M=505;
int w[N],f[M][M];
vector<pair<int,int> > v[N],l[N];

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    int c,n,m,q;
    cin>>c>>n>>m>>q>>q;
    for(int i=1;i<=m;i++){
        cin>>w[i];
    }
    for(int i=1;i<=n;i++){
        int k;
        cin>>k;
        for(int j=1;j<=k;j++){
            int x,t;
            cin>>x>>t;
            v[x].push_back({i,t});
            l[i].push_back({x,t});
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(i==j) f[i][j]=0;
            else f[i][j]=1e18;
        }
    }
    for(int i=1;i<=n;i++){
        for(auto j : l[i]){
            for(auto k : v[j.first]){
                if(k.first==i) continue;
                f[i][k.first]=j.second+k.second;
                f[k.first][i]=j.second+k.second;
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
    while(q--){
        int x,y,ans=1e18;
        cin>>x>>y;
        for(auto i : v[x]){
            for(auto j : v[y]){
                ans=min(ans,f[i.first][j.first]+i.second+j.second);
            }
        }
        cout<<ans+w[x]+w[y]<<'\n';
    }
    return 0;
}
