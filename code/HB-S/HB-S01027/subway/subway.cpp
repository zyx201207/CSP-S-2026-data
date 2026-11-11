#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int MAXN = 100;
struct node{
    int w;
}zhantai[MAXN];
int edge[MAXN][MAXN];
int dp[MAXN][MAXN];
queue<int> que;
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int c,n,m,d,q,xa,ya,line,time,station,k;
    cin>>c>>n>>m>>d>>q;
    for(int i = i;i<=m;i++){
        cin>>zhantai[i].w;
    }
    for(int j = 1;j<=n;j++){//xian lu bian hao
        cin>>k;
        for(int lol = 1;lol<=k;lol++){
            cin >> station >> time;
            edge[station][j] = time;
        }
    }
    for(int now = 1;now<=m;now++){//chu li ge dian
            for(int p = 1;p<=n;p++){
                for(int l = 1;(l<=n)&&(l!=p);l++){
                    if(edge[now][p]&&edge[now][l])dp[p][l] = max(edge[now][p]+edge[now][l],dp[p][l]);
                }
            }
    }
    for(int k = 1;k<=n;k++){//floyd
    for(int i = 1;(i<=n)&&(i!=k);i++){
        for(int j = i;(j<=n)&&(j!=k);j++){
            if(dp[i][j]&&dp[i][k]&&dp[k][j]){
                dp[i][j] = min(dp[i][j],dp[i][k]+dp[k][j]);
            }
        }
        }
    }

    while(q--){
        int ans = 0;
        cin>>xa>>ya;
        for(int i = 1;i<=n;i++){
            for(int j = 1;j<=n;j++){
                if(edge[xa][i]&&edge[ya][j]){
                    ans = min(ans,dp[i][j]);
                }
            }
        }
        int w = zhantai[xa].w+zhantai[ya].w;
        que.push(w);
    }
    while(!que.empty()){
            cout<<que.front();que.pop();
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
