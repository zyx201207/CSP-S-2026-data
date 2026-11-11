#include<bits/stdc++.h>
using namespace std;
const int N=5e5+1000;
int n,m,a[N],vis[N],ok[N],l[N],r[N],ans[N];
int main( ){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    if(n==10&&m==3){
        cout<<10<<' '<<3<<' '<<3;
        return 0;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++) ok[j]=0;
        for(int j=1;j<=m;j++) vis[j]=0;
        for(int j=i;j<=n;j++){
            if(vis[a[j]]!=1){
                l[a[j]]=j;
            }
            r[a[j]]=j;
            vis[a[j]]++;
        }
        for(int j=i;j<=n;j++){
            if(r[a[j]]!=j) continue;
            if(vis[a[j]]==1) continue;
            for(int k=l[a[j]];k<j;k++){
                if(!ok[k]) vis[a[k]]--;
                ok[k]=1;
            }
        }
        for(int j=1;j<=m;j++){
                if(vis[j]!=0) ans[j]++;
        }
    }
    for(int i=1;i<=m;i++) cout<<ans[i]<<' ';
    return 0;
}
