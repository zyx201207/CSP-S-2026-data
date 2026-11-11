#include<bits/stdc++.h>
using namespace std;
struct tree{
    vector<int>G[100005];
    int rt,n,dep[100005],mxdep[100005],fa[100005];
    void init(int n_){
        n=n_;
        for(int i=1;i<=n;i++){
            G[i].clear();
            dep[i]=mxdep[i]=fa[i]=0;
        }
    }
    void addedge(int u,int v){
        G[u].push_back(v);
        G[v].push_back(u);
    }
    void dfs(int u,int f){
        fa[u]=f;
        for(auto d:G[u])
            if(d!=f){
                dep[d]=dep[u]+1;
                dfs(d,u);
            }
    }
    void dfs1(int u,int f){
        fa[u]=f;
        mxdep[u]=dep[u];
        for(auto d:G[u])
            if(d!=f){
                dep[d]=dep[u]+1;
                dfs1(d,u);
                mxdep[u]=max(mxdep[u],mxdep[d]);
            }
    }
    int findcentre(){
        dep[rt]=0,fa[rt]=0;
        dfs(rt,0);
        int r1=0,r2=0;
        for(int i=1;i<=n;i++)
            if(dep[i]>dep[r1]) r1=i;
        dep[r1]=0,fa[r1]=0;
        dfs(r1,0);
        for(int i=1;i<=n;i++)
            if(dep[i]>dep[r2]) r2=i;
        int ct=r2;
        while(dep[ct]>dep[r2]/2) ct=fa[ct];
        dep[ct]=fa[ct]=0;
        dfs1(ct,0);
        return ct;
    }
    void check(int u,int k,int&ans){
        if(mxdep[u]-dep[u]>=k) ans++;
        else return;
        for(auto d:G[u])
            if(d!=fa[u]) check(d,k,ans);
    }
}tr[2];
int t,c,n,k,u,v,ans;
vector<int>G[1000005];
void dfsg(int u,int f,int x){
    for(auto d:G[u])
        if(d!=f){
            tr[x].addedge(u,d);
            dfsg(d,u,x);
        }
}
void split(int u,int v){
    tr[0].init(n),tr[1].init(n);
    dfsg(u,v,0);
    dfsg(v,u,1);
    tr[0].rt=u,tr[1].rt=v;
    tr[0].rt=tr[0].findcentre(),tr[1].rt=tr[1].findcentre();
    int l=1,r=n;
    while(r-l>3){
        int mid=(l+r)>>1,c1=0,c2=0;
        tr[0].check(tr[0].rt,mid,c1),tr[1].check(tr[1].rt,mid,c2);
        if(max(c2,1)+max(c1,1)<=k) r=mid;
        else l=mid;
    }
    for(int mid=l;mid<=r;mid++){
        int c1=0,c2=0;
        tr[0].check(tr[0].rt,mid,c1),tr[1].check(tr[1].rt,mid,c2);
        if(max(c2,1)+max(c1,1)<=k){
            ans=min(ans,mid);
            break;
        }
    }
}
void dfs(int u,int f){
    if(f!=0) split(u,f);
    for(auto d:G[u])
        if(d!=f) dfs(d,u);
}
int main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>c>>t;
    while(t--){
        if(c<=10){
            cin>>n>>k;
            for(int i=1;i<=n;i++) G[i].clear();
            tr[0].init(n);
            ans=1e9;
            for(int i=1;i<n;i++){
                cin>>u>>v;
                G[u].push_back(v);
                G[v].push_back(u);
            }
            dfsg(1,0,0);
            tr[0].rt=1;
            tr[0].rt=tr[0].findcentre();
            int l=1,r=n;
            while(r-l>3){
                int mid=(l+r)>>1,c1=0;
                tr[0].check(tr[0].rt,mid,c1);
                if(max(c1,1)<=k) r=mid;
                else l=mid;
            }
            for(int mid=l;mid<=r;mid++){
                int c1=0;
                tr[0].check(tr[0].rt,mid,c1);
                if(max(c1,1)<=k){
                    ans=min(ans,mid);
                    break;
                }
            }
            dfs(1,0);
            cout<<ans<<"\n";
        }else if(13<=c&&c<=14){
            cin>>n>>k;
            ans=1e9;
            for(int i=1;i<=n;i++) G[i].clear();
            for(int i=1;i<n;i++){
                cin>>u>>v;
                G[u].push_back(v);
                G[v].push_back(u);
            }
            int med=(n/2)/2;
            for(int i=med-1;i<=med+1;i++)
                if(i>=1) split(i,i-1);
            cout<<ans<<endl;
        }
    }
    return 0;
}