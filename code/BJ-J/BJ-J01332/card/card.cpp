#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[500010],vis[500010],ans[500010];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    bool f=0;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(a[i]==a[i-1]&&i!=1){
            f=1;
        }
    }
    if(f==0){
        cout<<n;
        return 0;
    }
    for(int i=1;i<n;i++){
        for(int j=i;j<=n;j++){
            for(int k=j-1;k>=i;k--){
                if(a[k]==a[j]&&vis[k]==0){
                    vis[k]=vis[j]=1;
                    for(int x=k+1;x<j;x++){
                        vis[x]=1;
                    }
                }
            }
        }
        for(int j=i;j<=m;j++){
            if(vis[j]==0){
                ans[j]++;
            }
        }
        memset(vis,0,sizeof(vis));
    }
    for(int i=1;i<=m;i++){
        cout<<ans[i]<<" ";
    }
    return 0;
}
