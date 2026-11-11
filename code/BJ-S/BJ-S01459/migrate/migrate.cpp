#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
int n;
int d;
int l[200005];
int fl[305][305];
int fa[305][305];
void sv1(){
    memset(fl,0x3f,sizeof(fl));
    memset(fa,0,sizeof(fa));
    for(int u=1;u<=n;u++){
        for(int v=u+1;v<=n && l[v]-l[u]<=d;v++){
            fl[u][v] = 1;
            fa[u][v] = 1;
        }
    }
    for(int k=1;k<=n;k++){
        for(int u=1;u<k;u++){
            for(int v=k+1;v<=n;v++){
                if(fl[u][v]>fl[u][k]+fl[k][v]){
                    fl[u][v] = fl[u][k]+fl[k][v];
                    fa[u][v] = fa[u][k]*fa[k][v];
                }
                else if(fl[u][v]==fl[u][k]+fl[k][v]){
                    fa[u][v] += fa[u][k]*fa[k][v];
                }
            }
        }
    }
    int ans=0;
    for(int u=1;u<=n;u++){
        for(int v=u+1;v<=n;v++){
            if(fa[u][v]==2){
                ans++;
            }
        }
    }
    cout<<ans<<endl;
}
signed main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int C,T;
    cin>>C>>T;
    while(T--){
        cin>>n>>d;
        for(int i=1;i<=n;i++)
            cin>>l[i];
        if(C<=10){
            sv1();
        }
    }
    return 0;
}
