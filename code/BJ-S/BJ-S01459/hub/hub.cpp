#include<bits/stdc++.h>
using namespace std;

struct node{
    int u,fa,st;
};
int n,k;
vector<int> ed[200];
int zu[200];
int p[200];

int fd(int x){
    if(p[x]==x)
        return x;
    return p[x] = fd(p[x]);
}

bool ok(){
    for(int i=0;i<=n;i++)
        p[i] = i;
    for(int u=1;u<=n;u++){
        if(!zu[u]) continue;
        for(int i=0;i<ed[u].size();i++){
            int v=ed[u][i];
            if(!zu[v]) continue;
            p[fd(u)] = fd(v);
        }
    }
    int cnt=0;
    for(int i=1;i<=n;i++){
        if(p[i]==i&&zu[i]){
            cnt++;
        }
    }
    return cnt<=2;
}


int lth(int s){
    queue<node> q;
    q.push({s,0,0});
    while(!q.empty()){
        int u=q.front().u, fa=q.front().fa, st=q.front().st;
        q.pop();
        if(zu[u])
            return st;
        for(int i=0;i<ed[u].size();i++){
            int v=ed[u][i];
            if(v==fa) continue;
            q.push({v,u,st+1});
        }
    }
    return 142857;
}

int rr(){
    int ans=0;
    for(int u=1;u<=n;u++){
        ans = max(ans,lth(u));
    }
    return ans;
}
void sv1(){
    memset(zu,0,sizeof(zu));
    for(int i=n-k+1;i<=n;i++)
        zu[i] = 1;
    int ans=n;
    do{
        if(ok()){
            ans=min(ans,rr());
        }
    }while(next_permutation(zu+1,zu+n+1));
    cout<<ans<<endl;
    return;
}

signed main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    int C,T;
    cin>>C>>T;
    while(T--){
        cin>>n>>k;
        for(int i=1;i<=n;i++)
            ed[i].clear();
        for(int i=1;i<n;i++){
            int u,v;
            cin>>u>>v;
            ed[u].push_back(v);
            ed[v].push_back(u);
        }
        sv1();
    }
    return 0;
}
