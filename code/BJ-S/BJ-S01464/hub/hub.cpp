#include <bits/stdc++.h>
#define mem(a,b) memset(a,b,sizeof(a))

using namespace std;
typedef long long ll;
const int N=1e6+5;
int C,T;
int n, K;
vector<int> tr[N];
int du[N];
int dis[N];
bool vis[N];
int dfn[N], tot, rfn[N];
bool ff[N];

void dfs(int u,int fa){
    dfn[u]=++tot;
    rfn[tot]=u;
    if (du[u]==2) ff[dfn[u]]=1;
    for (int v: tr[u]){
        if (v==fa||vis[v]) continue;
        dfs(v,u);
    }
}

bool check(int mid){
    // cout<<"At mid="<<mid<<":\n";
    mem(dis,0);
    mem(vis,0);
    mem(dfn,0); tot=0;
    mem(rfn,0);
    mem(ff,0);
    queue<int> q;
    for (int i=1; i<=n; i++){
        du[i]=tr[i].size();
        if (du[i]==1){
            q.push(i);
        }
    }
    while (q.size()){
        int u=q.front();
        q.pop();
        if (dis[u]+1>mid)
            continue;
        // cout<<"cut"<<u<<" dis="<<dis[u]<<" \n";
        vis[u]=1;
        for (int v: tr[u]){
            if (vis[v]) continue;
            du[v]--;
            dis[v]=max(dis[v],dis[u]+1);
            if (du[v]==1){
                q.push(v);
            }
        }
    }
    int cnt=0,rt=0;
    for (int i=1; i<=n; i++){
        if (!vis[i]){
            // cout<<i<<" ";
            cnt++;
        }
        if (rt==0&&!vis[i]&&du[i]==1) rt=i;
    }
    // cout<<"cnt="<<cnt<<"\n";
    if (cnt<=K) return 1;

    dfs(rt, 0);
    // for (int i=1; i<=n; i++){
    //     cout<<dis[i]<<" "<<du[i]<<" "<<vis[i]<<" "<<dfn[i]<<" "<<ff[dfn[i]]<<"\n";
    // }cout<<'\n';

    int mx=0;
    for (int i=1; i<=tot; i++){
        if (ff[i]){
            // cout<<"cometo "<<i<<": \n";
            if (dis[rfn[i]]+1>mid) continue;
            int h=-1,j=i+1;
            for (j=i+1; j<=tot; j++){
                if (!ff[j]) break;
                if (h!=-1&&h+1>mid) break;
                if (h!=-1) h++;
                if (dis[rfn[j]]+j-i+1>mid){
                    if (dis[rfn[j]]+1>mid){
                        break;
                    }
                    h=max(h,dis[rfn[j]]+1);
                }
            }
            mx=max(mx,j-i);
            // cout<<"an ans: ["<<i<<", "<<j<<"): ";
            // cout<<rfn[i]<<" -> "<<rfn[j]<<"\n";
        }
    }
    if (cnt-mx<=K) return 1;
    return 0;
}

int main()
{
    freopen("hub.in", "r", stdin);
    freopen("hub.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin>>C>>T;
    while (T--){
        cin>>n>>K;
        for (int i=1; i<N; i++){
            tr[i].clear();
        }
        for (int i=1; i<n; i++){
            int u,v;
            cin>>u>>v;
            tr[u].push_back(v);
            tr[v].push_back(u);
        }
        int l=0,r=n;
        while (l<r){
            int mid=(l+r)>>1;
            if (check(mid)){
                r=mid;
            }
            else{
                l=mid+1;
            }
        }
        cout<<l<<'\n';
    }
    return 0;
}