#include<bits/stdc++.h>
#define add(a,b,c) e[++idx]=b, ne[idx]=h[a], h[a]=idx
#define int long long
using namespace std;

int c,t,n,d,x[500005],f[305][305],g[305][305],e[1<<20],ne[1<<20],h[1<<20];

void solve1(){
    int ans=0;
    memset(f,0x3f,sizeof f);
    memset(g,0,sizeof g);
    for(int i=1;i<=n;i++)
        for(int j=i+1;j<=n;j++)
            if(x[j]-x[i]<=d) f[i][j]=g[i][j]=1;
            else break;
    for(int i=1;i<n;i++)
        for(int j=i+1;j<=n;j++){
            if(f[i][j]==1) continue;
            for(int k=i+1;k<j;k++){
                // cout << i << ' ' << j << ' ' << k << endl;
                if(f[i][k]>1e18||f[k][j]>1e18) continue;
                int cost=f[i][k]+f[k][j];
                if(cost<f[i][j]) f[i][j]=cost, g[i][j]=g[i][k]*g[k][j];
                else if(cost==f[i][j]) g[i][j]+=g[i][k]*g[k][j];
            }
        }
    for(int i=1;i<=n;i++)
        for(int j=2;j<=n;j++) ans+=g[i][j]==2;
    cout << ans << endl;
}

void solve2(){
    ;
}

signed main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> c >> t;
    while(t--){
        cin >> n >> d;
        for(int i=1;i<=n;i++) cin >> x[i];
        if(n<=300) solve1();
        else if(n<=5000) solve1();
        else solve1();
    }
    return 0;
}
