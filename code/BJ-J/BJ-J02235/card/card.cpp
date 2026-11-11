#include<bits/stdc++.h>
using namespace std;
int const N=500005;
int a[N],vis[N][3];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int k=1;k<=m;k++){
            int o=0;
    for(int i=1;i<=n;i++){
            for(int q=1;q<=m;q++){
                vis[q][1]=0;
            }
        for(int j=i;j<=n;j++){
            if(a[i]==k){
                o+=1;
                break;
            }
            if(vis[a[j]][1]==1){
                for(int l=vis[a[j]][2]+1;l<j;l++){
                    vis[a[l]][1]=0;
                }
            }
            vis[a[j]][1]=1;
            vis[a[j]][2]=j;
        }
        if(vis[k][1]==1){
            o+=1;
        }
    }
    cout<<o<<" ";
    }
return 0;
}
