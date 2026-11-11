#include<bits/stdc++.h>
using namespace std;
struct DSU{
    vector<int> siz,f;
    DSU(int n) siz(n+1,1),f{
        iota(f+1,f+n+1,0);
    }
    int leader(int x){
        if(x!=f[x]) x = f[x] = f[f[x]];
        return x;
    }
    bool merge(int x,int y){
        int fx = leader(x),fy = leader(y);
        if(fx==fy) return false;
        if(fx<fy) swap(fx,fy);
        siz[fx]+=siz[fy];
        f[fy] = fx;
        return true;
    }
    int size(int x){
        return siz[leader(x)];
    }
};
int main(){
    cin>>c>>t;
    while(t--){
        int n,k;
        cin>>n>>k;
        DSU dsu(n);
        for(int i = 1;i<=n;i++){
            int u,v;
            cin>>u>>v;
            merge(u,v);
        }
    }
    return 0;
}
