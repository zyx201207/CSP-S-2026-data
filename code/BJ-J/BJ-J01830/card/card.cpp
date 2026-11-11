#include<bits/stdc++.h>
using namespace std;
long long n,m,a[50005],r[50005],ans[50005];
struct N{
        bool y=0;
        long long p=0;
}vis[30005];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(long long i=1;i<=n;i++){
        cin>>a[i];
    }
    for(long long i=1;i<=n;i++){
            long long b=1;
        for(long long j=i;j<=n;j++,b++){
            long long k=a[j];
            if(vis[k].y==1){
                b=vis[k].p;
                for(int o=1+vis[k].p;o<=n;o++){
                    vis[r[o]].p=0,vis[r[o]].y=0,r[o]=0;
                }
            }else{
                r[b]=k,vis[k].y=1,vis[k].p=b;
            }
        }
        for(int j=1;j<=m;j++){
            if(vis[j].y==1){
                ans[j]++;
            }
        }
        memset(r,0,sizeof(r));
        memset(vis,0,sizeof(vis));
    }
    for(int i=1;i<=m;i++){
        cout<<ans[i]<<" ";
    }
    return 0;
}
