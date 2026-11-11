#include<bits/stdc++.h>
using namespace std;
const int N=500+10;
long long f[N][N];
long long k[N],a[N][N],t[N][N],w[N];

int n,m,d,q,c;
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

    for(int i=0;i<=N-10;i++){
        for(int j=0;j<=N-10;j++){
            f[i][j]=1e9;
            if(i==j) f[i][j]=0;
        }
    }

    for(int i=1;i<=m;i++){
        for(int j=1;j<=m;j++){
            for(int k=1;k<=m;k++){
                f[i][j]=t[i][k]+t[k][j]+w[k];
            }
        }
    }
    /*cout<<"s"<<endl;

    for(int i=1;i<=m;i++){
        for(int j=1;j<=m;j++){
            cout<<f[i][j]<<" ";
        }
        cout<<endl;
    }*/
    while(q--){
        int x,y;
        cin>>x>>y;
        cout<<w[x]+w[y]+f[x][y]<<endl;
    }
    return 0;
}
