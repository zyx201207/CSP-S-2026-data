#include<bits/stdc++.h>
using namespace std;
int n,m,a[1000000],vis[1000000],cur[1000000],ans[1000000];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];
    for(int i=1;i<=n;i++){
            int cnt=0;
        memset(vis,0,sizeof(vis));
        memset(cur,0,sizeof(cur));
        for(int j=i;j<=n;j++){
            if(vis[a[j]]){
                for(int k=vis[a[j]];k<=j;k++){
                    vis[cur[k]]=0;
                    cur[k]=0;
                }
                cur[j]=a[j];
                vis[a[j]]=j;
            }else{
                cur[++cnt]=a[j];
                vis[a[j]]=j;
            }
        }
        for(int j=1;j<=m;j++)if(vis[j])ans[j]++;
    }
    for(int i=1;i<=m;i++)cout<<ans[i]<<" ";
}
