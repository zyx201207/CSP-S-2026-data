#include<bits/stdc++.h>
using namespace std;
const int MAXN=500+2,MAXM=5000+2;
int ccc,n,m,d,q,a[MAXM],k[MAXN],x,t,dp[MAXM][MAXM],l,r,dis[MAXN+MAXM+100],ans,y,tt,bl;
pair<pair<int,int>,int>b[MAXN];
vector<int>tree[MAXM+MAXN+100];
void dfs(int now,int sum){
    if(sum>=ans)
        return;
    if(now==r){
        ans=min(ans,sum);
        return;
    }
    for(auto i:tree[now]){
        if(sum+dp[now][i]<dis[i]){
            dis[i]=sum+dp[now][i];
            dfs(i,sum+dp[now][i]);
        }
    }
}
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>ccc>>n>>m>>d>>q;
    if(ccc!=20&&ccc!=21){
        memset(dp,0x3f,sizeof(dp));ans=1000000000;
        for(int i=1;i<=m;i++)
            cin>>a[i];
        for(int i=1;i<=n;i++){
            cin>>k[i];
            for(int j=1;j<=k[i];j++){
                cin>>x>>t;
                tree[m+i].push_back(x);
                tree[x].push_back(m+i);
                dp[x][m+i]=dp[m+i][x]=t;
            }
        }
        while(q--){
            memset(dis,0x3f,sizeof(dis));ans=1000000000;
            cin>>l>>r;
            dis[l]=0;
            dfs(l,0);
            cout<<a[l]+a[r]+ans<<endl;
        }
    }
    if(ccc<=21&&ccc>19){
        int s[500000+2][2],atob=1000000000;
        memset(s,0x3f,sizeof(s));ans=1000000000;
        for(int i=1;i<=m;i++)
            cin>>a[i];
        cin>>k[0];
        for(int i=1;i<=k[0];i++){
            cin>>x>>t;
            s[x][0]=t;
        }
        cin>>k[1];
        for(int i=1;i<=k[1];i++){
            cin>>x>>t;
            s[x][1]=t;
        }
        for(int i=1;i<=m;i++){
            atob=min(atob,s[i][0]+s[i][1]);
        }
        while(q--){
            cin>>l>>r;
            cout<<a[l]+a[r]+min(s[l][0]+s[r][0],min(s[l][1]+s[r][1],min(s[l][0]+s[r][1]+atob,s[l][1]+s[r][0]+atob)))<<endl;
        }
    }
}
