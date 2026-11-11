#include<bits/stdc++.h>
using namespace std;
#define int long long
vector<pair<int,int> > v[500005];
int dp[505][505];
int w[500005];
signed main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    int c,n,m,d,q;
    cin>>c>>n>>m>>d>>q;
    int k,a,t;
    for (int i=1;i<=n;i++){
        for (int j=1;j<=n;j++){
            if (i!=j) dp[i][j]=4e18;
        }
    }
    for (int i=1;i<=m;i++) scanf("%lld",&w[i]);
    for (int i=1;i<=n;i++){
        scanf("%lld",&k);
        for (int j=1;j<=k;j++){
            scanf("%lld%lld",&a,&t);
            v[a].push_back({i,t});
        }
    }
    for (int i=1;i<=m;i++){
        for (int j1=0;j1<v[i].size();j1++){
            for (int j2=j1+1;j2<v[i].size();j2++){
                int a11=v[i][j1].first,a12=v[i][j1].second;
                int a21=v[i][j2].first,a22=v[i][j2].second;
                dp[a11][a21]=min(dp[a11][a21],a12+a22);
                dp[a21][a11]=min(dp[a21][a11],a12+a22);
            }
        }
    }
    for (int k1=1;k1<=n;k1++){
        for (int i=1;i<=n;i++){
            for (int j=1;j<=n;j++){
                dp[i][j]=min(dp[i][j],dp[i][k1]+dp[k1][j]);
            }
        }
    }
    int x,y;
    for (int i=1;i<=q;i++){
        int ans=9e18;
        scanf("%lld%lld",&x,&y);
        for (int j1=0;j1<v[x].size();j1++){
            for (int j2=0;j2<v[y].size();j2++){
                int a11=v[x][j1].first,a12=v[x][j1].second;
                int a21=v[y][j2].first,a22=v[y][j2].second;
                //cout<<a11<<" "<<a21<<endl;
                //cout<<a12<<" "<<a22<<endl;
                ans=min(ans,a12+a22+dp[a11][a21]);
            }
        }
        printf("%lld\n",w[x]+w[y]+ans);
    }
    return 0;
}
