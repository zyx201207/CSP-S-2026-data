#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll c,t,n,k,uu,vv;

struct node{
    int u,fa;
    vector<int>v;
}tr[200010];
ll dp[200010][19];
int dep[200010],maxd;
ll lg;
int dfs(int now,int fa,int deep){
    int maxdd=0;
    dp[now][0]=fa;
    maxd=max(maxd,deep);
    dep[now]=deep;
    tr[now].fa=fa;
    for(int v:tr[now].v){
        if(v!=fa){
            dfs(v,now,deep+1);
        }
    }
    return maxdd;
}
ll lca(int u,int v){
    if(dep[u]>dep[v]){
        swap(u,v);
    }
    for(int i=lg;i>=0;i--){
        if(dep[dp[v][i]]<=dep[u]){
            v=dp[v][i];
        }
        if(dep[v]==dep[u])break;
    }
    if(u==v)return u;
    for(int i=lg;i>=0;i--){
        if(dp[u][i]!=dp[v][i]){
            u=dp[u][i];
            v=dp[v][i];
        }
    }
    return dp[u][0];
}
ll dis(int u,int v){
    return dep[u]+dep[v]-2*dep[lca(u,v)];
}

int bfs(int now1,int now2){
    queue<int>q;
    q.push(now1);
    q.push(now2);
    vector<int>s;
    int kk=k;
    while(kk>0){
        int now=q.front();
        kk--;
        q.push(tr[now].fa);
        for(int v:tr[now].v){
            q.push(v);
        }
        s.push_back(now);
    }
    ll maxdi=0;
    for(int i=1;i<=n;i++){
        ll mindi=0x3f;
        for(int ss:s){
            mindi=min(mindi,dis(ss,i));
        }
        maxdi=max(maxdi,mindi);
    }
    return maxdi;
}
int main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    cin>>c>>t;
    while(t--){
        maxd=0;
        cin>>n>>k;
        for(int i=1;i<n;i++){
            cin>>uu>>vv;
            tr[uu].v.push_back(vv);
            tr[uu].u=uu;
            tr[vv].v.push_back(uu);
            tr[vv].u=vv;
        }
        dfs(1,1,1);
        lg=__lg(maxd);
        for(int j=1;j<=lg;j++){
            for(int i=2;i<=n;i++){
                dp[i][0]=dp[dp[i][j-1]][j-1];
            }
        }
        int ans=0x3f;
        for(int i=1;i<=n;i++){
            for(int j=1;j<i;j++){
                ans=min(ans,bfs(i,j));
            }
        }
        cout<<ans;
    }
    return 0;
}

/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2
*/
