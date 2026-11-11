#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,w[500005],a[500005],t[500005],k;
int v[10000][10000];
int hjm(int x,int y){
    int z[m+5]={0};
    bool e[m+5]={0};
    e[x]=1;
    for(int i=1;i<=m;i++){
        if(v[x][i]==0){
            z[i]=0x3f3f3f3f;
            continue;
        }
        z[i]=v[x][i];
    }
    while(1){
        int k=0x3f3f3f3f,minn=0x3f3f3f3f;
        for(int j=1;j<=m;j++){
            //cout<<e[j]<<endl;
            if(e[j]==1) continue;
            if(z[j]<minn){
                minn=z[j];
                k=j;
            }
        }
        if(k==0x3f3f3f3f) break;
        e[k]=1;
        for(int j=1;j<=m;j++){
            if(e[j]==1) continue;
            if(v[k][j]==0) continue;
            z[j]=min(z[j],z[k]+v[k][j]);
        }
    }
    return z[y];
}
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++){
        cin>>w[i];
    }
    for(int i=1;i<=n;i++){
        cin>>k;
        for(int j=1;j<=k;j++){
            cin>>a[j]>>t[j];
        }
        for(int j=1;j<=k;j++){
            for(int h=j+1;h<=k;h++){
                v[a[h]][a[j]]=v[a[j]][a[h]]=t[j]+t[h];
            }
        }
    }
    for(int i=1;i<=q;i++){
        int x=0,y=0;
        cin>>x>>y;
        cout<<hjm(x,y)+w[x]+w[y]<<endl;
    }
    return 0;
}
