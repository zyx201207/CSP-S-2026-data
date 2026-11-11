#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
vector<int> G[N];
int n,k,ans=1e9;
int used[N],fa[N],dis[N],dep[N];
int find(int x){
    if(fa[x]==x) return x;
    return fa[x]=find(fa[x]);
}
void merge(int x,int y){
    int fx=find(x),fy=find(y);
    if(fx==fy) return ;
    fa[fx]=fy;
    return ;
}
void DFS2(int u,int fa){
    for(auto v:G[u]){
        if(v==fa) continue;
        if(used[v]) continue;
        dis[v]=min(dis[v],dis[u]+1);
        DFS2(v,u);
    }
    return ;
}
void DFS(int dep,int lst){
    if(dep==k+1){
        for(int i=1;i<=n;i++) fa[i]=i;
        for(int i=1;i<=n;i++){
            if(!used[i]) continue;
            for(auto j:G[i]){
                if(used[j]) merge(i,j);
            }
        }
        int bl_cnt=0;
        for(int i=1;i<=n;i++){
            if(!used[i]) continue;
            if(find(i)==i) bl_cnt++;
        }
        if(bl_cnt>2) return ;
        // for(int i=1;i<=n;i++) cout<<used[i]<<" ";
        // cout<<'\n';
        for(int i=1;i<=n;i++) dis[i]=1e9;
        for(int i=1;i<=n;i++){
            if(used[i]) dis[i]=0,DFS2(i,0);
        }
        int mx=0;
        for(int i=1;i<=n;i++) mx=max(mx,dis[i]);
        // cout<<"mx "<<mx<<endl;
        ans=min(ans,mx);
        return ;
    }
    for(int i=lst+1;i<=n;i++){
        used[i]=1;
        DFS(dep+1,i);
        used[i]=0;
    }
    return ;
}
void find_pos(int u,int fa){
    dep[u]=dep[fa]+1;
    for(auto v:G[u]){
        if(v==fa) continue;
        find_pos(v,u);
    }
    return ;
}
vector<int> vec;
bool get_path(int u,int fa,int ed){
    if(u==ed){
        vec.push_back(u);
        return 1;
    }
    bool fl=0;
    for(auto v:G[u]){
        if(v==fa) continue;
        fl|=get_path(v,u,ed);
    }
    if(fl) vec.push_back(u);
    return fl;
}
void get_mx(int u,int fa,int ed){
    dep[u]=dep[fa]+1;
    for(auto v:G[u]){
        if(v==fa) continue;
        if(v==ed) continue;
        get_mx(v,u,ed);
    }
    return ;
}
int solve(int p1,int p2){
    int tmp=1e9;
    get_mx(vec[p1],0,vec[p2]);
    int cmx=0,cl,cr;
    for(int i=1;i<=n;i++){
        if(dep[i]>cmx) cmx=dep[i],cl=i;
    }
    get_mx(cl,0,vec[p2]);
    cmx=0;
    for(int i=1;i<=n;i++){
        if(dep[i]>cmx) cmx=dep[i];
    }
    tmp=min(tmp,(cmx+1)/2);
    get_mx(vec[p2],0,vec[p1]);
    cmx=0;
    for(int i=1;i<=n;i++){
        if(dep[i]>cmx) cmx=dep[i],cl=i;
    }
    get_mx(cl,0,p1);
    cmx=0;
    for(int i=1;i<=n;i++){
        if(dep[i]>cmx) cmx=dep[i];
    }
    tmp=max(tmp,(cmx+1)/2);
    return tmp;
}
int main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    int id,T;
    cin>>id>>T;
    while(T--){
        ans=1e9;
        cin>>n>>k;
        for(int i=1;i<=n;i++) G[i].clear();
        for(int i=1;i<=n;i++) used[i]=0;
        for(int i=1;i<n;i++){
            int u,v;
            cin>>u>>v;
            G[u].push_back(v),G[v].push_back(u);
        }
        if(n>=100&&k==2){
            int lpos,rpos;
            find_pos(1,0);
            int mx=0;
            for(int i=1;i<=n;i++) dep[i]=0;
            for(int i=1;i<=n;i++){
                if(dep[i]>mx) mx=dep[i],lpos=i;
            }
            for(int i=1;i<=n;i++) dep[i]=0;
            find_pos(lpos,0);
            mx=0;
            for(int i=1;i<=n;i++){
                if(dep[i]>mx) mx=dep[i],rpos=i;
            }
            vec.clear();
            // cout<<lpos<<" "<<rpos<<endl;
            get_path(lpos,0,rpos);
            if(vec.size()%2==0){
                int p1=(vec.size()-1)/2;
                int p2=p1+1;
                // assert(p1>=0);
                // assert(p2>=0);
                ans=solve(p1,p2);
            }
            else{
                int p1=(vec.size()-1)/2;
                int p2=p1+1;
                ans=solve(p1,p2);
                // assert(p1>=0);
                // assert(p2>=0);
                ans=min(ans,solve(p1-1,p2-1));
            }
            continue;
        }
        DFS(1,0);
        cout<<ans<<'\n';
    }
    return 0;
}