#include<bits/stdc++.h>
#define int long long 
using namespace std;
constexpr int X=2e6+5;

int N,D,a[X],l[X],r[X],d[X],siz1[X],siz2[X];
int res1[X],res2[X],res;
bool vis[X];
vector<int> pre1[X],pre2[X];
vector<int> root;

vector<int> G[X];
int dis[5005][5005],f[5005][5005];

inline void DFS1(int u)
{
    siz1[u]=1; vis[u]=1;
    for(int v:pre1[u]) if(!vis[v]) DFS1(v), siz1[u]+=siz2[v];
    if(d[u]) siz2[u]=1;
    else siz2[u]=siz1[u];
}
inline void DFS2(int u)
{
    siz1[u]=1; vis[u]=1;
    for(int v:pre2[u]) if(!vis[v]) DFS2(v), siz1[u]+=siz2[v];
    if(d[u]) siz2[u]=1;
    else siz2[u]=siz1[u];
}

void SUB()
{

    for(int i=1;i<=N;i++){
        r[i]=upper_bound(a+1,a+N+1,a[i]+D)-a-1;
    }

    for(int i=1;i<=N;i++){
        for(int j=i+1;j<=r[i];j++){
            G[i].push_back(j);
        }
    }

    // for(int i=1;i<=N;i++){
    //     for(int j:G[i]) cerr<<j<<" ";
    //     cerr<<endl;
    // }


    for(int i=1;i<=N;i++){
        for(int j=1;j<=N;j++){
            dis[i][j]=0x3f3f3f3f3f3f3f3f;
            f[i][j]=0;
        }
    }

    for(int S=1;S<=N;S++){
        dis[S][S]=0; f[S][S]=1;
        for(int j=1;j<=N;j++){
            for(int v:G[j]){
                // cerr<<S<<' '<<j<<" "<<v<<endl;
                if(dis[S][v]>dis[S][j]+1) dis[S][v]=dis[S][j]+1, f[S][v]=f[S][j];
                else if(dis[S][v]==dis[S][j]+1) f[S][v]+=f[S][j];
                // cerr<<dis[S][v]<<endl;
            }
        }
    }

    for(int u=1;u<=N;u++){
        for(int v=1;v<=N;v++){
            // cerr<<u<<' '<<v<<' ';
            // cerr<<dis[u][v]<<' '<<f[u][v]<<endl;
            if(f[u][v]==2) res++;
        }
    }


    for(int i=1;i<=N;i++){
        l[i]=lower_bound(a+1,a+N+1,a[i]-D)-a;
    }




    cout<<res<<'\n';

}

void solve()
{
    for(int i=1;i<=N;i++) siz1[i]=siz2[i]=vis[i]=0;
    for(int i=1;i<=N;i++) l[i]=r[i]=0;
    for(int i=1;i<=N;i++) res1[i]=res2[i]=0; res=0;
    for(int i=1;i<=N;i++) d[i]=0;
    for(int i=1;i<=N;i++) pre1[i].clear(), pre2[i].clear();
    root.clear();
    for(int i=1;i<=N;i++) G[i].clear();

    cin>>N>>D;
    for(int i=1;i<=N;i++) cin>>a[i];

    if(N<=500) return SUB();


    for(int i=1;i<=N;i++){
        r[i]=upper_bound(a+1,a+N+1,a[i]+D)-a-1;
    }

    // for(int i=1;i<=N;i++) cerr<<r[i]<<' '; cerr<<endl;

    for(int i=2;i<N;i++){
        if(r[i-1]>i) d[i]=1;
        else d[i]=0;
    }



    for(int i=1;i<=N;i++){
        if(r[i]==i) root.push_back(i);
        else pre1[r[i]].push_back(i);
    }


    for(int u:root){
        DFS1(u);
    }


    root.clear();

    for(int i=1;i<=N;i++){
        if(r[i]-i<=1) continue;
        res1[r[i]-1]+=siz2[i];
    }

    for(int i=1;i<=N;i++) siz1[i]=siz2[i]=vis[i]=0;

    for(int i=1;i<=N;i++){
        l[i]=lower_bound(a+1,a+N+1,a[i]-D)-a;
    }

    // for(int i=1;i<=N;i++) cerr<<l[i]<<' '; cerr<<endl;

    for(int i=2;i<N;i++){
        if(l[i+1]<i) d[i]=1;
        else d[i]=0;
    }

    for(int i=1;i<=N;i++){
        if(l[i]==i) root.push_back(i);
        else pre2[l[i]].push_back(i);
    }

    for(int u:root){
        DFS2(u);
    }

    for(int i=1;i<=N;i++){
        if(i-l[i]<=1) continue;
        res2[l[i]]+=siz2[i];
    }


    for(int i=1;i<=N;i++) res+=res1[i]*res2[i];

    cout<<res<<'\n';

}

signed main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);

    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int c,t; cin>>c>>t;
    while(t--) solve();
}