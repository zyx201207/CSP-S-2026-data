#include <bits/stdc++.h>
using namespace std;
long long c,n,m,d,q,b=2147483647,d=2147483647;
int w[500005];
int a[505][500005][7];
int x[100005][7];
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","r",stdout);
    cin>>c>>n>>m>>d>>q;
    for (int i=1;i<=n;i++){
        for (int j=1;j<=m;j++){
            cin>>a[i][j][1]>>a[i][j][2];
            a[i][j][3]=-1;
        }
    }
    for (int i=1;i<=q;i++){
        cin>>x[i][1]>>x[i][2];
        for (int j=1;j<=m,j++){
            a[x[i][1]][j][3]=-3;
            a[x[i][2]][j][3]=-2;
        }
        for (int j=1;j<=n;j++){
            for (int k=1;k<=m;k++){
                for (int l=1;l<=m;l++){
                    if (a[j][k][3]+a[j][l][3])==-5){
                        b=a[j][k][2]+a[j][l][2];
                    }
                    else if ((a[j][k][3]==-1&&a[j][l][3]!=-1)&&a[j][l][3]!l){
                        if (a[j][l][3]!=-2) b=a[j][k][2]+a[j][l][2];
                        else  a[j][l][3]=a[j][k][2]+a[j][l][2];
                    }
                if (b<d) d=b;
                }
            }
        }
        cout<<d<<endl;
        b=2147483647,d=2147483647;
    }
    return 0;
}
