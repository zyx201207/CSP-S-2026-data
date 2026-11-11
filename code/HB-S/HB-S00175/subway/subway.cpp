#include<bits/stdc++.h>
#define ll long long
#define db double
#define ios ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
using namespace std;
const int N=5e2+5;
const int M=5e5+5;
const int mod=1e9+7;
const int inf=0x3f3f3f3f;
int C;
int n,m,d,Q;
vector<int> a[N];
int t[N][M];
vector<int> sta[M];
int w[M],k[N];

int rd() {
    int num=0,k=1,c=getchar();
    while(!isdigit(c)) {
        if(c=='-') k=-1;
        c=getchar();
    }
    while(isdigit(c)) {
        num=num*10+c-48;
        c=getchar();
    }
    return num*k;
}
struct edge{
    int v,val;
    bool operator < (const edge& other) const {
        return val>other.val;
    }
};
priority_queue<edge> q;
bool vis[M];
int dij(int st,int ed) {
    fill(vis,vis+m+1,0);
    while(!q.empty()) q.pop();
    q.push({st,0});
    while(!q.empty()) {
        int u=q.top().v,dis=q.top().val; q.pop();
        if(u==ed) {
            return dis; 
        }
        if(vis[u]) continue;
        vis[u]=1;
        for(int i:sta[u]) {
            for(int v:a[i]) {
                if(u==v) continue;
                q.push({v,dis+t[i][u]+t[i][v]});
            }
        }
    }
    return -1;
}
void solve() {
    int u=rd(),v=rd();
    int ans=w[u]+dij(u,v)+w[v];
    printf("%d\n",ans);
}
int main() {
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    C=rd(),n=rd(),m=rd(),d=rd(),Q=rd();
    for(int i=1;i<=m;i++) {
        w[i]=rd();
    }
    for(int i=1;i<=n;i++) {
        k[i]=rd();
        a[i].push_back(0);
        for(int j=1;j<=2*k[i];j++) {
            if(j&1) {
                int x=rd();
                a[i].push_back(x);
                sta[x].push_back(i);
            }
            else t[i][a[i].back()]=rd();
        }
    }
    while(Q--) {
        solve();
    }
    return 0;
}
/*
information:
    n<=500, m<=5e5, d<=20, q<=1e5;
*/