#include <bits/stdc++.h>
#define ll long long
#define pb push_back
using namespace std;

int C,N,M,D,Q;
int w[500005],k[505];
vector<int>a[505],t[505],p[500005],pt[500005];
ll g[505][505];

int read(){
    int x=0;
    char c=getchar();
    while(!isdigit(c)){
        c=getchar();
    }
    while(isdigit(c)){
        x=(x<<1)+(x<<3)+c-'0';
        c=getchar();
    }
    return x;
}

int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    C=read();
    N=read();
    M=read();
    D=read();
    Q=read();
    for(int i=1;i<=M;i++){
        w[i]=read();
    }
    int x,xt;
    for(int i=1;i<=N;i++){
        k[i]=read();
        a[i].pb(0);
        t[i].pb(0);
        for(int j=1;j<=k[i];j++){
            x=read();
            xt=read();
            a[i].pb(x);
            p[x].pb(i);
            t[i].pb(xt);
            pt[x].pb(xt);
        }
    }
    /*
    for(int i=1;i<=N;i++){
        for(int j=1;j<=k[i];j++){
            cout<<a[i][j]<<" ";
        }
        cout<<"\n";
    }
    */
    for(int i=1;i<=N;i++){
        for(int j=1;j<=N;j++){
            if(i==j){
                g[i][i]=0;
                continue;
            }
            g[i][j]=1e18;
        }
    }
    for(int i=1;i<=M;i++){
        for(int j=0;j<p[i].size();j++){
            for(int l=j+1;l<p[i].size();l++){
                g[p[i][j]][p[i][l]]=min(g[p[i][j]][p[i][l]],(ll)pt[i][j]+pt[i][l]);
                g[p[i][l]][p[i][j]]=g[p[i][j]][p[i][l]];
                //cout<<i<<" "<<j<<" "<<l<<" "<<p[i][j]<<" "<<p[i][l];
            }
        }
    }
    for(int l=1;l<=N;l++){
        for(int i=1;i<=N;i++){
            if(i==l){
                continue;
            }
            for(int j=i+1;j<=N;j++){
                if(j==l){
                    continue;
                }
                g[i][j]=min(g[i][j],g[i][l]+g[j][l]);
                g[j][i]=g[i][j];
            }
        }
    }
    /*
    for(int i=1;i<=N;i++){
        for(int j=1;j<=N;j++){
            cout<<g[i][j]<<" ";
        }
        cout<<"\n";
    }
    */
    int y;
    ll ans;
    while(Q--){
        ans=1e18;
        x=read();
        y=read();
        for(int i=0;i<p[x].size();i++){
            for(int j=0;j<p[y].size();j++){
                ans=min(ans,g[p[x][i]][p[y][j]]+pt[x][i]+pt[y][j]);
            }
        }
        cout<<ans+w[x]+w[y]<<"\n";
    }
    return 0;
}
