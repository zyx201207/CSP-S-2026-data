#include<iostream>
#include<vector>
using namespace std;

const int maxn=1000+10,inf=1e9;
int n,k,dp[maxn][3][maxn],sel[maxn],maxdep[maxn],mn[maxn][maxn],dep[maxn];
vector<int> grp[maxn];

void dfs(int cur, int pa, int lim){
    maxdep[cur]=dep[pa]+1; maxdep[cur]=dep[cur];
    for(auto x:grp[cur])if(x!=pa)dfs(x,cur,lim),maxdep[cur]=max(maxdep[cur],dep[x]);
    // dp[cur][1][0]
    dp[cur][1][0]=1;
    for(auto x:grp[cur])if(x!=pa){
        if(maxdep[x]-dep[cur]>lim)dp[cur][1][0]+=dp[x][1][0];
    }
    // dp[cur][1][x]
    for(int j=1;j<=maxdep[cur]-dep[cur]&&j<=lim;j++){
        int pos=-1;
        for(auto x:grp[cur])if(x!=pa){
            if(maxdep[x]-dep[cur]+j>lim){
                if(pos==-1)pos=x;
                else pos=-2;
            }
        }
        if(pos==-2)break;
        if(pos==-1){
            int xm=inf;
            for(auto x:grp[cur])if(x!=pa)xm=min(xm,dp[x][1][j-1]);
            dp[cur][1][j]=xm;
        }else dp[cur][1][j]=dp[pos][1][j-1];
    }
    mn[cur][lim+1]=inf;
    for(int j=lim;j>=0;j--)mn[cur][j]=min(mn[cur][j+1],dp[cur][1][j]);
    // dp[cur][2][0]
    dp[cur][2][0]=1;
    int delta=inf;
    for(auto x:grp[cur])if(x!=pa){
        if(maxdep[x]-dep[cur]>lim)dp[cur][2][0]+=dp[x][1][0],delta=min(delta,dp[x][2][0]-dp[x][1][0]),delta=min(delta,mn[x][1]-dp[x][1][0]);
    }
    if(delta==inf)dp[cur][2][0]=inf;
    else dp[cur][2][0]+=delta;
    // dp[cur][2][x]
    for(int j=1;j<=maxdep[cur]-dep[cur]&&j<=lim;j++){
        int pos1=-1,pos2=-1;
        for(auto x:grp[cur])if(x!=pa){
            if(maxdep[x]-dep[cur]+j>lim){
                if(pos1==-1)pos1=x;
                else if(pos2==-1)pos2=x;
                else pos1=-2;
            }
        }
        if(pos1==-2)break;
        if(pos1==-1){
            for(auto x:grp[cur])if(x!=pa)dp[cur][2][j]=min(dp[cur][2][j],dp[x][2][j-1]);
            for(auto x:grp[cur])for(auto y:grp[cur])if(x!=pa&&y!=pa&&x!=y)dp[cur][2][j]=min(dp[cur][2][j],dp[x][1][j-1]+mn[y][j-1]);
        }else if(pos2==-1){
            int xm=inf,xm2=inf;
            for(auto x:grp[cur])if(x!=pa&&x!=pos1)xm=min(xm,mn[x][j-1]),xm2=min(xm2,dp[x][1][j-1]);
            dp[cur][2][j]=min(dp[pos1][2][j-1],min(dp[pos1][1][j-1]+xm,mn[pos1][j-1]+xm2));
        }else{
            dp[cur][2][j]=min(dp[pos1][1][j-1]+mn[pos2][j-1],dp[pos2][1][j-1]+mn[pos1][j-1]);
        }
    }
    
}
bool check(int lim){
   for(int x=1;x<=n;x++)for(int i=1;i<=2;i++)for(int j=0;j<=lim;j++)dp[x][i][j]=inf;
    dfs(1,0,lim);
    int ans=inf;
    for(int i=1;i<=2;i++)for(int j=0;j<=lim;j++){
       ans=min(ans,dp[1][i][j]);
    }
    /*if(lim==1){
    for(int x=1;x<=n;x++){
        for(int i=1;i<=2;i++)for(int j=0;j<=lim;j++)cout<<x<<' '<<i<<' '<<j<<' '<<dp[x][i][j]<<endl;
        cout<<endl;
    }
    }*/
    return ans<=k;
}

int main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    int tc,T; cin>>tc>>T;
    while(T--){
        cin>>n>>k;
        for(int i=1;i<n;i++){
            int u,v; cin>>u>>v;
            grp[u].push_back(v);
            grp[v].push_back(u);
        }
        int l=0,r=n;
        while(l<=r){
            int mid=(l+r)/2;
            if(check(mid))r=mid-1;
            else l=mid+1;
        }
        cout<<r+1<<endl;
        for(int i=1;i<=n;i++)grp[i].clear();
    }
}