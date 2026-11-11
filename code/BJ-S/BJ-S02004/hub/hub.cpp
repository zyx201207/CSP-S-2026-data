#include <bits/stdc++.h>
using namespace std;
int n,m,S,T;
vector <int> vc[1000010];
int cnt[1000010];
int dis[1000010],fa[1000010],vis0[1000010],vis1[1000010];
vector <int> mem;
void dfs(int id,int f){
    dis[id]=dis[f]+1; fa[id]=f;
    mem.push_back(id);
    for (auto x:vc[id]){
        if (x==f) continue;
        if (id==S&&x==T) continue;
        dfs(x,id);
    }
}
void dfs2(int id,int f,int col){
    dis[id]=0;
    for (auto x:vc[id]){
        if (x==f) continue;
        if (id==S&&x==T) continue;
        dfs2(x,id,col);
        dis[id]=max(dis[id],dis[x]+1);
    }
    cnt[dis[id]]++;
    if (col) vis1[dis[id]]++;
    else vis0[dis[id]]++;
}
void adda(int id,int f){
    cnt[dis[id]]--;
    cnt[dis[id]+1]++;
    for (auto x:vc[id]){
        if (x==f) continue;
        if (id==S&&x==T) continue;
        adda(x,id);
    }
}
void add(int u,int v){
    mem.clear();
    S=u,T=v;
    dfs(u,0);
    int ls=0;
    for (auto x:mem){
        if (dis[x]>dis[ls]) ls=x;
    }
    dfs(ls,0);
    int rs=0;
    for (auto x:mem){
        if (dis[x]>dis[rs]) rs=x;
    }
    vector <int> zj;
    while (true){
        zj.push_back(rs);
        if (ls==rs) break;
        rs=fa[rs];
    }
    dfs2(zj[zj.size()/2],0,(S<T));
}
int main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int c,t; cin>>c>>t;
    while (t--){
        cin>>n>>m;
        for (int i=1; i<=n; i++) vc[i].clear();
        for (int i=1; i<n; i++){
            int u,v; cin>>u>>v;
            vc[u].push_back(v);
            vc[v].push_back(u);
        }
        S=0,T=0;
        dfs(1,0);
        int ls=0;
        for (int i=1; i<=n; i++){
            if (dis[i]>dis[ls]) ls=i;
        }
        dfs(ls,0);
        int rs=0;
        for (int i=1; i<=n; i++){
            if (dis[i]>dis[rs]) rs=i;
        }
        vector <int> zj;
        while (true){
            zj.push_back(rs);
            if (ls==rs) break;
            rs=fa[rs];
        }
        int mid=zj.size()/2;
        int mn=n+10;
        if (c<=10){
            for (int u=1; u<=n; u++){
                for (auto v:vc[u]){
                    if (u<v){
                        for (int i=0; i<=n; i++) cnt[i]=0,vis0[i]=0,vis1[i]=0;
                        add(u,v); add(v,u);
                        int sum=0,ok0=0,ok1=0;
                        for (int i=n; i>=0; i--){
                            sum+=cnt[i]; ok0|=vis0[i]; ok1|=vis1[i];
                            if (sum<m||sum==m&&ok1&&ok0) mn=min(mn,i);
                            //cout<<u<<" "<<v<<" "<<i<<" "<<cnt[i]<<"\n";
                        }
                    }
                }
            }
        }
        else{
            for (int i=max(0,mid-5); i<=min((int)zj.size()-2,mid+5); i++){
                for (int j=0; j<=n; j++) cnt[j]=0,vis0[j]=0,vis1[j]=0;
                add(zj[i],zj[i+1]); add(zj[i+1],zj[i]);
                int sum=0,ok0=0,ok1=0;
                for (int j=n; j>=0; j--){
                    sum+=cnt[j]; ok0|=vis0[j]; ok1|=vis1[j];
                    if (sum<m||sum==m&&ok1&&ok0) mn=min(mn,j);
                }
            }

        }
        cout<<mn<<"\n";
    }
}
