#include<bits/stdc++.h>
#define int long long
using namespace std;
const int M = 2e6+5;
int c,n,k,inf=0x3f3f3f3f3f3f3f3f;
vector<int> dp[M][3][2];
int f[M][3][2];
int siz[M],dep[M],Mid;
vector<int>ve[M];
void chmax(int &x,int y){
    if((x>=0&&y>0)){
        x=min(x,y);
    }else{
        x=max(x,y);
    }
}
void dfs(int x,int fa){
    siz[x]=1,dep[x]=dep[fa]+1;
    dp[x][0][0][0]=-dep[x];
    dp[x][1][1][1]=dep[x];
    for(int u:ve[x])if(u!=fa)dfs(u,x);
    for(int u:ve[x])if(u!=fa){
        for(int i=0;i<=siz[x]&&i<=k;i++)for(int o1=0;o1<3;o1++)for(int p1=0;p1<2;p1++)if(dp[x][o1][p1][i]!=-inf){
            for(int j=0;j<=siz[u]&&j<=k;j++)for(int o2=0;o2<3;o2++)for(int p2=0;p2<2;p2++)if(dp[u][o2][p2][j]!=inf){
                int ds=i+j,df=(o1+o2-(p1&&p2));
                if(df>2)continue;
                if(ds>k)continue;
                int wx=dp[x][o1][p1][i],wy=dp[u][o2][p2][j];
                if(wy<=0&&wx<=0)chmax(f[ds][df][p1],min(wy,wx));
                else if(wy>=0&&wx>=0)chmax(f[ds][df][p1],min(wx,wy));
                else{
                    if(wx<0&&wy>0)swap(wx,wy);
                    if(wx+(-wy)-2*dep[x]>Mid)chmax(f[ds][df][p1],wy);
                    else chmax(f[ds][df][p1],wx);
                }
            }
        }
        siz[x]+=siz[u];
        for(int i=0;i<=siz[x]&&i<=k;i++)for(int o1=0;o1<3;o1++)for(int p1=0;p1<2;p1++)dp[x][o1][p1][i]=f[i][o1][p1],f[i][o1][p1]=-inf;
    }
    // if(Mid==1)for(int i=0;i<=siz[x]&&i<=k;i++)for(int o1=0;o1<3;o1++)for(int p1=0;p1<2;p1++)if(dp[x][o1][p1][i]!=-inf)cout<<x<<" "<<o1<<" "<<p1<<" "<<i<<":"<<dp[x][o1][p1][i]<<"\n";
}
bool check(){
    for(int i=1;i<=n;i++)for(int o1=0;o1<3;o1++)for(int p1=0;p1<2;p1++){
        dp[i][o1][p1].clear();
        dp[i][o1][p1].resize(k+2,-inf);
        f[i][o1][p1]=-inf;
    }
    dfs(1,0);
    for(int o1=0;o1<3;o1++)for(int p1=0;p1<2;p1++)if(dp[1][o1][p1][k]>=0)return 1;
    return 0;
}
void Main(){
    cin>>n>>k;
    for(int i=1,u,v;i<n;i++){
        cin>>u>>v;
        ve[u].push_back(v),ve[v].push_back(u);
    }
    int l=0,r=n+1;
    while(l<r){
        Mid=(l+r)>>1;
        if(check()){
            r=Mid;
        }else{
            l=Mid+1;
        }
    }
    cout<<l<<"\n";
    for(int i=1;i<=n;i++){
        ve[i].clear();
    }
}
signed main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    int T=1;
    cin>>c>>T;
    while(T--)Main();
}