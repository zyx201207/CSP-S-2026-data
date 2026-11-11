#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,p;
int djs[505][505],w[505],h[505][505];
int main(){
    memset(h,-1,sizeof(h));
    cin>>c>>n>>m>>d>>p;
    for(int i=1;i<=m;i++){
        cin>>w[i];
    }
    for(int i=1;i<=n;i++){
        int a;
        cin>>a;
        int l[505];
        for(int j=1;j<=a;j++){
            cin>>l[j];
        }
        for(int j=1;j<=a;j++){
            for(int k=1;k<=a;k++){
                h[l[j]][l[k]]=h[l[k]][l[j]]=0;
            }
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(i==j)djs[i][j]=0;
            else{
                
            }
        }
    }
return 0;
}