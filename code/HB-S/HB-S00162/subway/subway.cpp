#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int maxn=5e5+5;
int w[maxn];
int dp[1005][1005];
int t[1005][1005];
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    int c,n,m,d,q;
    cin >> c >> n >> m >> d >> q;
    for(int i=1;i<=m;i++){
        cin >> w[i];
    }
    int k;
    memset(dp,0x3f,sizeof(dp));
    memset(t,0x3f,sizeof(t));
    for(int f=1;f<=n;f++){
        cin >> k;
        int a,ti;
        for(int i=1;i<=k;i++){
            cin >> a >> ti;
            t[f][a]=t[a][f]=ti;
        }
    }
    for(int i=1;i<=m;i++) dp[i][i]=0;


    for(int k=1;k<=m;k++){
        for(int i=1;i<=m;i++){
            for(int j=1;j<=m;j++){
                if(t[i][k]==0x3f||t[k][j]==0x3f) continue;
                dp[i][j]=min(dp[i][j],t[i][k]+t[k][j]);
            }
        }
    }
    for(int k=1;k<=m;k++){
        for(int i=1;i<=m;i++){
            for(int j=1;j<=m;j++){
                dp[i][j]=min(dp[i][j],dp[i][k]+dp[k][j]);
            }
        }
    }
    ll ans;
    int x,y;
    while(q--){
        ans=0;
        cin >> x >> y;
        ans+=w[x]+w[y];
        ans+=dp[x][y];
        cout << ans << "\n";
    }
    return 0;
}
