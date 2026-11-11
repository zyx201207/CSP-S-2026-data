#include <bits/stdc++.h>
#define int long long
using namespace std;
int n;
int m;
int c;
int d;
int q;
int w[500005];
vector<pair<int,int> > line[505];
vector<pair<int,int> > sub[500005];
int f[505][505];
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++){
        cin>>w[i];
    }
    for(int i=1;i<=n;i++){
        int k;
        cin>>k;
        for(int j=1;j<=k;j++){
            int a,t;
            cin>>a>>t;
            line[i].push_back({a,t});
            sub[a].push_back({i,t});
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            f[i][j]=1e18;
        }
        f[i][i]=0;
    }
    for(int i=1;i<=m;i++){
        for(auto [j,t1] : sub[i]){
            for(auto [k,t2] : sub[i]){
                if(j!=k){
                    f[j][k]=min(f[j][k],t1+t2);
                    f[k][j]=min(f[k][j],t1+t2);
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
    while(q--){
        int x,y;
        cin>>x>>y;
        int ans=1e18;
        for(auto i : sub[x]){
            for(auto j : sub[y]){
                ans=min(ans,f[i.first][j.first]+i.second+j.second+w[x]+w[y]);
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
//100