#include<bits/stdc++.h>
using namespace std;
long long c,T,n,k,kui=0,L[1000005],maxx=0,ans=0;
bool a[1000005],vis[1000005];
vector<long long>e[1000005];
bool one(long long mask){
    long long res=0;
    while(mask){
        res+=mask%2;
        mask/=2;
    }
    return res==k;
}
void dfs_kuai(long long x,long long Fa){
    vis[x]=1;
    for(auto v:e[x]){
        if(v==Fa||!a[v])continue;
        dfs_kuai(v,x);
    }
}
bool kuai(){
    kui=0;
    for(int i=1;i<=n;i++){
        if(a[i]&&!vis[i]){
            kui++;
            dfs_kuai(i,0);
        }
    }
    return kui<=2;
}
void dfs(long long x,long long Fa,long long r){
    L[x]=min(L[x],r);
    for(auto v:e[x]){
        if(v==Fa||a[v])continue;
        dfs(v,x,r+1);
    }
}
int main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);/*zhushi!!!!!!!!!!!!!*/
    scanf("%lld%lld",&c,&T);

    while(T--){
        ans=1e15;
        scanf("%lld%lld",&n,&k);
        for(int i=1;i<=n-1;i++){
            long long u=0,v=0;
            scanf("%lld%lld",&u,&v);
            e[u].push_back(v);
            e[v].push_back(u);
        }
        for(int i=1;i<(1<<n);i++){
            if(one(i)==1){
                for(int j=0;j<n;j++){
                    if((1<<j)&i){
                        a[j+1]=1;
                    }else a[j+1]=0;
                    L[j+1]=1e15;
                }
                if(kuai()){
                    maxx=0;
                    for(int j=1;j<=n;j++){
                        if(a[j])dfs(j,0,0);
                    }
                    for(int j=1;j<=n;j++)
                        maxx=max(maxx,L[j]);
                    ans=min(ans,maxx);
                }
            }
        }
        printf("%lld\n",ans);
    }
    return 0;
}
