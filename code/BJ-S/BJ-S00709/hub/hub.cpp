#include<bits/stdc++.h>
using namespace std;
long long c,t,n,k,ji[30],vis[30],nmin[30],ans,vis2[30];
vector<long long>poi[30];
inline void ds(long long now){
    vis[now]=1;
    for(int i=0;i<poi[now].size();i++){
        if(vis[poi[now][i]]==0 && ji[poi[now][i]]==1){
            ds(poi[now][i]);
        }
    }
}
inline void dfs2(long long ff,long long now,long long dis){
    vis2[now]=1;
    if(ji[now]==1){
        nmin[ff]=min(nmin[ff],dis);
        return;
    }
    for(int i=0;i<poi[now].size();i++){
        if(vis2[poi[now][i]]==0){
            dfs2(ff,poi[now][i],dis+1);
        }
    }
}
inline void p(){
    for(int i=1;i<=n;i++)vis[i]=0,nmin[i]=0x3f3f3f3f3f3f3f3f;
    long long jj=0;
    for(int i=1;i<=n;i++){
        if(vis[i]==0 && ji[i]==1){
            ds(i);
            jj++;
        }
    }
    if(jj>2)return;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++)vis2[j]=0;
        dfs2(i,i,0);
    }
    long long xans=0;
    for(int i=1;i<=n;i++){
        xans=max(xans,nmin[i]);
    }
    ans=min(ans,xans);
}
inline void dfs(long long now,long long bl){
    if(now==n){
        if(bl==k)p();
        return;
    }
    ji[now+1]=0;
    dfs(now+1,bl);
    ji[now+1]=1;
    dfs(now+1,bl+1);
    ji[now+1]=0;
}
int main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    scanf("%lld%lld",&c,&t);
    while(t--){
        ans=0x3f3f3f3f3f3f3f3f;
        scanf("%lld%lld",&n,&k);
        for(int i=0;i<=n;i++)poi[i].clear();
        for(int i=1;i<n;i++){
            long long a,b;
            scanf("%lld%lld",&a,&b);
            poi[b].push_back(a);
            poi[a].push_back(b);
        }
        dfs(0,0);
        printf("%lld\n",ans);
    }
    return 0;
}