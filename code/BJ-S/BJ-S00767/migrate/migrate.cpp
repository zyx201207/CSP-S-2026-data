#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pii pair<int,int>
#define dle long double
#define fi first
#define sec second
#define rep(i,a,b) for(int i = (a);i<=(b);i++)
#define per(i,a,b) for(int i = (a);i>=(b);i--)
#define endl '\n'
const int MAXN = 5e3+10,MAXM = 2e6+10;vector<int> g[MAXN];
int c,t,n,x,a[MAXN],d[MAXN],fl[MAXN][MAXN],d2[MAXM],p,ans,flg[MAXM];
void bfs(int x) {
    memset(d,-1,sizeof(d));
    queue<int> q;d[x] = 0;
    q.push(x);while(q.size()) {
        int u = q.front();q.pop();
        for(int v:g[u]) { if(d[v]==d[u]+1) {
                if(fl[x][v]==0) fl[x][v] = 1;
                else if(fl[x][v]==1) fl[x][v] = -1;
            }if(d[v]==-1) d[v] = d[u]+1,
                q.push(v),fl[x][v] = fl[x][u];
        }
    }
}
void bfs2(int s) {
    queue<int> q;q.push(s);
    vector<int> V(1,s);
    d2[s] = 0;while(q.size()) {
        int u = q.front();q.pop();
        if(d2[u]==2) break;rep(v,u+1,n) { 
            if(v==p) continue;if(abs(a[v]-a[u])
                >x) break;if(d2[v]==-1) 
                d2[v] = d2[u]+1,V.push_back(v),
                q.push(v),flg[v] = flg[u];
            else if(d2[v]==d2[u]+1) {
                if(flg[v]==0) flg[v] = 1;
                else if(flg[v]==1) flg[v] = -1;
            }
        }
    }for(int x:V) { if(flg[x]==1) 
        ans++;d2[x] = -1,flg[x] = 0;
    }
}
signed main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>t;while(t--) {
        cin>>n>>x;rep(i,1,n)
            cin>>a[i],g[i].clear();
        if(c==13||c==14) {
            memset(d2,-1,sizeof(d2));
            rep(i,1,n) if(a[i]-a[1]<=x
                &&a[n]-a[i]<=x) p = i;
            ans = 0;rep(i,1,n) bfs2(i);
            cout<<ans<<endl;continue;
        }rep(i,1,n) rep(j,1,n) fl[i][j] = 0;
        rep(i,1,n) rep(j,i+1,n) {
            if(a[j]-a[i]>x) break;
            g[i].push_back(j);
            g[j].push_back(i);
        }rep(i,1,n) bfs(i);int ans = 0;
        rep(i,1,n) rep(j,i+1,n)
            ans += fl[i][j]==1;
        cout<<ans<<endl;
    }
    return 0;
}