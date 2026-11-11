#include<bits/stdc++.h>
#define int long long
#define PII pair<int,int>
#define fir first
#define sec second
using namespace std;
int c,n,m,d,q;
int w[500005],f[505][505];
vector<PII> a[505],b[500005];
signed main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++){
        cin>>w[i];
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(i==j)f[i][i]=0;
            else f[i][j]=1e18;
        }
    }
    for(int i=1;i<=n;i++){
        int k;
        cin>>k;
        for(int j=1;j<=k;j++){
            int t,x;
            cin>>t>>x;
            a[i].push_back({t,x});
            b[t].push_back({i,x});
        }
    }
    for(int i=1;i<=n;i++){
        for(auto u:a[i]){
            for(auto v:b[u.fir])
                f[i][v.fir]=min(f[i][v.fir],u.sec+v.sec);
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            for(int k=1;k<=n;k++){
                f[j][k]=min(f[j][k],f[j][i]+f[i][k]);
            }
        }
    }
    while(q--){
        int x,y;
        cin>>x>>y;
        int ans=1e18;
        for(auto i:b[x]){
            for(auto j:b[y]){
                ans=min(ans,f[i.fir][j.fir]+i.sec+j.sec);
            }
        }
        ans+=w[x]+w[y];
        cout<<ans<<'\n';
    }
    return 0;
}
