#include <bits/stdc++.h>
using namespace std;
int w[2000],k[2],a[2][2500],t[2][2500],vis[2000];
int main() {
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    int c,n,m,d,q,cross=-1;
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++){
        cin>>w[i];
    }
    for(int i=1;i<=n;i++){
        cin>>k[i];
        for(int j=1;j<=k[i];j++){
            cin>>a[i][j]>>t[i][j];
            if(vis[a[i][j]]==1){
                cross=a[i][j];
            }
            vis[a[i][j]]=1;
        }
    }
    for(int i=1;i<=q;i++){
        int x,y;
        cin>>x>>y;
        int f1=-1,f2=-1,d1=-1,d2=-1;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=k[i];j++){
                if(a[i][j]==x){
                    f1=i;
                    d1=j;
                }
                if(a[i][j]==y){
                    f2=i;
                    d2=j;
                }
            }
        }
        if(f1==f2){
            cout<<w[x]+w[y]+t[f1][x]+t[f1][y];
        }else{
            cout<<w[x]+w[y]+t[f1][x]+t[f2][y]+t[f1][cross]+t[f2][cross];
        }
    }



    return 0;
}
