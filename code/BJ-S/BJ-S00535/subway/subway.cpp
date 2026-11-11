#include <bits/stdc++.h>
using namespace std;
int c,n,m,d,q,w[500005],bel[500005],in[3][500005];
inline void slv2(){
    for(int i=1;i<=n;i++){
        int k;
        cin>>k;
        for(int i=1;i<=k;i++){
            int xx;
            cin>>xx;
            bel[xx]+=i;
            cin>>in[i][xx];
        }
    }int minn=998244353;
    for(int i=1;i<=n;i++){
        if(bel[i]==3) minn=min(minn,in[1][i]+in[2][i]);
    }while(q--){
        int x,y;
        cin>>x>>y;
        int ans=0;
        if(bel[x]==3&&bel[y]==3){
            ans=min(min(in[1][x]+in[1][y],in[2][y]+in[2][x]),min(in[1][x]+in[2][y],in[2][x]+in[1][y])+minn)+w[x]+w[y];
            cout<<ans;
        }else if(bel[x]==3){
            ans=min(in[bel[y]][x]+in[bel[y]][y],in[bel[y]%2+1][x]+in[bel[y]][x])+w[x]+w[y];
            cout<<ans;
        }else if(bel[y]==3){
            ans=min(in[bel[x]][x]+in[bel[x]][y],in[bel[x]][x]+in[bel[x]%2+1][y]+minn)+w[x]+w[y];
            cout<<ans;
        }else if(bel[y]==bel[x]){
            cout<<in[bel[x]][x]+in[bel[y]][y]+w[x]+w[y];
        }else cout<<in[bel[x]][x]+in[bel[y]][y]+w[x]+w[y]+minn;
    }
    return;
}
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++) cin>>w[i];
    if(c==20&&c==21){
        slv2();
        return 0;
    }
    return 0;
}