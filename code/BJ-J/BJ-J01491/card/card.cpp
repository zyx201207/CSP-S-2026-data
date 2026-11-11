#include <bits/stdc++.h>
using namespace std;
int n,m,a[200005],vis[200005],ans[200005],jlid[200005];

int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        vis[i]=1;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            jlid[j]=0x3f3f3f3f;
        }
        for(int j=i;j<=n;j++){
            vis[j]=1;
        }
        for(int j=1;j<=n;j++){
            jlid[a[j]]=min(jlid[a[j]],j);
        }
        for(int l=i;l<=n;l++){
            int k=jlid[a[l]];
                if(l!=k&&vis[k]==1){
                    for(int j=k;j<=l-1;j++){
                       vis[j]=0;
                    }
                }
            jlid[a[l]]=l;
        }
        for(int l=i;l<=n;l++){
            if(vis[l]) ans[a[l]]++;
        }
    }
    for(int i=1;i<=m;i++){
        cout<<ans[i]<<' ';
    }

    return 0;
}//just10minutes
