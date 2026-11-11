#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e6+5,mod=1e9+7,INF=1e18;
int n,k;
vector<int> a[N];
int dis[N],id,maxx,ID;
void dfs(int x,int fa){
    if(x==fa)maxx=0;
    dis[x]=dis[fa]+1;
    if(dis[x]>maxx){
        id=x;
        maxx=dis[x];
    }
    for(int i=0;i<a[x].size();i++){
        if(a[x][i]==fa){
            continue;
        }
        dfs(a[x][i],x);
    }
}
int ans1;
int ans2;
bool c;
void dfs1(int x,int fa,int xx){
    if(x==fa)c=0;
    if(c)return;
    dis[x]=min(dis[x],dis[fa]+1);
    if(dis[x]==xx){
        ans1=x;
        c=1;
        return;
    }
    for(int i=0;i<a[x].size();i++){
        if(a[x][i]==fa){
            continue;
        }
        dfs1(a[x][i],x,xx);
    }
}
void dfs2(int x,int fa,int xx){
    if(x==fa)c=0;
    if(c)return;
    dis[x]=min(dis[x],dis[fa]+1);
    if(dis[x]==xx){
        ans2=x;
        c=1;
        return;
    }
    for(int i=0;i<a[x].size();i++){
        if(a[x][i]==fa){
            continue;
        }
        dfs2(a[x][i],x,xx);
    }
}
int ans[N],dis2[N];
void dfs3(int x,int fa,int xx){
    dis2[x]=min(dis2[x],dis2[fa]+1);
    ans[x]=min(dis[x],dis2[x]);
    for(int i=0;i<a[x].size();i++){
        if(a[x][i]==fa){
            continue;
        }
        dfs3(a[x][i],x,xx);
    }
}
int anss=0;
void dfsans(int x,int fa,int xx){
    bool op=(ans[x]>=ans[fa]);
    for(int i=0;i<a[x].size();i++){
        if(a[x][i]==fa){
            continue;
        }
        op=min(op,(ans[x]>ans[a[x][i]]));
        dfsans(a[x][i],x,xx);
    }
    anss+=max(0ll,op*(ans[x]-xx));
}
int iid;
bool get(int x){
    c=0;
    ans1=ans2=0;
    memset(dis,0x3f,sizeof(dis));
    memset(dis2,0x3f,sizeof(dis2));
    memset(ans,0x3f,sizeof(ans));
    dis[ID]=-1;
    dfs1(ID,ID,x);
    iid=ans1;
    memset(dis,0x3f,sizeof(dis));
    dis[iid]=-1;
    dfs2(iid,iid,x);
    if(ans2==0)return 1;
    memset(dis,0x3f,sizeof(dis));
    dis[ans2]=-1;
    dfs(ans2,ans2);
    dis2[ans1]=-1;
    dfs3(ans1,ans1,x);
    anss=0;
    dfsans(1,1,x);
    anss+=2;
    if(anss>k){
        return 0;
    }
    return 1;
}
signed main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int c,t;
    cin>>c>>t;
    while(t--){
        cin>>n>>k;
        int u,v;
        for(int i=1;i<=n;i++){
            a[i].clear();
        }
        for(int i=1;i<n;i++){
            cin>>u>>v;
            a[u].push_back(v);
            a[v].push_back(u);
        }
        memset(dis,0x3f,sizeof(dis));
        dis[1]=-1;
        dfs(1,1);
        int idd=id;
        maxx=id=0;
        memset(dis,0x3f,sizeof(dis));
        dis[idd]=-1;
        dfs(idd,idd);
        ID=id;
        int l=1,r=n;
        while(l<r){
            int mid=(l+r)/2;
            if(get(mid)){
                r=mid;
            }else{
                l=mid+1;
            }
        }
        cout<<l<<"\n";
    }
    return 0;
}
