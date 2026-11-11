#include<bits/stdc++.h>
using namespace std;
long long h[500005],vtx[500005],nxt[500005],wt[500005],idx;
void add(long long a,long long b,long long c){
    vtx[idx]=b;
    wt[idx]=c;
    nxt[idx]=h[a];
    h[a]=idx;
    idx++;
}
struct z{
    int u,v,w;
    bool operator<(z a) const{
        return a.w<w;
    }
};
long long c,t,n,d,a[2000005],m,dis[200005],cnt[200005],ans;
bool vis[200005];
priority_queue<z> q;
void dij(long long s){
    z tmp;
    tmp.u=s;
    tmp.v=s;
    tmp.w=0;
    q.push(tmp);
    while(!q.empty()){
        tmp=q.top();
        q.pop();
        long long nid=tmp.v;
        if(vis[nid]==1){
            continue;
        }
        vis[nid]=1;
        long long p=h[nid];
        while(p!=-1){
            if(vis[vtx[p]]==0){
                if(dis[vtx[p]]>=dis[nid]+wt[p]){
                    dis[vtx[p]]=dis[nid]+wt[p];
                    tmp.u=nid;
                    tmp.v=vtx[p];
                    tmp.w=dis[vtx[p]];
                    q.push(tmp);
                }
            }
            p=nxt[p];
        }
    }
}
void dfs(int s,int len){
    if(len>0&&len==dis[s]){
        cnt[s]++;
    }
    long long p=h[s];
    len++;
    while(p!=-1){
        dfs(vtx[p],len);
        p=nxt[p];
    }
}
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>c>>t;
    while(t--){
        cin>>n>>d;
        m=0;
        ans=0;
        memset(h,-1,sizeof(h));
        memset(vtx,0,sizeof(vtx));
        memset(vtx,0,sizeof(nxt));
        for(int i=1;i<=n;i++){
            cin>>a[i];
        }
        for(int i=1;i<n;i++){
            for(int j=i+1;j<=n;j++){
                if(a[j]-a[i]<=d){
                    add(i,j,1);
                }else{
                    break;
                }
            }
        }
        for(int i=1;i<=n;i++){
            for(int j=i;j<=n;j++){
                dis[j]=1e9;
            }
            dis[i]=0;
            memset(cnt,0,sizeof(cnt));
            memset(vis,0,sizeof(vis));
            dij(i);
            dfs(i,0);
            for(int j=i+1;j<=n;j++){
                if(cnt[j]==2){
                    ans++;
                }
            }
        }
        cout<<ans<<"\n";
    }
    return 0;
}
