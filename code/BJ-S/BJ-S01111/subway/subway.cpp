#include<bits/stdc++.h>
using namespace std;
#define maxn 500005
#define int long long
int c,n,m,d,q,w[maxn],dp[505][505];
vector<int> a[maxn],t[maxn];
signed main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    memset(dp,0x3f,sizeof(dp));
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++){
        cin>>w[i];
    }
    for(int i=1;i<=n;i++){
        dp[i][i]=0;
        int k;
        cin>>k;
        for(int j=1;j<=k;j++){
            int aa,tt;
            cin>>aa>>tt;
            a[aa].push_back(i);
            t[aa].push_back(tt);
        }
    }
    for(int i=1;i<=m;i++){
        for(int j=0;j<a[i].size();j++){
            for(int k=0;k<j;k++){
                dp[a[i][j]][a[i][k]]=min(dp[a[i][j]][a[i][k]],t[i][j]+t[i][k]);
                dp[a[i][k]][a[i][j]]=min(dp[a[i][k]][a[i][j]],t[i][j]+t[i][k]);
            }
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            for(int k=1;k<=n;k++){
                dp[j][k]=min(dp[j][k],dp[j][i]+dp[i][k]);
            }
        }
    }
    for(int i=1;i<=q;i++){
        int x,y,ans=0x3f3f3f3f3f3f3f3f;
        cin>>x>>y;
        for(int j=0;j<a[x].size();j++){
            for(int k=0;k<a[y].size();k++){
                ans=min(ans,dp[a[x][j]][a[y][k]]+t[x][j]+t[y][k]);
            }
        }
        cout<<ans+w[x]+w[y]<<'\n';
    }
    return 0;
}