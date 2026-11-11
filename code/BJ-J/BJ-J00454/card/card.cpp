#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],ans[500005],sum[300005],len=0;
bool vis[300005];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];
    for(int i=1;i<=n;i++){
        len=0;
        memset(vis,false,sizeof(vis));
        for(int j=i;j<=n;j++){
            if(vis[a[j]]){
                for(int d=1;d<=len;d++){
                    if(ans[d]==a[j]){
                        for(int k=d;k<=len;k++)vis[ans[k]]=false;
                        len=d;
                        break;
                    }
                }
            }else len++,ans[len]=a[j],vis[a[j]]=true;
        }
        for(int d=1;d<=len;d++)sum[ans[d]]++;
    }
    for(int i=1;i<=m;i++)cout<<sum[i]<<" ";
    return 0;
}
