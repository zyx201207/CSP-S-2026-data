#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,w[500005],x,y;
struct kate{
    int k1,a[1005],t[1005],z[1005];
}kate k[505];
int bx(int a1,int b){
    int mi=0,tong[1005]={};
    mi+=w[a1]+w[b];
    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            for(int l=1;l<=n;l++){
                if(k[i].z[l]==k[j].z[l]&&k[i].z[l]!=0&&k[i].z[l]!=a1){
                    mi+=k[i].t[l]+k[j].t[l];
                    al=k[i].z[l];
                }
            }
        }
    }
    return mi;
}
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++) cin>>w[i];
    for(int i=1;i<=n;i++){
        cin>>k[i].k1;
        for(int j=1;j<=k[i].k1;j++){
            cin>>k[i].a[j]>>k[i].t[j];
            k[i].z[k[i].a[j]]++;
        }
    }
    for(int i=1;i<=q;i++){
        cin>>x>>y;
        cout<<bx(x,y);
    }
    return 0;
}
