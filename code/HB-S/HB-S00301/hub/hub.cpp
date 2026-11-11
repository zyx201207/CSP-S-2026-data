# include <bits/stdc++.h>
using namespace std;
int c,T,n,k,u,v,e[2000][2000],vit[2000];
struct str{
    int d,w;
};
int f(int d){
    //vector <int> lzh;
    //vit[d]=d;
    int mx=0,wz=-1;
    int eti[n+10];
    for(int i=1; i<=n; i++){
        if(e[d][i]>mx) mx=e[d][i],wz=i;
    }
    vit[wz]=d;
    for(int i=1; i<=n; i++){
        if(e[d][i]<e[wz][i]) eti[i]=e[d][i];
        else                 eti[i]=e[wz][i];
    }
    /*
    int kkk=k-2;
    lzh.push_back(d),lzh.push_back(wz);
    while(k>0){
        int mx=0,wz=-1,nu=-1,mn=INT_MAX,wz_mni,wz_mnj,len=lzh.size();
        for(int i=1; i<=n; i++){
            if(eti[i]>mx) mx=eti[i],wz=i;
        }
        mn=mx;
        for(int i=0; i<len; i++){
            int lenlen=g[lzh[i]].size();
            for(int j=0; j<lenlen; j++){
                if(vit[g[lzh[i]][j]]==d) continue;
                if(e[g[lzh[i]][j]][wz]<mn) mn=e[g[lzh[i]][j]][wz],wz_mnj=j,wz_mni=i;
            }
        }
        vit[g[lzh[wz_mni]][wz_mnj]]=d,lzh.push_back(g[lzh[wz_mni]][wz_mnj]);
        for(int i=1; i<=n; i++) eti[i]=min(eti[i],e[g[lzh[wz_mni]][wz_mnj]][i]);
    }
    */
    int wlz=0;
    for(int i=0; i<=n; i++) wlz=max(wlz,eti[i]);
    return wlz;
}
int main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    cin>>c>>T;
    while(T--){
        cin>>n>>k;
        vector <int> g[n+10];
        int vis[n+10]={0};
        for(int i=0; i<=n; i++) vis[i]=0;
        for(int i=1; i<n; i++){
            cin>>u>>v;
            g[u].push_back(v);
            g[v].push_back(u);
        }
        for(int i=1; i<=n; i++){
            queue<str> q;
            q.push({i,0});
            vis[i]=i;
            while(!q.empty()){
                str t=q.front(); q.pop();
                e[t.d][i]=e[i][t.d]=t.w;
                int len=g[t.d].size();
                for(int j=0; j<len; j++){
                    if(vis[g[t.d][j]]==i) continue;
                    q.push({g[t.d][j],t.w+1});
                    vis[g[t.d][j]]=i;
                }
            }
        }
        int ans=INT_MAX;
        for(int i=1; i<=n; i++) ans=min(ans,f(i));
        cout<<ans<<"\n";
    }
    return 0;
}
