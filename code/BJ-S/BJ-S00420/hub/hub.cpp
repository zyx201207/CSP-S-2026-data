#include <bits/stdc++.h>
using namespace std;

int n, d;

vector <int> to[2000006];
int dep[2000006], hs[2000006], val[2000006];
bool dev[2000006];
int rt1, rt0, limit;

void dfs(int now,int f){
    dep[now] = 0;
    hs[now] = 0;
    val[now] = 0;
    for(int nxt:to[now]){
        if(nxt==f||dev[nxt])continue;
        dfs(nxt,now);
        dep[now] = max(dep[now],dep[nxt]+1);
        val[now] += val[nxt];
        if(val[nxt] > val[hs[now]]){
            hs[now] = nxt;
        }
    }
    val[now] += (dep[now] >= limit);
}

void dfs1(int now,int f){
    dep[now] = 0;
    hs[now] = 0;
    val[now] = 0;
    for(int nxt:to[now]){
        if(nxt==f||!dev[nxt])continue;
        dfs1(nxt,now);
        dep[now] = max(dep[now],dep[nxt]+1);
        val[now] += val[nxt];
        if(val[nxt] > val[hs[now]]){
            hs[now] = nxt;
        }
    }
    val[now] += (dep[now] >= limit);
}

void dfs_cover(int now,int f){
    dev[now] = 1;
    dep[now] = 0;
    hs[now] = 0;
    val[now] = 0;
    for(int nxt:to[now]){
        if(nxt==f||dev[nxt])continue;
        dfs_cover(nxt,now);
        dep[now] = max(dep[now],dep[nxt]+1);
        val[now] += val[nxt];
        if(val[nxt] > val[hs[now]]){
            hs[now] = nxt;
        }
    }
    val[now] += (dep[now] >= limit);
}

bool check(){
    memset(dev,0,sizeof dev);
    dep[0] = -111;
    dfs(1,0);
    int now = 1, f = 0;
    int outdep = 0, outval = 0;
    rt0 = 1;
    while(1){
        if(outval >= val[now]-1||hs[now]==0){
            rt1 = now;
            dfs_cover(now,f);
            break;
        }
        for(int nxt:to[now]){
            if(nxt!=f&&nxt!=hs[now]){
                outdep = max(outdep,dep[nxt]+1);
                outval += val[nxt];
            }
        }
        outval+=(outdep >= limit);
        outdep++;
        f = now;
        now = hs[now];
    }
    dfs(1,0);
    f = 0;
    outdep = 0;
    outval = 0;
    while(1){
        if(outval >= val[rt0]-1||hs[rt0]==0){
            break;
        }
        for(int nxt:to[rt0]){
            if(nxt!=f&&!dev[nxt]&&nxt!=hs[rt0]){
                outdep = max(outdep,dep[nxt]+1);
                outval += val[nxt];
            }
        }
        outval+=(outdep >= limit);
        outdep++;
        f = rt0;
        rt0 = hs[rt0];
    }       
    f = 0;
    outdep = 0;
    outval = 0;
    while(1){
        if(outval >= val[rt1]-1||hs[rt1]==0){
            break;
        }
        for(int nxt:to[rt1]){
            if(nxt!=f&&dev[nxt]&&nxt!=hs[rt1]){
                outdep = max(outdep,dep[nxt]+1);
                outval += val[nxt];
            }
        }
        outval+=(outdep >= limit);
        outdep++;
        f = rt1;
        rt1 = hs[rt1];
    }        
    dfs(rt0,0);
    dfs1(rt1,0);
    int cost0 = val[rt0];
    int cost1 = val[rt1];
    return cost0+cost1 <= d;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    int c, T;
    cin >> c >> T;
    while(T--){
        cin >> n >> d;
        for(int i = 1;i <= n;i++){
            to[i].clear();
        }
        for(int i = 1;i <= n-1;i++){
            int u, v;
            cin >> u >> v;
            to[u].push_back(v);
            to[v].push_back(u);
        }
        int l = 0, r = n;
        while(l != r){
            int mid = (l+r)/2;
            limit = mid;
            if(check()){
                r = mid;
            }
            else l = mid+1;
        }
        cout << l << "\n";
    }
    return 0;
}