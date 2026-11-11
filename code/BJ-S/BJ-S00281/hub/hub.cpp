#include <bits/stdc++.h>
using namespace std;
int u[1005],d[1005][1005],n,m,cur=0,ans;
bool sl[1005];
vector<int> l[1005];
void dfs(int p,int c){
    if(!sl[p]||u[p])return;
    u[p]=c;
    for(int i=0;i<l[p].size();++i){
        dfs(l[p][i],c);
    }
}
void dfs2(int p,int t){
    if(p>n){
        int xn=0;
        for(int i=1;i<=n;++i)u[i]=0;
        cur=0;
        for(int i=1;i<=n;++i){
            if(!sl[i]||u[i])continue;
            dfs(i,++cur);
        }
        if(cur>2)return;
        for(int i=1;i<=n;++i){
            int nn=0x3f3f3f3f;
            for(int j=1;j<=n;++j){
                if(sl[j])nn=min(nn,d[i][j]);
            }
            xn=max(xn,nn);
        }
        ans=min(ans,xn);
        return;
    }
    if(n-p>=m-t){
        sl[p]=0;
        dfs2(p+1,t);
    }
    if(t<m){
        sl[p]=1;
        dfs2(p+1,t+1);
    }
}
int main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    int id,t;scanf("%d%d",&id,&t);
    for(int _=1;_<=t;++_){
        memset(d,0x3f,sizeof(d));
        scanf("%d%d",&n,&m);
        queue<int> q;
        ans=0x3f3f3f3f;
        for(int i=1;i<=n;++i)l[i].clear();
        for(int i=1;i<n;++i){
            int x,y;scanf("%d%d",&x,&y);
            l[x].push_back(y);
            l[y].push_back(x);
        }
        for(int i=1;i<=n;++i){
            d[i][i]=0;
            q.push(i);
            while(!q.empty()){
                int o=q.front();
                q.pop();
                for(int j=0;j<l[o].size();++j){
                    if(d[i][l[o][j]]<=d[i][o]+1)continue;
                    d[i][l[o][j]]=d[i][o]+1;
                    q.push(l[o][j]);
                }
            }
        }
        dfs2(1,0);
        printf("%d\n",ans);
    }
    return 0;
}
