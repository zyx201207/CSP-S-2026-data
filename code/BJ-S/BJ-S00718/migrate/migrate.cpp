#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e3+9;
struct node{
    int d,x;
};
int n,d,w[N];
node dp[N][N];
void dfs(int x,int s,int f){
    if(x>=n){
        return;
    }
    if(dp[f][x].d>s){
        dp[f][x].d=s;
        dp[f][x].x=1;
    }else if(dp[f][x].d==s){
        dp[f][x].x++;
    }
    for(int i=1;w[x+i]-w[x]<=d;i++){
        dfs(x+i,s+1,x);
    }
}
signed main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
int c,t;
    cin>>c>>t;
    while(t--){
        cin>>n>>d;
        for(int i=1;i<=n;i++){
            cin>>w[i];
        }
        w[n+1]=1e16;
        memset(dp,0,sizeof dp);
        dfs(1,0,0);
        int cnt=0;
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                if(dp[i][j].n==2){
                    cnt++;
                }
            }
        }
        cout<<cnt<<endl;
    }
    return 0;
}
