#include<bits/stdc++.h>
using namespace std;
int g,b,c,n,m,d,q,w[500005],k[505],a[505][500005],t[505][500005],x[100005],y[100005];
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
            cin>>a[i][j]>>t[i][j];
        }
    }
    for(int i=1;i<=q;i++){
        cin>>x[i]>>y[i];
    }
    if(c==1||c==2||c==3||c==4||c==5||c==6){
        for(int z=1;z<=q;z++){
            b=w[x[z]];
                for(int i=1;i<=n;i++){
                    for(int j=1;j<=k[i];j++){
                        if(x[z]==a[i][j]){
                            b+=t[i][j];
                            g=10;
                            break;
                        }
                    }
                    if(g==10){
                        break;
                    }
                }
                g=0;
            cout<<b+w[y[z]]<<endl;
        }
        return 0;
    }
    if(c==7||c==8||c==9||c==10||c==11){
        for(int z=1;z<=q;z++){
            b=w[x[z]];
            for(int i=1;i<=n;i++){
                for(int j=1;j<=k[i];j++){
                    if(x[z]==a[i][j]){
                        b+=t[i][j];
                    }
                }
            }
            cout<<b+w[y[z]]<<endl;
        }
    }
    return 0;
}
