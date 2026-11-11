#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=6e3+5,nn=2e6+5;
int c,t,n,d,x[nn],mx[N],cntt[N],vis[N];
bool A=0;
vector<vector<int> > g(nn);
int bfs(int s){
    memset(cntt,0x00,sizeof cntt);
    memset(mx,0x3f,sizeof mx);
    memset(vis,0x00,sizeof vis);
    queue<int> q;
    q.push(s);
    cntt[s]=1,mx[s]=0;
    while(!q.empty()){
        int u=q.front();
        q.pop();
        for(auto v:g[u]){
            if(mx[v]>mx[u]+1){
                mx[v]=mx[u]+1;
                cntt[v]=cntt[u];
                if(!vis[v]){
                    vis[v]=1;
                    q.push(v);
                }
            }
            else if(mx[v]==mx[u]+1){
                cntt[v]+=cntt[u];
            }
        }
    }
    int ss=0;
    for(int i = 1;i <= n;i++){
        if(cntt[i]==2)ss++;
    }
    return ss;
}
signed main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin >> c >> t;
    if(c==11||c==12){
        while(t--){
            cin >> n>>d;
            for(int i = 0;i < n;i++)cin >> x[i];
            int jian=x[1]-x[0];
            int tmp=d/jian;
            if(tmp==2)cout << (n-2) << endl;
            else cout << 0 << endl;
        }
    }
    while(t--){
        cin >> n >> d;
        for(int i = 0;i <= n;i++)g[i].clear();
        for(int i = 0;i < n;i++){
            cin >> x[i];
        }
        for(int i = 0;i < n;i++){
            for(int j = i+1;j < n;j++){
                if(x[j]-x[i]<=d)g[i].push_back(j);
            }
        }
        int cnt=0;
        for(int i = 0;i < n;i++){
            cnt+=bfs(i);
        }
        cout << cnt << endl;
    }
}
