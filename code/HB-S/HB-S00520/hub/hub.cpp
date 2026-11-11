#include<bits/stdc++.h>

using namespace std;
const int N=1e6+5;
int n,k;
vector<int> e[N];
bool book[N],tmp[N];
int dis[N];

void dfs(int u,int step) {
    if(dis[u]<=step) return ;
    dis[u]=step;
    for(int v:e[u]) dfs(v,step+1);
    return ;
}

void c2(int u) {
    if(!tmp[u]) return ;
    tmp[u]=false;
    for(int v:e[u]) c2(v);
    return ;
}

int check_sub1(int state) {
    for(int i=1;i<=n;i++) {
        dis[i]=n;
        book[i]=tmp[i]=false;
        if((state>>(i-1))&1) {
            book[i]=tmp[i]=true;
            dis[i]=0;
        }
    }
    int cnt=0;
    for(int i=1;i<=n;i++) {
        if(tmp[i]) {
            c2(i);
            cnt++;
        }
        if(cnt>2) return n+1;
    }
    for(int i=1;i<=n;i++) {
        if(book[i]) {
            for(int v:e[i]) {
                dfs(v,1);
            }
        }
    }
    int maxn=0;
    for(int i=1;i<=n;i++) maxn=max(maxn,dis[i]);
    return maxn;
}

void sub1() {
    cin>>n>>k;
    for(int i=1;i<n;i++) {
        int u,v;
        cin>>u>>v;
        e[u].push_back(v);
        e[v].push_back(u);
    }
    int ans=n;
    for(int state=(1<<k)-1;state<(1<<n);state++) if(__builtin_popcount(state)==k) {
        int t=check_sub1(state);
        ans=min(ans,check_sub1(state));
    }
    cout<<ans;
    return ;
}

signed main() {
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int c,T;
    cin>>c>>T;
    while(T--) {
        sub1();
        for(int i=1;i<=n;i++) e[i].clear();
        cout<<'\n';
    }
    return 0;
}
/*
0 1
10 3
1 2
1 3
2 4
2 5
3 6
3 7
3 8
7 9
9 10

2
*/