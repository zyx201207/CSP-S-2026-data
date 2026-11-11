#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    int f[8][2] = {{1,0},{0,1},{0,-1},{1,1},{1,-1},{-1,1},{-1,0},{-1,-1}};
    int c,n,m,d,q;
    cin>>c>>n>>m>>d>>q;
    long long w[m + 1];
    for(int i = 1; i <= m; i++){
        cin>>w[i];
    }
    int dp[1001][1001];
    int k ;
    cin>>k;
    int a[k + 1][q + 1], t[k + 1][q + 1];
    for(int i = 1; i <= q; i++){
        for(int j = 1; j <= k; j++){
            cin>>a[i][j]>>t[i][j];
            dp[i][a[i][j]]++;
        }
    }
    int x[q + 1],y[q + 1];
    int t1[q + 1];
    for(int i = 1; i <= n; i++){
        cin>>x[i]>>y[i];
    }
    int cnt[q + 1];
    int xc = 0,yc = 0;
    for(int i = 1; i <= q; i++){
        for(int j = 1; j <= n; j++){
            for(int k = 0; k < 8; k++){
                if(dp[i + f[k][0]][x[i] + f[k][1]] == y[i]){
                    cout<<cnt[i]<<endl;
                }
                else if(i + f[k][0] <= q && x[i] + f[k][1] <= k){
                    cnt[i] += w[x[i]] + t[x[i]][i];
                    x[i]++;
                }
                else{
                    x[i]--;
                }
            }
        }
    }
    return 0;

}
