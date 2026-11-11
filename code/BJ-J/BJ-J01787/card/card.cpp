#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m;
    cin>>n>>m;
    int a[n+1];
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    int b[n+5]={};
    int c[n+1][m+1]={};
    for(int j=1;j<=n;j++){
        b={};
        for(int k=j;k<=n;k++){
            int r=0,e;
            int d[n+1]={};
            for(int l=1;l<=k-1;l++){
                if(b[l]==a[k]){
                    r=1;
                    e=l;
                    break;
                }
                d[l]=b[l];
            }
            b={};
            if(r==0){
                b[k]=a[k];
            }else{
                for(int l=1;l<=e-1;l++){
                    b[l]=d[l];
                }
                b[k]=a[k];
            }
        }
        for(int i=1;i<=n;i++){
            if(b[i]<=m){
                c[j][b[i]]=1;
            }
        }
    }
    int f[m+1]={};
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            f[i]+=c[i][j];
        }
        cout<<f[i]<<' ';
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}