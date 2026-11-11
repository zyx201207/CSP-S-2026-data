#include <bits/stdc++.h>
#define int long long
#define pb push_back
using namespace std;
int c,t,n,k,bel[55],dep[55][55];
bool isok[55],vis[55],f[25][25];
vector <int> v[500005],E[500005];
void dfs10(int x,int fa,int nw) {
    bel[x]=nw; vis[x]=1;
    for (int vto : v[x]) {
        if (vis[vto]==0&&isok[vto]==1) {
            dfs10(vto,x,nw);
        }
    }
} void findzj(int x,int fa,int now) {
    dep[now][x]=dep[now][fa]+1; vis[x]=1;
    for (int vto : E[x]) {
        if (vto==fa) continue;
        if (vis[vto]) continue;
        findzj(vto,x,now);
    }
    return;
}
signed main() {
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    cin>>c>>t; while (t--) {
        cin>>n>>k; for (int i=1;i<=n-1;i++) {
            int xx,yy; cin>>xx>>yy;
            v[xx].pb(yy),v[yy].pb(xx);
        }
        if (n<=10) {
            int anss=1e9;
            for (int S=0;S<(1<<n);S++) { int sum=0;
                for (int i=1;i<=n*2;i++) isok[i]=0,vis[i]=0,E[i].clear(),bel[i]=i;
                for (int i=1;i<=20;i++) {
                    for (int j=1;j<=20;j++) f[i][j]=0;
                }
                for (int i=1;i<=n;i++) {
                    if (((1<<(i-1))&S)>0) {
                        isok[i]=1; sum++;
                    }
                } int cnt=n;
                for (int i=1;i<=n;i++) {
                    if (isok[i]==1&&vis[i]==0) {
                        dfs10(i,0,++cnt);
                    }
                }
                if (cnt>n+2||sum>k||sum==0) continue;
                for (int i=1;i<=n;i++) {
                    for (int vto : v[i]) {
                        if (f[bel[vto]][bel[i]]==0&&bel[i]!=bel[vto]) {
                            E[bel[vto]].pb(bel[i]),E[bel[i]].pb(bel[vto]);
                            f[bel[vto]][bel[i]]=1;
                        }
                    }
                }
                for (int i=n+1;i<=cnt;i++) {
                    for (int i=1;i<=cnt;i++) vis[i]=0;
                    findzj(i,0,i);
                } 
                int ansget=0;
                for (int i=1;i<=n;i++) {
                    if (bel[i]==i) {
                        int minn=1e9;
                        for (int j=n+1;j<=cnt;j++) {
                            minn=min(minn,dep[j][i]-1);
                        } ansget=max(ansget,minn);
                    } 
                }
                anss=min(anss,ansget);
            } 
            cout<<anss<<'\n'; 
        }
        else {
            int m=(n-1)/2+1;
            cout<<(m-k)/2+1<<'\n';
        }
    }
    return 0;
}