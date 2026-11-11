#include<bits/stdc++.h>
using namespace std;
//typedef pair<int,int> pii;
const int N=5e5+10,M=1e5+10;
int c,n,m,d,q;
int k[510],a[510][N],t[510][N];
int x,y,maxl,w[N];
int dp[1001][1001];
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++)
        cin>>w[i];
    for(int i=1;i<=n;i++){
        cin>>k[i];
        for(int j=1;j<=k[i];j++){
            cin>>a[i][j];
            cin>>t[i][a[i][j]];
            maxl=max(maxl,a[i][j]);
        }
    }

    memset(dp,0x3f,sizeof(dp));
    for(int i=1;i<=maxl;i++){
        dp[i][i]=0;
    }
    for(int i=1;i<=maxl;i++){
        for(int j=i+1;j<=maxl;j++){
            for(int u=1;u<=n;u++){
                for(int v=1;v<=n;v++){
                    if(u==v){
                        dp[i][j]=min(dp[i][j],dp[i][j-1]+t[u][j]);
                    }else{
                        dp[i][j]=min(dp[i][j],dp[i][j-1]+t[u][j]+t[j][j]);
                    }
                }
            }
        }
    }
    for(int i=1;i<=q;i++){
        cin>>x>>y;
        cout<<dp[x][y]+w[x]+w[y]<<"\n";
    }
    return 0;
    fclose(stdin);
    fclose(stdout);
}
