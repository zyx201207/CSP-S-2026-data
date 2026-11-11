#include<bits/stdc++.h>
#define int long long
using namespace std;
int a[2000005];
int f[5005][5005];
bool vis[5005];
int n,d;
int st;
int cnt;
void dfs(int x,int sum){
    f[st][x]=min(f[st][x],sum);
    f[x][st]=min(f[x][st],sum);
    for(int i=1;i<=n;i++){
        if(!vis[i]&&abs(a[i]-a[x])<=d){
            vis[i]=1;
            dfs(i,sum+1);
            vis[i]=0;
        }
    }
    return ;
}
void dfs2(int x,int y,int sum,int tar){
    if(x==y&&sum==tar){
        cnt++;
        return ;
    }
    for(int i=1;i<=n;i++){
        if(!vis[i]&&abs(a[i]-a[x])<=d){
            vis[i]=1;
            dfs2(i,y,sum+1,tar);
            vis[i]=0;
        }
    }
    return ;
}
signed main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int  c,t;
    cin>>c>>t;
    while(t--){
        cin>>n>>d;
        for(int i=1;i<=n;i++)
            cin>>a[i];
        for(int i=0;i<=5000;i++)
            for(int j=0;j<=5000;j++)
                f[i][j]=INT_MAX;
        for(int i=1;i<=n;i++){
            st=i;
            vis[i]=1;
            dfs(i,0);
            vis[i]=0;
        }
        int ans=0;
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                cnt=0;
                vis[i]=1;
                dfs2(i,j,0,f[i][j]);
                if(cnt==2)
                    ans++;
                vis[i]=0;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
