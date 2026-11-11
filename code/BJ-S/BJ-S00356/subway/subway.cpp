#include<bits/stdc++.h>
using namespace std;
#define int long long
#define pii pair<int,int>
#define fi first
#define se second
inline int rd(){
    char c='?';
    int res=0;
    while(!isdigit(c)){
        c=getchar_unlocked();
    }
    while(isdigit(c)){
        res=res*10+c-'0';
        c=getchar_unlocked();
    }
    return res;
}
int w[500001];
vector<pii> sw[500001];
int ins[501][501];
int f[501][501];
inline void floyd(int n){
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            f[i][j]=ins[i][j];
        }
    }
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
            }
        }
    }
}
signed main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    int c=rd(),n=rd(),m=rd(),d=rd(),q=rd();
    for(int i=1;i<=m;i++) w[i]=rd();
    for(int i=1;i<=n;i++){
        int k=rd();
        for(int j=1;j<=k;j++){
            int a=rd(),t=rd();
            sw[a].push_back({i,t});
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(i!=j) ins[i][j]=1e18+1;
        }
    }
    for(int i=1;i<=m;i++){
        for(int j=0;j<sw[i].size();j++){
            for(int k=0;k<sw[i].size();k++){
                if(j==k) continue;
                pii jj=sw[i][j],kk=sw[i][k];
                ins[jj.fi][kk.fi]=min(ins[jj.fi][kk.fi],jj.se+kk.se);
            }
        }
    }
    floyd(n);
    while(q--){
        int x=rd(),y=rd(),res=1e18+1;
        for(int i=0;i<sw[x].size();i++){
            for(int j=0;j<sw[y].size();j++){
                    pii ii=sw[x][i],jj=sw[y][j];
                res=min(res,w[x]+w[y]+ii.se+jj.se+f[ii.fi][jj.fi]);
            }
        }
        cout<<res<<'\n';
    }
    return 0;
}
