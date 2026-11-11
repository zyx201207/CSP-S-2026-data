#include<bits/stdc++.h>
using namespace std;
//#define int long long
int c,n,m,d,q,x,y,u,v,ff;
int w[500100];
int k[510];
int a[510][50010];
int t[510][50010];
int g[50010][20];
bool bk[50010];
struct f{
    int bh;
    int w;
}qu[500100];
int ta,p;
void shf(int bh,int w){
    qu[++ta].bh=bh;
    qu[ta].w=w;
    p=ta;
    while(p!=1&&qu[p].w<qu[p/2].w){
        swap(qu[p],qu[p/2]);
        p/=2;
    }
}
void xiach(){
    swap(qu[1],qu[ta--]);
    p=1;
    while((p*2<=ta&&qu[p*2].w<qu[p].w)||(p*2+1<=ta&&qu[p*2+1].w<qu[p].w)){
        if((p*2+1<=ta&&qu[p*2+1].w<qu[p*2].w)){
            swap(qu[p],qu[p*2+1]);
            p*=2;
            p++;
        }else{
            swap(qu[p],qu[p*2]);
            p*=2;
        }
    }
}
signed main(){
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
            g[a[i][j]][++g[a[i][j]][0]]=i;
        }
    }
    while(q--){
        cin>>x>>y;
        for(int i=1;i<=m;i++){
            bk[i]=0;
        }
        ta=0;
        shf(x,0);
        bk[x]=1;
        while(ta!=0){
            u=qu[1].bh;
            v=qu[1].w;
            if(u==y){
                cout<<v+w[x]+w[y]<<"\n";
                break;
            }
            for(int i=1;i<=g[u][0];i++){
                for(int j=1;j<=k[g[u][i]];j++){
                    if(a[g[u][i]][j]==u){
                        ff=j;
                    }
                }
                for(int j=1;j<=k[g[u][i]];j++){
                    if(bk[a[g[u][i]][j]]){
                        continue;
                    }
                    bk[a[g[u][i]][j]]=1;
                    shf(a[g[u][i]][j],v+t[g[u][i]][j]+t[g[u][i]][ff]);
                }
            }
            xiach();
        }
    }
    return 0;
}
