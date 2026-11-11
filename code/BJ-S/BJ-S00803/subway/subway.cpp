#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e5+100;
int z,n,m,d,q,t[N],kx[N],kd[N],f[600][600];
struct node{
    int v,t;
};
vector <node>a[600];
vector <node>b[N];
void flord(){
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(f[i][j]>f[i][k]+f[k][j]){
                    f[i][j]=f[i][k]+f[k][j];
                }
            }
        }
    }

}
signed main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    memset(f,0x3f,sizeof(f));
    cin >> z >> n >> m >> d >> q;
    for(int i=1;i<=m;i++){
        cin >> t[i];
    }
    int o,p;
    for(int i=1;i<=n;i++){
        f[i][i]=0;
        cin >> kx[i];
        for(int j=1;j<=kx[i];j++){
            cin >> o >> p;
            a[i].push_back({o,p});
            b[o].push_back({i,p});
            kd[o]++;
        }
    }
    //for(int i=1;i<=m;i++){
    //    cout << "i:" << i << " ";
    //    for(int j=0;j<b[i].size();j++){
    //        cout << b[i][j].t <<" " << b[i][j].v << "\n";
    //    }
    //}
    for(int i=1;i<=m;i++){
        for(int j=0;j<kd[i];j++){
            for(int k=0;k<kd[i];k++){
                int jt=b[i][j].t,kt=b[i][k].t,jv=b[i][j].v,kv=b[i][k].v;
                if(jv==kv){
                    continue;
                }else{
                    //cout << jv << " " << kv << "\n";
                    f[jv][kv]=min(jt+kt,f[jv][kv]);
                }
            }
        }
    }
    flord();
    while(q--){
       int x,y,min_=1e9;
       cin >> x >> y;
       for(int i=0;i<kd[x];i++){
            for(int j=0;j<kd[y];j++){
                int xv=b[x][i].v,yv=b[y][j].v,xt=b[x][i].t,yt=b[y][j].t;
                min_=min(min_,xt+yt+f[xv][yv]);
            }
       }
        cout << min_+t[x]+t[y]  << "\n";
    }
    //for(int i=1;i<=n;i++){
     //   for(int j=1;j<=n;j++){
    //        cout << f[i][j] << " ";
     //   }
     //   cout << "\n";
    //}
    return 0;
}
