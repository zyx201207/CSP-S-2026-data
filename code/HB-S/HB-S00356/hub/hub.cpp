#include<bits/stdc++.h>
using namespace std;

int c,t;
int n,k;
struct Edge{
    int f,ne,w;
};
struct DSU{
    vector<int> fa,sz;
    DSU(int n){
        fa.resize(n+1);
        sz.assign(n+1,1);
        for(int i=1;i<=n;i++){
            fa[i]=i;
            sz[i]=1;
        }
    }
    int find(int a){
        if(fa[a]==a){
            return a;
        }
        return fa[a]=find(fa[a]);
    }
    bool merge(int a,int b){
        int x=find(a);
        int y=find(b);
        if(x==y){
            return false;
        }
        if(sz[x]>sz[y]){
            fa[y]=x;
            sz[x]+=sz[y];
        }else{
            fa[x]=y;
            sz[y]+=sz[x];
        }
        return true;
    }
};
int main(){
    cin>>c>>t;
    cin>>n>>k;
    vector<Edge> edges(n-1);
    for(int i=0;i<n-1;i++){
        cin>>edges[i].f>>edges[i].ne>>edges[i].w;
    }
    long long ans=0;
    DSU dsu(n);
    for(const Edge& a:edges){
        if(dsu.merge(a.f,a.ne)){
            ans+=1;
        }
    }
    cout<<ans<<endl;
    return 0;
}