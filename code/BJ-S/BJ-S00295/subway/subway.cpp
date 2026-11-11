#include <bits/stdc++.h>
using namespace std;
const int N=500+10;
int len[N][N],w[N];
int lymj,n,m,d,q;

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);

    cin>>lymj>>m>>n>>d>>q;
    memset(len,0x3f,sizeof(len));
    for(int i=1;i<=n;i++) cin>>w[i];
    for(int id=1;id<=m;id++){
        int k;cin>>k;
        int z[N],t[N];
        for(int i=1;i<=k;i++) cin>>z[i]>>t[i];
        for(int i=1;i<=k;i++){
            for(int j=1;j<=k;j++){
                if(z[j]==z[i]) continue;
                len[z[i]][z[j]]=min(len[z[i]][z[j]],t[i]+t[j]);
            }

        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            for(int k=1;k<=n;k++){
                len[i][j]=min(len[i][k]+len[k][j],len[i][j]);
            }
        }
    }
    for(int k=1;k<=n;k++){
        for(int j=1;j<=n;j++){
            for(int i=1;i<=n;i++){
                len[i][j]=min(len[i][k]+len[k][j],len[i][j]);
            }
        }
    }

    while(q--){
        int u,v;
        cin>>u>>v;
        cout<<len[u][v]+w[u]+w[v]<<"\n";
    }
    return 0;

}
