#include<bits/stdc++.h>
using namespace std;
int c,m,n,k[505],a[505][500005],d,q,x,y;
long long w[500005],t[505][500005],ans;
long long z[500005][500005],ti[500005][500005];
int f(int u,int v){
    /*
    long long h[500005];
    for(int i=1;i<=m;i++){
        h[i]=INT_MAX;
    }
    */
    if(z[u][v]!=-1){
        return z[u][v];
    }
    if(u==v){
        return z[u][v]=0;
    }
    long long mb=0,mn=INT_MAX;
    for(int i=1;i<=m;i++){
        if(i!=u&&ti[u][i]!=INT_MAX){
            if(ti[u][i]<mn){
                mn=ti[u][i];
                mb=i;
            }
        }
    }
    return z[u][v]=f(mb,v)+mn;
    /*
    int s=u;
    for(int j=1;j<m;j++){
        for(int i=1;i<=m;i++){
            int mn=0,mb=0;
            if(i!=s&&ti[s][i]!=INT_MAX){
                h[i]=min(ti[s][i],h[i]);
                if(h[i]<mn){
                    mn=h[i];
                    mb=i;
                }
            }
            if(mb==0){
                break;
            }
            z[s][mb]=mn;
            s=mb;
        }
    }
    */
}
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    for(int i=1;i<=m;i++){
        for(int j=1;j<=m;j++){
            z[i][j]=-1;
            ti[i][j]=INT_MAX;
        }
    }
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++){
        cin>>w[i];
    }
    for(int i=1;i<=n;i++){
        cin>>k[i];
        for(int j=1;j<=k[i];j++){
            cin>>a[i][j]>>t[i][j];
            for(int k=i;k<j;k++){
                if(a[i][j]+a[i][k]<ti[k][j]){
                    ti[k][j]=a[i][j]+a[i][k];
                }
            }
        }
    }
    for(int i=1;i<=q;i++){
        cin>>x>>y;
        ans=w[x]+w[y];
        cout<<ans+f(x,y);
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
