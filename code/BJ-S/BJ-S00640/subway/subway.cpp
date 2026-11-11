#include<bits/stdc++.h>
using namespace std;
const int N=1026;
int e[N][N],w[N];
int c,n,m,d,q;
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    memset(e,0x3f,sizeof(e));
    for(int i=1;i<=m;i++){
        cin>>w[i];
        e[i][i]=0;
    }
    for(int i=1;i<=n;i++){
        int k;
        cin>>k;
        if(k==2){
            int a1,a2,a3,a4;
            cin>>a1>>a2>>a3>>a4;
            e[a1][a3]=e[a3][a1]=a2+a4;
        }else{
            for(int j=1;j<=k;j++){
                int x,z;
                cin>>x>>z;
            }
        }
    }
    for(int k=1;k<=m;k++){
        for(int i=1;i<=m;i++){
            for(int j=1;j<=m;j++){
                if(e[i][k]+e[k][j]<e[i][j]){
                    e[i][j]=e[i][k]+e[k][j];
                }
            }
        }
    }
    while(q--){
        int x,y;
        cin>>x>>y;
        if(x>y) swap(x,y);
        cout<<e[x][y]+w[x]+w[y]<<endl;
    }
    return 0;
}
