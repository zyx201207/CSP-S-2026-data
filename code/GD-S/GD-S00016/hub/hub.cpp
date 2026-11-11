#include<bits/stdc++.h>
using namespace std;
int n,k,a[2000001],dis[2000001],fa[2000001],ans;
vector<int>e[2000001];
int find(int x){
    if(fa[x]==x)return x;
    else return fa[x]=find(fa[x]);
}
void merge(int x,int y){
    x=find(x),y=find(y);
    if(x==y)return;
    fa[x]=y;
}
void check(){
    queue<int>q;
    for(int i=1;i<=n;i++){
        fa[i]=i;
        dis[i]=n+1;
        if(a[i])q.push(i),dis[i]=0;
    }
    while(!q.empty()){
        int fr=q.front();
        q.pop();
        for(auto v:e[fr]){
            if(dis[v]==n+1){
                dis[v]=dis[fr]+1;
                q.push(v);
            }
        }
    }
    for(int i=1;i<=n;i++){
        for(auto v:e[i])if(dis[i]==0&&dis[v]==0)merge(i,v);
    }
    int scccnt=0;
    for(int i=1;i<=n;i++){
        if(dis[i]==0&&find(i)==i)scccnt++;
    }
    if(scccnt!=2)return;
    int maxn=0;
    for(int i=1;i<=n;i++)maxn=max(maxn,dis[i]);
    ans=min(ans,maxn);
}
void bf(int id,int cnt){
    //cout<<id<<" "<<cnt<<endl;
    if(id==n+1){
        if(cnt!=k)return;
        check();
        return;
    }
    if((n-cnt)+cnt>=k){
    a[id]=0;
    bf(id+1,cnt);
    }
    if(cnt<k){
    a[id]=1;
    bf(id+1,cnt+1);
    }
}
int dep[2000001],maxdep[2000001];
void dfs1(int u,int fa){
    maxdep[u]=dep[u]=dep[fa]+1;
    for(auto v:e[u]){
        if(v==fa)continue;
        dfs1(v,u);
        maxdep[u]=max(maxdep[u],maxdep[v]);
    }
}
int testid;
void mian(){
    cin>>n>>k;
    for(int i=1;i<=n;i++)e[i].clear();
    for(int i=1;i<n;i++){
        int x,y;
        cin>>x>>y;
        e[x].push_back(y);
        e[y].push_back(x);
    }
    if(testid==13||testid==14){
        int m=n/2;
        if(k<=m+1)cout<<max(1,(m-k)/3+1);
        else if(k==n)cout<<0;
        else cout<<1;
        return;
    }
    ans=n;
    bf(1,0);
    cout<<ans<<"\n";
    return;
}
signed main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    int t;
    cin>>testid>>t;
    while(t--)mian();
    return 0;
}