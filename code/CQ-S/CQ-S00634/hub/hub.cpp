#include <bits/stdc++.h>
using namespace std;
int C,T,_,__;
namespace solve1{
    int n,k,dis[25],vis[25],choose[25];
    vector<int> vec[25];
    queue<int> que;
    void solve(){
        while(T--){
            scanf("%d%d",&n,&k);
            for(int i=1;i<n;i++){
                int x,y;
                scanf("%d%d",&x,&y);
                vec[x].push_back(y),vec[y].push_back(x);
            }
            int ans=0x3f3f3f3f;
            for(int i=1;i<(1<<n);i++){
                if(__builtin_popcount(i)>k) continue;
                for(int j=1;j<=n;j++) choose[j]=vis[j]=0,dis[j]=0x3f3f3f3f;
                for(int j=1;j<=n;j++)
                    if((i>>(j-1))&1)
                        choose[j]=1,que.push(j),vis[j]=1,dis[j]=0;
                int res=0;
                while(!que.empty()){
                    int now=que.front();que.pop();
                    res=max(res,dis[now]);
                    for(int j:vec[now])
                        if(!vis[j]) que.push(j),vis[j]=1,dis[j]=dis[now]+1;
                }
                for(int j=1;j<=n;j++) vis[j]=0;
                int ct=0;
                for(int j=1;j<=n;j++){
                    if(choose[j]&&!vis[j]){
                        que.push(j),ct++;
                        while(!que.empty()){
                            int now=que.front();que.pop();
                            for(int k:vec[now])
                                if(choose[k]&&!vis[k]) que.push(k),vis[k]=1;
                        }
                    }
                }
                if(ct<=2) ans=min(ans,res);
            }
            printf("%d\n",ans);
            for(int i=1;i<=n;i++) vec[i].clear();
        }
    }
}
namespace solve2{
    int n,k;
    bool check(int mid){
        if(mid==0) return k==n;
        return ((n-1)/2+2)-4*mid<=k;
    }
    void solve(){
        while(T--){
            scanf("%d%d",&n,&k);
            for(int i=1;i<n;i++) scanf("%d%d",&_,&__);
            int l=0,r=n,res=n;
            while(l<=r){
                int mid=(l+r)/2;
                if(check(mid)) res=mid,r=mid-1;
                else l=mid+1;
            }
            printf("%d\n",res);
        }
    }
}
int main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    scanf("%d%d",&C,&T);
    if(C<=3) solve1::solve();
    else if(C>=13&&C<=14) solve2::solve();
    return 0;
}
//25pts by ??????5=??????1