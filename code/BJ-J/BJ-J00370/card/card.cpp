#include <bits/stdc++.h>
using namespace std;
int a[500005],vis[500005],ans[300005];
int main() {
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    int t=0;
    for(int t=1;t<=n;t++){
        memset(vis,0,sizeof(vis));
        for(int i=t;i<=n;i++){
            vis[i]=1;
            int place=-1;
            for(int j=i-1;j>=1;j--){
                if(a[j]==a[i] && vis[j]==1){
                    place=j;
                    break;
                }
            }
            if(place!=-1){
                for(int j=place;j<i;j++){
                    vis[j]=0;
                }
            }
        }
        for(int i=1;i<=n;i++){
            if(vis[i]==1) ans[a[i]]++;
        }
    }
    for(int i=1;i<=m;i++){
        cout<<ans[i]<<" ";
    }


    return 0;
}
