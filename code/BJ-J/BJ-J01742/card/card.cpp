#include <bits/stdc++.h>
using namespace std;
int n,m,a[500005],sum[300005],vis[300005],now[500005];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++){
        memset(vis,0,sizeof(vis));
        memset(vis,0,sizeof(now));
        for(int j=i;j<=n;j++){
            now[j]=1;
            sum[a[i]]++;
            if(vis[a[j]]>0)
                for(int k=vis[a[j]];k<j;k++){
                    if(now[k]==1){
                        now[k]=0;
                        sum[a[k]]--;
                    }
                }
            vis[a[j]]=j;
        }
    }
    for(int i=1;i<=m;j++) cout<<sum[j]<<" ";
    return 0;
}