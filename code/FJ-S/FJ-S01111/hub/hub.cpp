#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e6+3;
int oc,T,n,k,h,d1[N],d[N],m1,m2,fa[N],z[N],g,s;
vector<int>e[N];
void dfs1(int u,int fu){
    if(d1[u]>d1[m1])m1=u;
    for(int v:e[u])if(v!=fu)d1[v]=d1[u]+1,dfs1(v,u);
}
void dfs2(int u,int fu){
    if(d[u]>d[m2])m2=u;fa[u]=fu;
    for(int v:e[u])if(v!=fu)d[v]=d[u]+1,dfs2(v,u);
}
void dfs(int u,int fu){
    z[u]=1;fa[u]=fu;
    for(int v:e[u])if(v!=fu)dfs(v,u),z[u]=max(z[u],z[v]+1);
}
void df(int u,int x){
    ++s;
    for(int v:e[u])if(z[v]>x&&v!=fa[u]&&v!=g)df(v,x);
}
bool chk(int x){
    int t1=m1,t2=m2;s=0;
    for(int i=1;i<=x;i++)t1=fa[t1],t2=fa[t2];
    g=t1;t1=fa[t1];
    while(t1!=h){
        df(t1,x);
        g=t1;t1=fa[t1];
    }
    g=t2;t2=fa[t2];
    while(t2!=h){
        df(t2,x);
        g=t2;t2=fa[t2];
    }
    return (s<=x);
}
int main(){
    cin.tie(0)->sync_with_stdio(0);
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    cin>>oc>>T;
    while(T--){
        cin>>n>>k;
        for(int i=1;i<=n;i++)d1[i]=d[i]=z[i]=0,e[i].clear();
        for(int i=1;i<n;i++){
            int u,v;cin>>u>>v;
            e[u].push_back(v);e[v].push_back(u);
        }
        m1=m2=0;dfs1(1,0);dfs2(m1,0);
        int l=0,r=d[m2]/2;h=m2;
        while(d[h]>r)h=fa[h];
        dfs(h,h);
        while(l<r){
            int mid=(l+r)>>1;
            if(chk(mid))r=mid;
            else l=mid+1;
        }
        cout<<r<<'\n';
    }
    return 0;
}