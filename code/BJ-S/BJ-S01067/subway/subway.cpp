//long long
//int          #####
//n=509
//m=500009
//k=m
#include<bits/stdc++.h>
using namespace std;
//------------------in
int c,n,m,d,q,w[500009],k[509],a[509][500009],t[509][50009];
//-------------
vector<int>mp[500009];
int ans;
bool tt[500009];
//-------------
void dfs(int u,int tm,int ed,int fa,int sdf){
    tt[u]=1;
    if(u==ed){
        ans=min(ans,tm);
        tt[u]=0;
        return;
    }
    for(auto i:mp[u]){
        if(i!=fa){
            for(int j=1;j<=k[i];j++){
                int v=a[i][j];
                if(!tt[v]){
                    dfs(v,tm+t[i][u]+t[i][v],ed,i,sdf+1);
                }
            }
        }
    }
    tt[u]=0;
    return;
}
void init(){
    int x,y;
    cin>>x>>y;
    ans=INT_MAX;
    dfs(x,0,y,-1,0);
    cout<<ans+w[x]+w[y]<<endl;
    return;
}
//-------------
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++){
        cin>>w[i];
    }
    for(int i=1;i<=n;i++){
        cin>>k[i];
        for(int j=1;j<=k[i];j++){
            cin>>a[i][j]>>t[i][a[i][j]];
            mp[a[i][j]].push_back(i);
        }
    }
    for(int i=1;i<=q;i++){
        init();
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
