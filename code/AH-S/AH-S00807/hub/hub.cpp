#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    int c,t;
    cin>>c>>t;
    while(t--){
        int n,k;
        cin>>n>>k;
        n+=2;
        int d[n][n]={};
        n-=2;
        for(int i=1;i<=n;i++){
            int u,v;
            cin>>u>>v;
            d[u][v]=d[v][u]=1;
        }
        for(int k=1;k<=n;k++){
            for(int i=1;i<=n;i++){
                for(int j=1;j<=n;j++){
                    d[i][j]=max(d[i][j],d[i][k]+d[k][j]);
                }
            }
        }
        int ans=-1;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                ans=max(ans,d[i][j]);
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
