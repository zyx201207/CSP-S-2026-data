#include<bits/stdc++.h>
using namespace std;
int n,m,cnt,a[500010],b[500010],vis[500010];
int t[300010];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        cnt=0;
        for(int j=1;j<=n;j++){
            vis[j]=-1;
            b[j]=0;
        }
        for(int j=i;j<=n;j++){
            cnt++;
            if(vis[a[j]]==-1){
                vis[a[j]]=cnt;
                b[cnt]=a[j];
            }else{
                for(int o=vis[a[j]]+1;o<=cnt;o++){
                    vis[b[o]]=-1;
                }
                cnt=vis[a[j]];
            }
        }
        for(int j=1;j<=cnt;j++){
            t[b[j]]++;
        }
    }
    for(int i=1;i<=m;i++){
        cout<<t[i]<<" ";
    }
    return 0;
}
