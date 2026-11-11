#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
int cc,t,n,k;
vector<int>v[1000005],w[1000005];
int d[1000005];
bool vis[1000005];
int fa[1000005];
int dp[1000005],ddp[1000005],sz[1000005];
int mxd=0,mxdd=0,tsum=0;;
void dfs(int x){
    sz[x]=1;
    int md=0;
    int a=-1e9,b=-1e9;
    int aa=-1e9,bb=-1e9;
    for(int j=0;j<v[x].size();j++){
        if(!vis[v[x][j]])continue;
        if(v[x][j]==fa[x])continue;
        fa[v[x][j]]=x;dfs(v[x][j]);sz[x]+=sz[v[x][j]];
        if(dp[v[x][j]]>=a)b=a,a=dp[v[x][j]];
        else if(dp[v[x][j]]>b)b=dp[v[x][j]];
        if(ddp[v[x][j]]>=aa)bb=aa,aa=ddp[v[x][j]];
        else if(ddp[v[x][j]]>bb)bb=ddp[v[x][j]];
    }
    if(d[x]==2){
        mxd=max(mxd,a+b+1);
        dp[x]=a+1;
    }
    if(d[x]==2){
        mxdd=max(mxdd,aa+bb+1);
        mxdd=max(mxdd,a+bb+1);
        mxdd=max(mxdd,aa+b+1);
        ddp[x]=aa+1;
    }
    if(sz[x]<=1)dp[x]=-1e9;
    else dp[x]=max(dp[x],0);
    ddp[x]=max(ddp[x],0);
    mxdd=max(mxdd,ddp[x]);
}
bool sol(int p){
    queue<int>q;mxd=mxdd=0;
    for(int i=1;i<=n;i++){
        vis[i]=1;fa[i]=0;sz[i]=0;
        d[i]=v[i].size();dp[i]=ddp[i]=0;
        if(d[i]==1)q.push(i);
    }q.push(0);
    int cc=p;
    int sum=n;
    while(q.size()){
        int x=q.front();q.pop();
        if(x==0){
            cc--,q.push(0);
            if(!cc)break;
            continue;
        }sum--;
        vis[x]=0;
        for(int j=0;j<v[x].size();j++){
            if(vis[v[x][j]])d[v[x][j]]--;
            else continue;
            if(d[v[x][j]]==1)q.push(v[x][j]);
        }
    }
    int cnt=0;
    if(sum<=k)return 1;
    if(sum<=2)return 0;
    int rt=0;
    for(int i=1;i<=n;i++){
        if(!vis[i])continue;
        if(d[i]==2)rt=i;
    }tsum=sum;
    if(!rt){
        return 0;
    }
    dfs(rt);
    if(sum-min(2*p,mxd)<=k)return 1;
    if(sum-min(p-1,mxdd)<=k)return 1;
    return 0;
}
signed main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>cc>>t;
    while(t--){
        cin>>n>>k;
        for(int i=1;i<n;i++){
            int x,y;cin>>x>>y;
            v[x].push_back(y);v[y].push_back(x);
        }
        //cout<<sol(1)<<'\n';

        int l=1,r=n,ans=n;
        while(l<=r){
            int md=(l+r)/2;
            if(sol(md)){
                ans=md;r=md-1;
            }
            else{
                l=md+1;
            }
        }
        //cout<<k<<")";
        cout<<ans<<'\n';
        for(int i=1;i<=n;i++)v[i].clear();
    }
    return 0;
}
