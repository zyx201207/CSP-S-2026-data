#include <bits/stdc++.h>
using namespace std;
long long c,n,m,d,q,w[5+(int)5e5],a[1005][505],t[505][1005],a1[505][1005],k[505];
long long tu[505][505];
int main(){
    memset(tu,0x3f,sizeof(tu));
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++){
        cin>>w[i];
    }
    for(int i=1;i<=n;i++){
        int k1;
        cin>>k1;
        for(int j=1;j<=k1;j++){
            int x;
            cin>>x>>t[i][x];
            a[x][i]=1;
            a1[i][x]=1;
        }
    }
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            for(int k=1;k<=n;k++){
                if(j==k){
                    tu[k][j]=0;
                }
                if(a1[j][i]&&a1[k][i]&&j!=k){
                    tu[k][j]=tu[j][k]=min(t[j][i]+t[k][i],tu[j][k]);
                }
            }
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            for(int k=1;k<=n;k++){
                tu[j][i]=tu[i][j]=min(tu[i][k]+tu[k][j],tu[j][i]);
            }
        }
    }
    for(int i=1;i<=q;i++){
        int s,e;
        cin>>s>>e;
        long long ans=0x3f3f3f3f3f3f3f3f;
        for(int j=1;j<=n;j++){
            for(int k=1;k<=n;k++){
                    if(a[s][j]&&a[e][k])
                ans=min(ans,tu[j][k]+t[j][s]+t[k][e]);
            }
        }
        cout<<ans+w[s]+w[e]<<endl;
    }
    return 0;
    fclose(stdin);
    fclose(stdout);
}
