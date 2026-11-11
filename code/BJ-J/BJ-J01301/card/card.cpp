#include<bits/stdc++.h>
using namespace std;
int a[500005];
int h[300005];
int vis[300005];
int k[300005];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    int id=1;
    for(int i=1;i<=n;i++){
        for(int j=i;j<=n;j++){
            if(vis[a[j]]==0){
                vis[a[j]]=1;
                k[id]=a[j];
                id++;
            }else{
                while(k[id-1]!=a[j]){
                    id--;
                    vis[k[id]]=0;
                }
            }
        }
        id=1;
        for(int j=1;j<=m;j++){
            if(vis[j]==1){h[j]++;
            vis[j]=0;
            //cout<<j<<' ';
            }
        }
    }
    for(int i=1;i<=m;i++){
        cout<<h[i]<<' ';
    }
    return 0;
}

