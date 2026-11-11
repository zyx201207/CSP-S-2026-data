#include<iostream>
using namespace std;
int c,n,m,d,q,k[505],w[505],a[505][505],t[505][505];
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++){
        cin>>w[i];
    }
    for(int i=1;i<=n;i++){
        cin>>k[i];
        for(int j=1;j<=k[i];j++){
            cin>>a[i][j];
            cin>>t[i][j];
        }
    }
    for(int i=1;i<=q;i++){
        int x,y,l,r,l2,r2;
        cin>>x>>y;
        for(int g=1;g<=n;g++){
            for(int h=1;h<=k[i];h++){
                if(a[g][h]==x){
                    l=g;
                    r=h;
                }
                if(a[g][h]==y){
                    l2=g;
                    r2=h;
                }
            }
        }
        cout<<w[x]+t[l][r]+t[l2][r2]+w[y]<<"\n";
    }
    return 0;
}
