#include<iostream>
#include<cstdio>
#include<vector>
#include<cstring>
using namespace std;
int n,m,sum[300005];
int a[500005];
int vis[300005];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }for(int i=1;i<=n;i++){
        for(int j=i;j<=n;j++){
            if(vis[a[j]]){
                for(int k=vis[a[j]];k<=j;k++){
                    vis[a[k]]=0;
                }vis[a[j]]=0;
            }vis[a[j]]=j;
        }for(int j=1;j<=m;j++){
            sum[j]+=(vis[j]!=0);
        }memset(vis,0,sizeof(vis));
    }for(int i=1;i<=m;i++){
        cout<<sum[i]<<" ";
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
