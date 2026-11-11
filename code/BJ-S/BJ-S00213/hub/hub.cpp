#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e6+5;
int n,k,dep[N],c,mx[N],T,p[N],m,fa[N],dis[N];
vector<int>g[N];
void init(){
    m=0;
    for(int i=1;i<=n;i++){
        g[i].clear();
        dis[i]=0;
        dep[i]=mx[i]=0;
    }
}
void dfs(int u,int last){
    dep[u]=dep[last]+1;
    fa[u]=last;
    for(auto i:g[u]){
        if(i==last)continue;
        dfs(i,u);
    }
}
void bfs(){
    for(int i=1;i<=m;i++)dis[p[i]]=1;
    queue<int>q;
    for(int i=1;i<=m;i++){
        q.push(p[i]);
        while(!q.empty()){
            int u=q.front();
            q.pop();
            mx[i]=max(mx[i],dis[u]-1);
            for(auto v:g[u]){
                if(dis[v])continue;
                dis[v]=dis[u]+1;
                q.push(v);
            }
        }
        //cout<<p[i]<<" "<<mx[i]<<"\n";
    }
}
bool cmp(pair<int,int>x,pair<int,int>y){
    if(x.first==y.first)return x.second<y.second;
    return x.first>y.first;
}
int pre[N],suf[N];
bool check(int x){
    //cout<<"CK "<<x<<endl;
    vector<pair<int,int> >rg,rl;
    for(int i=1;i<=n;i++){
        int l=max(1,i-(x-mx[i]));
        int r=min(m,i+(x-mx[i]));

        rg.push_back({l,r});
    }
    sort(rg.begin(),rg.end(),cmp);
    int mr=m+1;
    for(auto i:rg){
        if(mr<=i.second)continue;
        mr=min(mr,i.second);
        rl.push_back(i);
    }
    sort(rl.begin(),rl.end());
    int ml=0;mr=m+1;
    for(int i=0;i<rl.size();i++){
        //cout<<"RG "<<rl[i].first<<" "<<rl[i].second<<endl;
        ml=rl[0].second;
        mr=rl[i].first;
        pre[i]=max(1,mr-ml+1);
        //cout<<"PR "<<i<<" "<<pre[i]<<endl;
    }
    ml=0,mr=m+1;
    for(int i=rl.size()-1;i>=0;i--){
        ml=rl[i].second;
        mr=rl[rl.size()-1].first;
        suf[i]=max(1,mr-ml+1);
    }
    int res=suf[0];
    for(int i=0;i<rl.size()-1;i++){
        res=min(res,pre[i]+suf[i+1]);
    }
    //cout<<res<<endl;
    return res<=k;
}
void solve(){
    cin>>n>>k;
    init();
    for(int i=1;i<n;i++){
        int u,v;cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(1,0);
    int u=0,v=0;
    for(int i=1;i<=n;i++){
        if(dep[i]>dep[u])u=i;
    }
    dfs(u,0);
    for(int i=1;i<=n;i++){
        if(dep[i]>dep[v])v=i;
    }
    for(int i=v;i;i=fa[i]){
        p[++m]=i;
        if(i==u)break;
    }
    bfs();
    int l=0,r=n,mid,ans;
    while(l<=r){
        mid=(l+r)>>1;
        if(check(mid)){
            ans=mid;
            r=mid-1;
        }
        else l=mid+1;
    }
    cout<<ans<<"\n";
}
int main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    cin>>c>>T;
    while(T--)solve();
    return 0;
}