#include<bits/stdc++.h>
using namespace std;
long long k=0,head[5009],w[5009],a[5009][5009],t[5009][5009],k1[5009],x[5009],y[5009],z[5009],ww[500090];
struct line{
    int to,w,pre;
};
line b[500009];
void add(int x,int y){
    k++;b[k].to=y;b[k].pre=head[x];head[x]=k;
}
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    long long n,m,d,c,q,ans=0,xz=0,yz=0;cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++){
        cin>>w[i];
    }
    for(int i1=1;i1<=n;i1++){
        cin>>k1[i1];
        for(int i=1;i<=2*k1[i1];i++){
            cin>>a[i1][i]>>t[i1][i];
        }
    }
    /*for(int i=1;i<=q;i++){
        cin>>x[i]>>y[i];while(y[i]-x[i]>0){
                for(int i1=1;i1<=n;i1++){
                for(int j=1;j<=2*k1[i1];j++){
                    ww[i]+=t[i1][j];
                    x[i]++;cout<<x[i];
                }
                }
            }cout<<ww[i]+w[x[i]]+w[y[i]];
        }
        for(int i1=1;i1<=n;i1++){
            for(int j=1;j<=2*k1[i1];j++){
                int qw=i/2+1;
                if(x[i]==a[i1][j]) xz=1;
                if(y[i]==a[i1][j]) yz=1;
            }
        }
        if(xz==1&&yz==1){

.

    long long hs(long long q){
    for(long long i=1;i<=q;i++){
        cin>>x[i]>>y[i];
        z[i]=w[x[i]]+t[x[i]]][x[i]]+w[y[i]];
        return z[i];
    }
}*/

    return 0;
}
