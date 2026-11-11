#include<bits/stdc++.h>
using namespace std;
int c,t;
const int MAXN=1000005;
int tot;
int head[MAXN],to[MAXN],nxt[MAXN];
int f[MAXN];
void add_edge(int u,int v){
    tot++;
    to[tot]=v;
    nxt[tot]=head[u];
    head[u]=tot;
    return;
}
int deep[MAXN];
void dfs(int u,int fa){
    deep[u]=deep[fa]+1;
    f[u]=fa;
    for (int i=head[u];i!=0;i=nxt[i]){
        int v=to[i];
        if (v==fa){
            continue;
        }
        dfs(v,u);
    }
    return;
}
struct node{
    int dis,v;
};
node dis[MAXN];
bool cmp(node &a,node &b){
    return a.dis<b.dis;
}
void solve(){
    for (int i=1;i<MAXN;i++){
        head[i]=0;
        deep[i]=0;
        f[i]=0;
    }
    tot=0;
    int n,k;
    cin>>n>>k;
    for (int i=1;i<n;i++){
        int u,v;
        cin>>u>>v;
        add_edge(u,v);
        add_edge(v,u);
    }
    dfs(1,0);
    int maxm=0;
    int x;
    for (int i=1;i<=n;i++){
        if (deep[i]>maxm){
            maxm=deep[i];
            x=i;
        }
        deep[i]=0;
    }
    dfs(x,0);
    maxm=0;
    int y;
    for (int i=1;i<=n;i++){
        if (deep[i]>maxm){
            maxm=deep[i];
            y=i;
        }
    }
    if (k==2){
        int len=deep[y];
        len-=2;
        if (len%3==0){
            cout<<len/3<<"\n";
        }
        else{
            cout<<len/3+1<<"\n";
        }
        return;
    }
    cout<<"-1"<<"\n";
    return;
}
int main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    cin>>c>>t;
    for (int z=1;z<=t;z++){
        solve();
    }
return 0;
}
