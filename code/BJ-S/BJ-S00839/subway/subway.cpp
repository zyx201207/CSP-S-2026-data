#include<bits/stdc++.h>
using namespace std;
long long c,n,m,d,q,w[500005],a[500005][21],b[500005],t,k,u,dp[505][505],x,y;
long long minn(long long e,long long r){
    if(e<r)return e;
    else return r;
}
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++)cin>>w[i];
    for(int i=1;i<=n;i++){
        cin>>t;
        while(t--){
            cin>>u>>k;
            a[u][b[u]]=i;
            b[u]++;
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            dp[i][j]=1145141919810;
        }
    }
    for(int i=1;i<=n;i++)dp[i][i]=0;
    for(int i=1;i<=m;i++){
        for(int j=0;j<b[i];j++){
            for(int l=j+1;l<b[i];l++){
                dp[a[i][j]][a[i][l]]=1;
                dp[a[i][l]][a[i][j]]=1;
            }
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            for(int l=1;l<=n;l++){
                dp[i][j]=minn(dp[i][j],dp[i][l]+dp[j][l]);
            }
        }
    }
    while(q--){
        cin>>x>>y;
        long long p=1145141919810;
        for(int i=0;i<b[x];i++){
            for(int j=0;j<b[y];j++){
                p=minn(p,dp[a[x][i]][a[y][j]]);
            }
        }
        cout<<w[x]+w[y]+(p+1)*2*k<<endl;
    }
    return 0;
}
//AFO-2026.10.31
//bye
/*
0 5 11 200 6
1 2 3 4 5 6 7 8 9 10 11
5 1 2 2 2 3 2 4 2 5 2
0
0
0
8 1 2 5 2 6 2 7 2 8 2 9 2 10 2 11 2
*/
