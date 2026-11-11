#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll c,t,n,d,x[2000010];
ll dpv[2000010];
ll dp[2000010];
int dfs(int st,int u){
    if(u>n){
        return 0;
    }
    if(st>dp[u]){
        return 0;
    }
    if(dp[u]>st){
        dpv[u]=0;
        dp[u]=st;
    }
    dpv[u]++;
    for(int v=u+1;x[v]-x[u]<=d && v<=n;v++){
        dfs(st+1,v);
    }
    return 0;
}

int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>t;
    while(t--){
        cin>>n>>d;
        for(int i=1;i<=n;i++){
            cin>>x[i];
            dp[i]=0x3f;
        }
        int ans=0;
        for(int u=1;u<=n;u++){
            dfs(1,u);
            for(int v=u+1;v<=n;v++){
                cout<<dpv[v]<<'\n';
                if(dpv[v]==2){
                    ans++;
                    dpv[v]=0;
                    dp[v]=0x3f;
                }
            }
        }
        cout<<ans<<'\n';
    }
    return 0;
}

/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2
*/
