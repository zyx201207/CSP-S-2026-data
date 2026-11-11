#include<bits/stdc++.h>
#define int long long
using namespace std;
int c,T,n,kk,d[100010],f[100010][30],dep[100010],ans=1e18,sum,pp;
vector<int> e[100010],p[100010];
bitset<100000> bs;
void dfs(int x,int fa){
    d[x]=1;
    for(auto y:p[x]){
        if(y==fa) continue;
        dfs(y,x);
    }
    return;
}
void dfs1(int x,int fa){
    for(auto y:e[x]){
        if(y==fa) continue;
        f[y][0]=x;
        dep[y]=dep[x]+1;
        dfs1(y,x);
    }
    return;
}
int lca(int x,int y){
    if(dep[x]<dep[y]) swap(x,y);
    for(int i=pp;i>=0;i--){
        if(dep[f[x][i]]>=dep[y]) x=f[x][i];
    }
    if(x==y) return x;
    for(int i=pp;i>=0;i--){
        if(f[x][i]!=f[y][i]) x=f[x][i],y=f[y][i];
    }
    return f[x][0];
}
signed main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>c>>T;
    while(T--){
        ans=1e18;
        cin>>n>>kk;
        for(int i=1;i<n;i++){
            int x,y;
            cin>>x>>y;
            e[x].push_back(y);
            e[y].push_back(x);
        }
        pp=log2(n);
        f[1][0]=1;
        dfs1(1,1);
        for(int j=1;j<=pp;j++){
            for(int i=1;i<=n;i++){
                f[i][j]=f[f[i][j-1]][j-1];
            }
        }
        for(int k=0;k<(1<<n);k++){
            sum=0;
            bs.reset();
            for(int i=0;i<n;i++) {
                if(k&(1<<i)) bs[i+1]=1;
            }
            if(bs.count()!=kk) continue;
            for(int i=1;i<=n;i++){
                if(!bs[i]) continue;
                for(auto j:e[i]){
                    if(bs[j]) {
                        p[i].push_back(j);
                        p[j].push_back(i);
                    }
                }
            }
            for(int i=1;i<=n;i++){
                if(!bs[i] || d[i]) continue;
                sum++;
                dfs(i,i);
            }
            if(sum>2) continue;
            sum=0;
            for(int i=1;i<=n;i++){
                if(bs[i]) continue;
                int sum1=1e18;
                for(int j=1;j<=n;j++){
                    if(!bs[j]) continue;
                    int xx=lca(i,j);
                    sum1=min(sum1,dep[i]+dep[j]-2*dep[xx]);
                }
                sum=max(sum,sum1);
            }
            for(int i=1;i<=n;i++) {
                d[i]=0,p[i].clear();
            }
            ans=min(ans,sum);
        }
        for(int i=1;i<=n;i++){
            e[i].clear(),dep[i]=0;
            for(int j=1;j<=29;j++) f[i][j]=0;
        }
        cout<<ans<<'\n';
    }
    return 0;
}
