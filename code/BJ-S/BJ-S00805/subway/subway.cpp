#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int h[N],h2[N],c,a[4][N],n,w[N],m,mi=2e9+10,d,q;
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++){
        scanf("%d",&w[i]);//每个地铁站的地铁口走到站厅时间
    }
  //  if(c==20||c==21){
        for(int i=1;i<=n;i++){
            int k;
            cin>>k;
            if(i==2){
                while(k--){
                    scanf("%d",&a[2][i]);//经过的地铁站2
                    scanf("%d",&a[3][a[2][i]]);//每条线路到站台需要的时间2
                    h2[a[2][i]]=1;
                }
                continue;
            }
            while(k--){
                scanf("%d",&a[0][i]);//经过的地铁站
                scanf("%d",&a[1][a[0][i]]);//每条线路到站台需要的时间
                h[a[0][i]]=1;
            }
        }
        for(int i=1;i<=m;i++){
            if((h2[i]==1)&&(h[i]==1)){
                mi=min(mi,a[1][i]+a[3][i]);
            }
        }
        while(q--){
            int x,y;
            scanf("%d%d",&x,&y);
            if(h[x]&&h[y]){
                cout<<w[x]+w[y]+a[1][x]+a[1][y]<<'\n';
            }else if(h2[x]&&h2[y]){
                cout<<w[x]+w[y]+a[3][x]+a[3][y]<<'\n';
            }else{
                if(h[x]==1)cout<<w[x]+w[y]+mi+a[1][x]+a[3][y]<<'\n';
                else cout<<w[x]+w[y]+mi+a[3][x]+a[1][y]<<'\n';
            }
        }
  //  }
    return 0;
}
