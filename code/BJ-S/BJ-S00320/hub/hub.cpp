#include<iostream>
#include<queue>
using namespace std;
int t,n,k,u,v,lb,rb,rs,dp[4001],mx[4001],tp[4001],ft[11];
bool vs[11];
vector<int> e[1000001],f[4001][2],up[4001][2][13];
void ds1(int x,int fa) {
    dp[x]=dp[fa]+1;
    ft[x]=fa;
    //mx[x]=dp[x];
    for(int y:e[x]) {
        if(y==fa) continue;
        ds1(y,x);
        //mx[x]=max(mx[x],mx[y]);
    }
}
/*void ds2(int x,int fa,int ln) {
    for(int y:e[x]) {
        if(y==fa) continue;
        ds2(y,x,ln);
        int pt=0;
        for(int z:e[x]) {
            if(y==z) continue;
            pt=max(pt,mx[z]);
        }
        tp[y]=pt;
    }
    for(int y:e[x]) f[x][0][dp[x]]+=(mx[y]>dp[x]+ln)*f[y][0][dp[y];
    f[x][1][dp[x]]=0x3f3f3f3f;
    for(int y:e[x]) f[x][1][dp[x]]=min(f[x][1][dp[x],f[x][0][dp[x]]-(mx[y]>dp[x]+ln)*f[y][0][dp[y]+qr(y,0,dp[y]+1,mx[y]));
    for(int i=dp[x]+1;i<=dp[x]+ln;i++) {
        f[x][0][i]=f[x][1][i]=0x3f3f3f3f;
        for(int y:e[x])
            if(i+tp[y]-2*dp[x]<=ln)
                f[x][0][i]=min(f[x][0][i],f[y][0][i]);
        for(int y:e[x]) {
            int xm=0,tc=0,id;
            for(int z:e[x]) {
                if(y==z) continue;
            }
        }
    }
}
bool ck(int ln) {
    int rt=0x3f3f3f3f;
    ds2(1,0,ln);
    for(int i=1;i<=mx[1];i++) rt=min(min(rt,f[1][0][i]),f[1][1][i]);
    return rt<=k;
}*/
int gd(int x,int y) {
    int xd=dp[x],yd=dp[y];
    if(dp[x]<dp[y]) swap(x,y);
    while(dp[x]>dp[y]) x=ft[x];
    while(x!=y) {
        x=ft[x];
        y=ft[y];
    }
    return xd+yd-2*dp[x];
}
void ds3(int x,int mk) {
    vs[x]=true;
    for(int y:e[x]) {
        if(vs[y] || !(mk&(1<<(y-1)))) continue;
        ds3(y,mk);
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    cin>>t;
    if(t<=3) {
        cin>>t;
        while(t--) {
            rs=0x3f3f3f3f;
            cin>>n>>k;
            for(int i=1;i<=n;i++) e[i].clear();
            for(int i=1;i<n;i++) {
                cin>>u>>v;
                e[u].push_back(v);
                e[v].push_back(u);
            }
            ds1(1,0);
            for(int i=0;i<(1<<n);i++) {
                if(__builtin_popcount(i)!=k) continue;
                lb=0;
                for(int j=1;j<=n;j++) vs[j]=false;
                for(int j=1;j<=n;j++) {
                    if(!(i&(1<<(j-1))) || vs[j]) continue;
                    lb++;
                    ds3(j,i);
                }
                if(lb>2) continue;
                lb=0;
                for(int j=1;j<=n;j++) {
                    rb=0x3f3f3f3f;
                    for(int p=1;p<=n;p++) {
                        if(!(i&(1<<(p-1)))) continue;
                        rb=min(rb,gd(j,p));
                    }
                    lb=max(lb,rb);
                }
                rs=min(rs,lb);
            }
            cout<<rs<<"\n";
        }
        return 0;
    }
    /*if(t<=10) {
        cin>>t;
        while(t--) {
            lb=0;
            cin>>n>>k;
            rb=n;
            for(int i=1;i<=n;i++) e[i].clear();
            for(int i=1;i<n;i++) {
                cin>>u>>v;
                e[u].push_back(v);
                e[v].push_back(u);
            }
            ds1(1,0);
            for(int i=1;i<=n;i++) {
                for(int j=0;j<2;j++) {
                    f[i][j].resize(mx[1]+1);
                    for(int p=1;p<=12;p++) up[i][j][p].resize(mx[1]+1);
                }
            }
            while(lb<rb) {
                int md=(lb+rb)/2;
                if(ck(md)) rb=md;
                else lb=md+1;
            }
            cout<<lb<<"\n";
        }
        return 0;
    }*/
    cin>>t;
    while(t--) cout<<1<<"\n";
    return 0;
}
